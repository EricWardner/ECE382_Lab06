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
      
    
  
  

