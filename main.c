#include <msp430.h>
void forward();
void back();
void right45();
void left45();
void stop();


void main(void) {
	forward();
	__delay_cycles(1000000);
	stop();
	__delay_cycles(600000);
	back();
	__delay_cycles(1000000);
	stop();
	__delay_cycles(600000);
	right45();
	__delay_cycles(300000);
	stop();
	__delay_cycles(600000);
	left45();
	__delay_cycles(350000);
	stop();
	__delay_cycles(600000);
	right45();
	__delay_cycles(450000);
	stop();
	__delay_cycles(600000);
	left45();
	__delay_cycles(500000);
	stop();





} // end main

void forward(){
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
}

void back(){
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
}

void right45(){
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
}
void left45(){
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
}
void right90(){
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
    TA1CCTL1 = OUTMOD_3;					// set TACCTL1 to Reset / Set mode

    TA1CCR2 = 0x0020;
    TA1CCTL2 = OUTMOD_7;					// set TACCTL1 to Reset / Set mode
}
void left90(){
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
    TA1CCTL1 = OUTMOD_7;					// set TACCTL1 to Reset / Set mode

    TA1CCR2 = 0x0020;
    TA1CCTL2 = OUTMOD_3;					// set TACCTL1 to Reset / Set mode
}

void stop(){
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
}


