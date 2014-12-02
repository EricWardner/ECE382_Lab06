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


<a href="url"><img src="http://i.imgur.com/ah73whn.jpg" align="left" height="486" width="555" ></a>




[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/QqOlSv22k2A/0.jpg)](http://www.youtube.com/watch?v=QqOlSv22k2A)

