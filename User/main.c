#include "bsp_sys.h"
#include "stdio.h"



int main(void)
{	
//*****************************系统初始*****************************//	
	STM32_System_Init();//所有系统配置在这个函数里完成	

//MOTO_PWM_Out(2500, 2500);

//Car_Turn_Right();
//Car_Turn_Left();
//Car_Go();
//Car_Back();

	while(1)
	{
		Car_Go();
	}
}	

