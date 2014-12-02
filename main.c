#include <msp430.h>
#include "robot.h"

extern void forward(int32 time);
extern void back(int32 time);
extern void left(int32 time);
extern void right(int32 time);
extern void stop(int32 time);

void main(void) {
	stop(PAUSE);
	back(BACK);
	stop(PAUSE);
	right(RIGHT45);
	stop(PAUSE);
	left(LEFT45);
	stop(PAUSE);
	right(RIGHT90);
	stop(PAUSE);
	left(LEFT90);
	stop(0);

} // end main
