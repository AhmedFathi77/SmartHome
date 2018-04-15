/*
 * TimerModule.h
 *
 *  Created on: Apr 9, 2018
 *      Author: leenovoz510
 */

#ifndef TIMERMODULE_H_
#define TIMERMODULE_H_

unsigned int Number_over_flow = 0;

void Timer0_init_Overflow_mode();
void Timer0_init_Compare_mode();
void Timer0_init_PWM_mode(unsigned int Duty_Cylcle);


#endif /* TIMERMODULE_H_ */
