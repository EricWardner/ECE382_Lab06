ECE382_Lab06
============

MSP430 Motor

####Pre-Lab

######Which pins will output which signals you need?
  TA0 subsystem. 
  - Right: speed: P2.5 direction : P2.4
  - Left: speed: P2.0 direction: P2.1
  - Why: Because they are on the right and left side fo the board and they seems like they would work. 
  - Signals
    -TACTL 
      -TA0CTL
      -TA1CTL

    -TACCR0
      -TA0CCR0
      -TA0CCR1
      -TA0CCR2
    -TA1CCR0
      -TA1CCR0
      -TA1CCR1
      -TA1CCR2

######Which side of the motor will you attach these signals to?
  PWM: Goes into the upper terminal of motor
  DC: THe bottom terminal of motor

######How will you use these signals to achieve forward / back / left / right movement?

  -Forward: Same PWM to both motors; Opposite DC (0 to left, 1 to right) to each motor (they face eachother, are inverse)
  
  -Back: Same PWM to both motors; Opposite DC, also opposite to forward (1 to left, 0 to right) to each motor
  
  -Left: Depending on how severe/sharp of a turn. want wheels to turn opposite directions. Same PWM. Same DC 1, 1
  
  -Right: similar to left with opposite DC signal. 0,0
  
  
######Additional Hardware
  -SN754410: Allows the MSP430 to controll the motors
  
  -Capacitors: Smooth out the signal and prevent errors becasue of signal variance. 
  
  -Motors: Motors to turn the wheels
  
  -Voltage regulator: keep voltage at 3.3v
  
  
######Code Ideas
  Want to move motors individually but it will be done within different functions. 
  
    robotMoveForward(speed)
      handles each motor individually. 
      
    robotMoveLeft(speed)
      handles each motor individually.
      
    robotMoveRight(speed)
      handles each motor individually.
      
    robotMoveBack(speed)
      handles each motor individually.
      
    
  
###Setup/Goals
The goal of the lab was to wire up the robot and program in a specified course for the robot to take. The course was forward, backward, right 45 degrees, left 45 degrees, right 90 degrees, and left 90 degrees. 

Ther initial set up was actually a bit difficult and took some thinking. It turns out my initial wire diagram was a bit wrong so I used the example gode given to wire it up in a new way. From the code I knew that it would spin both motors if wired correctly so I went about testing until both motors spun when the code was run! Here is the meat of the given code that I used to create my accurate wire diagram. 

```C
P1DIR &= ~BIT3;
    P1REN |= BIT3;

    P2DIR |= BIT2;							// P2.2 is associated with TA1CCR1
    P2SEL |= BIT2;							// P2.2 is associated with TA1CCTL1

    P2DIR |= BIT4;							// P2.4 is associated with TA1CCR2
    P2SEL |= BIT4;							// P2.4 is associated with TA1CCTL2

    TA1CTL = ID_3 | TASSEL_2 | MC_1;		// Use 1:8 presclar off MCLK
    TA1CCR0 = 0x0100;						// set signal period

    TA1CCR1 = 0x0020;
    TA1CCTL1 = OUTMOD_7;					// set TACCTL1 to Reset / Set mode

    TA1CCR2 = 0x0020;
    TA1CCTL2 = OUTMOD_3;					// set TACCTL1 to Reset / Set mode
```
From the code it is clear that P2.2 and P2.4 are being used for motor control. After some trial and error my wireing came out as follows.

<br><a href="url"><img src="http://i.imgur.com/jAkdrqz.png" align="center" height="262" width="724" ></a></br>
<br>
<br>

the final wiring implemented on the robot can be seen here


<a href="url"><img src="http://i.imgur.com/ah73whn.jpg" align="center" height="486" width="555" ></a>

###Functionality
The code part was based heavily off of the given code show above, I figured if it isn't broken, don't fix it.
My code broke down in the following way
######main.c
directed the movement of the robot, only had a main function

######robotMove.c
defined the functions that would move the robot 

<dl>
  <dt>init
    <dd>Sets all of the bits on P2 that will be used (in accordance with diagram)</dd>
    <dd>Sets the clock and the signal period for the PWM signal</dd>
</dl>

```C
void init(){
	WDTCTL = WDTPW|WDTHOLD;                 // stop the watchdog timer

	P2DIR |= BIT2;							// P2.2 is associated with TA1CCR1
	P2SEL |= BIT2;							// P2.2 is associated with TA1CCTL1
	P2DIR |= BIT4;							// P2.4 is associated with TA1CCR2
	P2SEL |= BIT4;							// P2.4 is associated with TA1CCTL2

	P2DIR |= BIT0;							// P2.0 is associated with LEFT_ENB
	P2OUT &= BIT0;							// P2.0 is associated with LEFT_ENB
	P2DIR |= BIT5;							// P2.5 is associated with RIGHT_ENB
	P2OUT &= BIT5;							// P2.5 is associated with RIGHT_ENB

	P2DIR |= BIT1;							// P2.0 is associated with LEFT_DIR
	P2OUT &= BIT1;							// P2.0 is associated with LEFT_DIR
	P2DIR |= BIT3;							// P2.5 is associated with RIGHT_DIR
	P2OUT &= BIT3;							// P2.5 is associated with RIGHT_DIR

	TA1CTL = ID_3 | TASSEL_2 | MC_1;		// Use 1:8 presclar off MCLK
	TA1CCR0 = 0x0100;						// set signal period
}
```

<dl>
  <dt>forward
    <dd>P2.1 and P2.3 set to high (DIR=forward)</dd>
    <dd>both ENBs are set to high to enable motor</dd>
    <dd>both PWM outmods set to 7 (fast)</dd>
    <dd>delay for specified time</dd>
</dl>

```C
void forward(int32 time){

    P2OUT |= BIT1|BIT3;						//set direction
    P2OUT |= BIT0|BIT5;						//enable motor

	TA1CTL = ID_3 | TASSEL_2 | MC_1;		// Use 1:8 presclar off MCLK
    TA1CCR0 = 0x0100;						// set signal period

    TA1CCTL1 = OUTMOD_7;					// set TACCTL1 to Reset / Set mode
    TA1CCTL2 = OUTMOD_7;					// set TACCTL1 to Reset / Set mode

    for(i=0;i<time;i++){
    	__delay_cycles(1);
    }
}
```
<dl>
  <dt>back
    <dd>P2.1 and P2.3 set to low (DIR=backwards)</dd>
    <dd>both ENBs are set to high to enable motor</dd>
    <dd>both PWM outmods set to 3 (fast for back) (fast)</dd>
    <dd>delay for specified time</dd>
</dl>

```C
void back(int32 time){

    P2OUT &= ~(BIT1|BIT3);
    P2OUT |= BIT0|BIT5;						//enable motor

    TA1CCTL1 = OUTMOD_3;					// set TACCTL1 to Reset / Set mode
    TA1CCTL2 = OUTMOD_3;					// set TACCTL1 to Reset / Set mode

    for(i=0;i<time;i++){
        __delay_cycles(1);
    }
}
```

<dl>
  <dt>right
    <dd>P2.1 set to high and P2.3 set to low (left motor goes forward right motor goes back)</dd>
    <dd>both ENBs are set to high to enable motor</dd>
    <dd>both outmod for CTL1 set to 7 (fast for forward), outmod for CTL2 set to 3 (fast for back)</dd>
    <dd>delay for specified time</dd>
</dl>

```C
void right(int32 time){

    P2OUT |= BIT1;
    P2OUT &= ~BIT3;
    P2OUT |= BIT0|BIT5;						//enable motor

    TA1CCTL1 = OUTMOD_7;					// set TACCTL1 to Reset / Set mode
    TA1CCTL2 = OUTMOD_3;					// set TACCTL1 to Reset / Set mode

    for(i=0;i<time;i++){
		__delay_cycles(1);
	}
}
```

<dl>
  <dt>left
    <dd>P2.1 set to low and P2.3 set to high (left motor goes back right motor goes forward)</dd>
    <dd>both ENBs are set to high to enable motor</dd>
    <dd>both outmod for CTL1 set to 3 (fast for back), outmod for CTL2 set to 7 (fast for forward)</dd>
    <dd>delay for specified time</dd>
</dl>

```C
void left(int32 time){

    P2OUT &= ~BIT1;
    P2OUT |= BIT3;
    P2OUT |= BIT0|BIT5;						//enable motor

    TA1CCTL1 = OUTMOD_3;					// set TACCTL1 to Reset / Set mode
    TA1CCTL2 = OUTMOD_7;					// set TACCTL1 to Reset / Set mode

    for(i=0;i<time;i++){
    	__delay_cycles(1);
    }
}
```

<dl>
  <dt>stop
    <dd>both ENBs are set to low to disable motor</dd>
    <dd>both both outmods set to 5</dd>
    <dd>delay for specified time</dd>
</dl>

```C
void stop(int32 time){

	P2OUT &= ~(BIT0 | BIT5);				//disable motor

	TA1CCTL1 = OUTMOD_5;
	TA1CCTL2 = OUTMOD_5;

	for(i=0;i<time;i++){
		__delay_cycles(1);
	}
}
```

####Functionality
Ultimately the B functionality worked as expected and required. Watch this awesome video

[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/QqOlSv22k2A/0.jpg)](http://www.youtube.com/watch?v=QqOlSv22k2A)

####Debugging/Lessons Learned

This project took a lot of debugging once the code finally comipled. It took multiple tests and run throughs to get the right timing for each direction and I still do not think it is entirely perfect. The right motor was a little bit faster than the left motor so that presented some problems as well. For the most part, the given code helped a lot and it was a fairly easy program to write, but it took time to implement properly. I really wish I had gone for A functionality...




Documentation: C2C Bodin helped explain how the bits had to get set and how the stop funtion worked. C2C bolinger also helped me to understand how to do a high/low setting of a ceratin bit. I used Dr. Coulson's code as a base example. 

