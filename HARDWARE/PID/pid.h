#ifndef __PID_H
#define __PID_H

#include "stm32f10x.h"


//void PID_Init(void); 
int PID_Calc_Left(int NextPoint,int Setpoint);
int PID_Calc_Right(int NextPoint,int Setpoint);

#endif

