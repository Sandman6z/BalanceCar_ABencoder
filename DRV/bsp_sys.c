/*
********************************************************************************************************
文件名：bsp_sys.c
功  能：初始化所有外设
备  注：
淘  宝：https://shop60670850.taobao.com
作  者：lilianhe
日  期: 2017-2-6
*********************************************************************************************************
*/

#include "bsp_sys.h"

void STM32_System_Init(void)
{	
	//STM32内部初始化
	
	Delay_Init(72);        //滴答时钟初始化
	NVIC_Config();         //中断配置配置初始化
	LED_GPIO_Config();     //LED初始化
	USART1_Init(115200);   //串口初始化
	IIC_Init();            //IIC模拟初始化
	
	MOTO_GPIO_Init();       //电机驱动IO配置
	MOTO_PWM_Init(3599,0);  //电机的PWM频率初始化20KHz
	

	OLED_Init();
  OLED_Clear();
	OLED_ShowString(80,0,"m/min",16);
	OLED_ShowString(104,4,"RPM",16);
	OLED_ShowString(104,6,"RPM",16);
	OLED_ShowString(104,2,"RPM",16);
	
	OLED_ShowCHinese(0,0,2);//车
	OLED_ShowCHinese(16,0,3);//速
	
	OLED_ShowCHinese(0,2,0);//设
	OLED_ShowCHinese(16,2,1);//定
	OLED_ShowCHinese(32,2,2);//车
	OLED_ShowCHinese(48,2,3);//速
	
	OLED_ShowCHinese(0,4,4);//左
	OLED_ShowCHinese(16,4,6);//轮
	OLED_ShowCHinese(32,4,3);//速
	OLED_ShowCHinese(48,4,7);//度
	
	OLED_ShowCHinese(0,6,5);//右
	OLED_ShowCHinese(16,6,6);//轮
	OLED_ShowCHinese(32,6,3);//速
	OLED_ShowCHinese(48,6,7);//度
	
	//PID_Init();
	Encoder_Init_TIM2();
	Encoder_Init_TIM4();
	
	Timer1_Init();//最后启动定时器1
	Delay_ms(100);          //等待初始化完成
}


