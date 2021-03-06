/*
 * robot.h
 *
 *  Created on: Dec 1, 2014
 *      Author: C16Eric.Wardner
 */

#ifndef ROBOT_H_
#define ROBOT_H_

typedef		unsigned long		int32;

void forward(int32 time);
void back(int32 time);
void right(int32 time);
void left(int32 time);
void stop(int32 time);

#define		TRUE				1
#define		FALSE				0
#define		FORWARD				1000000
#define		BACK				1000000
#define		LEFT45				350000
#define		RIGHT45				300000
#define		LEFT90				500000
#define		RIGHT90				450000
#define		PAUSE				600000

#endif
