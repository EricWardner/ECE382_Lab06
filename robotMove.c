#include <msp430.h>
#include "robot.h"
int32 i;
void forward(int32 time){
    WDTCTL = WDTPW|WDTHOLD;                 // stop the watchdog timer

    P2DIR |= BIT2;							// P2.2 is associated with TA1CCR1
    P2SEL |= BIT2;							// P2.2 is associated with TA1CCTL1

    P2DIR |= BIT4;							// P2.4 is associated with TA1CCR2
    P2SEL |= BIT4;							// P2.4 is associated with TA1CCTL2

    P2DIR |= BIT1|BIT3;							// P2.4 is associated with TA1CCR2
    P2OUT |= BIT1|BIT3;

	TA1CTL = ID_3 | TASSEL_2 | MC_1;		// Use 1:8 presclar off MCLK
    TA1CCR0 = 0x0100;						// set signal period

    TA1CCR1 = 0x0020;
    TA1CCTL1 = OUTMOD_7;					// set TACCTL1 to Reset / Set mode

    TA1CCR2 = 0x0020;
    TA1CCTL2 = OUTMOD_7;					// set TACCTL1 to Reset / Set mode


    for(i=0;i<time;i++){
    	__delay_cycles(1);
    }
}

void back(int32 time){
    WDTCTL = WDTPW|WDTHOLD;                 // stop the watchdog timer

    P2DIR |= BIT2;							// P2.2 is associated with TA1CCR1
    P2SEL |= BIT2;							// P2.2 is associated with TA1CCTL1

    P2DIR |= BIT4;							// P2.4 is associated with TA1CCR2
    P2SEL |= BIT4;							// P2.4 is associated with TA1CCTL2

    P2DIR |= BIT1|BIT3;							// P2.4 is associated with TA1CCR2
    P2OUT &= ~(BIT1|BIT3);

	TA1CTL = ID_3 | TASSEL_2 | MC_1;		// Use 1:8 presclar off MCLK
    TA1CCR0 = 0x0100;						// set signal period

    TA1CCR1 = 0x0020;
    TA1CCTL1 = OUTMOD_3;					// set TACCTL1 to Reset / Set mode

    TA1CCR2 = 0x0020;
    TA1CCTL2 = OUTMOD_3;					// set TACCTL1 to Reset / Set mode
    for(i=0;i<time;i++){
        __delay_cycles(1);
    }
}

void right(int32 time){
    WDTCTL = WDTPW|WDTHOLD;                 // stop the watchdog timer

    P2DIR |= BIT2;							// P2.2 is associated with TA1CCR1
    P2SEL |= BIT2;							// P2.2 is associated with TA1CCTL1

    P2DIR |= BIT4;							// P2.4 is associated with TA1CCR2
    P2SEL |= BIT4;							// P2.4 is associated with TA1CCTL2

    P2DIR |= BIT1|BIT3;							// P2.4 is associated with TA1CCR2
    P2OUT |= BIT1;
    P2OUT &= ~BIT3;

	TA1CTL = ID_3 | TASSEL_2 | MC_1;		// Use 1:8 presclar off MCLK
    TA1CCR0 = 0x0100;						// set signal period

    TA1CCR1 = 0x0020;
    TA1CCTL1 = OUTMOD_7;					// set TACCTL1 to Reset / Set mode

    TA1CCR2 = 0x0020;
    TA1CCTL2 = OUTMOD_3;					// set TACCTL1 to Reset / Set mode
    for(i=0;i<time;i++){
		__delay_cycles(1);
	}
}
void left(int32 time){
    WDTCTL = WDTPW|WDTHOLD;                 // stop the watchdog timer

    P2DIR |= BIT2;							// P2.2 is associated with TA1CCR1
    P2SEL |= BIT2;							// P2.2 is associated with TA1CCTL1

    P2DIR |= BIT4;							// P2.4 is associated with TA1CCR2
    P2SEL |= BIT4;							// P2.4 is associated with TA1CCTL2

    P2DIR |= BIT1|BIT3;							// P2.4 is associated with TA1CCR2
    P2OUT &= ~BIT1;
    P2OUT |= BIT3;

	TA1CTL = ID_3 | TASSEL_2 | MC_1;		// Use 1:8 presclar off MCLK
    TA1CCR0 = 0x0100;						// set signal period

    TA1CCR1 = 0x0020;
    TA1CCTL1 = OUTMOD_3;					// set TACCTL1 to Reset / Set mode

    TA1CCR2 = 0x0020;
    TA1CCTL2 = OUTMOD_7;					// set TACCTL1 to Reset / Set mode
    for(i=0;i<time;i++){
    	__delay_cycles(1);
    }
}

void stop(int32 time){
	WDTCTL = WDTPW|WDTHOLD;                 // stop the watchdog timer

	    P2DIR |= BIT2;							// P2.2 is associated with TA1CCR1
	    P2SEL |= BIT2;							// P2.2 is associated with TA1CCTL1

	    P2DIR |= BIT4;							// P2.4 is associated with TA1CCR2
	    P2SEL |= BIT4;							// P2.4 is associated with TA1CCTL2

	    P2DIR = 0;							// P2.4 is associated with TA1CCR2
	    P2OUT = 0;


		TA1CTL = ID_3 | TASSEL_2 | MC_1;		// Use 1:8 presclar off MCLK
	    TA1CCR0 = 0x0100;						// set signal period

	    TA1CCR1 = 0x0;
	    TA1CCTL1 = 0;					// set TACCTL1 to Reset / Set mode

	    TA1CCR2 = 0x0;
	    TA1CCTL2 = 0;					// set TACCTL1 to Reset / Set mode
	    for(i=0;i<time;i++){
	    	__delay_cycles(1);
	    }
}
