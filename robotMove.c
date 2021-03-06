#include <msp430.h>
#include "robot.h"
int32 i;

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

void back(int32 time){

    P2OUT &= ~(BIT1|BIT3);
    P2OUT |= BIT0|BIT5;						//enable motor

    TA1CCTL1 = OUTMOD_3;					// set TACCTL1 to Reset / Set mode
    TA1CCTL2 = OUTMOD_3;					// set TACCTL1 to Reset / Set mode

    for(i=0;i<time;i++){
        __delay_cycles(1);
    }
}

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

void stop(int32 time){

	P2OUT &= ~(BIT0 | BIT5);				//disable motor

	TA1CCTL1 = OUTMOD_5;
	TA1CCTL2 = OUTMOD_5;

	for(i=0;i<time;i++){
		__delay_cycles(1);
	}
}
