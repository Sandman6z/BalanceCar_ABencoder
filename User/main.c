#include "bsp_sys.h"
#include "stdio.h"



int main(void)
{	
//*****************************ϵͳ��ʼ*****************************//	
	STM32_System_Init();//����ϵͳ������������������	

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

