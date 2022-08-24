/*
********************************************************************************************************
�ļ�����bsp_sys.c
��  �ܣ���ʼ����������
��  ע��
��  ����https://shop60670850.taobao.com
��  �ߣ�lilianhe
��  ��: 2017-2-6
*********************************************************************************************************
*/

#include "bsp_sys.h"

void STM32_System_Init(void)
{	
	//STM32�ڲ���ʼ��
	
	Delay_Init(72);        //�δ�ʱ�ӳ�ʼ��
	NVIC_Config();         //�ж��������ó�ʼ��
	LED_GPIO_Config();     //LED��ʼ��
	USART1_Init(115200);   //���ڳ�ʼ��
	IIC_Init();            //IICģ���ʼ��
	
	MOTO_GPIO_Init();       //�������IO����
	MOTO_PWM_Init(3599,0);  //�����PWMƵ�ʳ�ʼ��20KHz
	

	OLED_Init();
  OLED_Clear();
	OLED_ShowString(80,0,"m/min",16);
	OLED_ShowString(104,4,"RPM",16);
	OLED_ShowString(104,6,"RPM",16);
	OLED_ShowString(104,2,"RPM",16);
	
	OLED_ShowCHinese(0,0,2);//��
	OLED_ShowCHinese(16,0,3);//��
	
	OLED_ShowCHinese(0,2,0);//��
	OLED_ShowCHinese(16,2,1);//��
	OLED_ShowCHinese(32,2,2);//��
	OLED_ShowCHinese(48,2,3);//��
	
	OLED_ShowCHinese(0,4,4);//��
	OLED_ShowCHinese(16,4,6);//��
	OLED_ShowCHinese(32,4,3);//��
	OLED_ShowCHinese(48,4,7);//��
	
	OLED_ShowCHinese(0,6,5);//��
	OLED_ShowCHinese(16,6,6);//��
	OLED_ShowCHinese(32,6,3);//��
	OLED_ShowCHinese(48,6,7);//��
	
	//PID_Init();
	Encoder_Init_TIM2();
	Encoder_Init_TIM4();
	
	Timer1_Init();//���������ʱ��1
	Delay_ms(100);          //�ȴ���ʼ�����
}


