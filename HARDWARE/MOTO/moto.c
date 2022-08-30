#include "moto.h"


//PWM在timer3里配置
void MOTO_GPIO_Init(void)
{		
	/*定义一个GPIO_InitTypeDef类型的结构体*/
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);                                	  /*开启GPIO的外设时钟*/																   
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;	  /*选择要控制的GPIO引脚*/	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;                              					/*设置引脚模式为通用推挽输出*/   
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;                             					/*设置引脚速率为50MHz */ 
	GPIO_Init(GPIOB, &GPIO_InitStructure);                                									/*调用库函数，初始化GPIO*/			
}


//左电机
void MOTO_Left(char state)
{
	if(state == GO)//左前电机前进
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_13);
	  GPIO_ResetBits(GPIOB,GPIO_Pin_12);
	}
	if(state == BACK)//左前电机后退
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_12);
	  GPIO_ResetBits(GPIOB,GPIO_Pin_13);
		
	}
	if(state == STOP)//停转
	{
		GPIO_ResetBits(GPIOB,GPIO_Pin_12);
	  GPIO_ResetBits(GPIOB,GPIO_Pin_13);
	}
			
}

//右电机
void MOTO_Right(char state)
{
	if(state == GO)//左前电机前进
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_14);
	  GPIO_ResetBits(GPIOB,GPIO_Pin_15);
	}
	if(state == BACK)//左前电机后退
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_14);
	  GPIO_ResetBits(GPIOB,GPIO_Pin_15);	
	}
	if(state == STOP)//停转
	{
		GPIO_ResetBits(GPIOB,GPIO_Pin_14);
	  GPIO_ResetBits(GPIOB,GPIO_Pin_15);
	}		
}



//***************************前进**************************//
//只要配置()的状态就可以改变电机转动方向
void Car_Go(void)
{
	//左电机 前    //右电机 前
	MOTO_Left(GO);  MOTO_Right(GO);
}

//***************************后退**************************//
void Car_Back(void)
{
  //左电机 后       //右电机 后
	MOTO_Left(BACK);  MOTO_Right(BACK);
}

//***************************向左转圈***********************//
void Car_Turn_Left(void)
{
	//左电机 后       //右电机 前
	MOTO_Left(BACK);  MOTO_Right(GO);
}


//***************************向右转圈***********************//
void Car_Turn_Right(void)
{
	//左电机 前    //右电机 后
	MOTO_Left(GO);  MOTO_Right(BACK);
}

//***************************停车***************************//
void Car_Stop(void)
{
	//左电机 停    //右电机 停
	MOTO_Left(STOP);  MOTO_Right(STOP);
}
