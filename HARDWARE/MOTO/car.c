#include "car.h"

int Encoder_Left, Encoder_Right;
int Left_t, Right_t, Encoder_L, Encoder_R;
int Moto_Left, Moto_Right; 
int para_L, para_R;												//����
int SetPoint = 50;												//����Ŀ��ֵ��λRPM

//ʹ�ü��ٱ���1��120�ļ�����
#define SetPointL SetPoint * 6240 / 600		//����ɱ������ٶȣ���Ϊ����pid���Ƶ��Ǳ���������������
#define SetPointR SetPoint * 6240 / 600
u32 temp1, temp2, temp3;	

//Time1��ʱ��1�жϷ�����
//200ms��ʱ
void TIM1_UP_IRQHandler(void)
{
	if(TIM_GetFlagStatus(TIM1, TIM_IT_Update) != RESET)   		//ʱ�䵽��
	{
		TIM_ClearITPendingBit(TIM1, TIM_FLAG_Update);						//���ж�
			LED_Flash(5);																					//500ms��˸һ��
		
			Encoder_Left = Read_Encoder(2);  											//��ȡ������ 
			Encoder_Right = Read_Encoder(4);  										//��ȡ������ 			
		
			para_L = PID_Calc_Left(Encoder_Left,SetPointL);				//�����������õ�����ʽPID��������ֵ 
		  para_R = PID_Calc_Right(Encoder_Right,SetPointR);			//�ҵ���������õ�����ʽPID��������ֵ 
		
			if((para_L < -3)||(para_L > 3)) 											// ���� PID ��������������СʱƵ�����������𵴡�
			{
				Moto_Left += para_L;  
			}   
			if((para_R < -3)||(para_R > 3)) 											// ���� PID ��������������СʱƵ�����������𵴡�
			{
				Moto_Right += para_R;  
			}			
  		if(Moto_Left > 3500)Moto_Left = 3500;									//�޷�
			if(Moto_Right > 3500)Moto_Right = 3500;								//�޷�
			
			TIM3 -> CCR3 = Moto_Left;															//����pwm
			TIM3 -> CCR4 = Moto_Right;														//����pwm


			
//			OLED_ShowNum(32,0,SetPoint,5,12);								//������Ŀ��ֵ
//			temp=SetPoint*300/2496;          								//6240=13*4*120������������13�ߣ�STM32������ģʽ 4��Ƶ��������1��120
//			OLED_ShowNum(56,1,temp,4,12);    								//���������Ŀ��ֵ

			OLED_ShowNum(70, 2, SetPoint, 3, 16);    								//���ּ��������ֵ
		  //OLED_ShowNum(70, 6, Encoder_Right, 4, 16);    				//���ּ��������ֵ
			
			temp1 = Encoder_Left * 600 / 6240;
			OLED_ShowNum(70, 4, temp1, 3, 16);    									//��ʵ�ʼ��������ת�� ��λRPM
			
			temp2 = Encoder_Right * 600 / 6240;
			OLED_ShowNum(70, 6, temp2, 3, 16);    									//��ʵ�ʼ��������ת��
			//����
			temp3 = Encoder_Right * 600 / 6240 * 0.065 * 3.1415;		//���㳵��
			OLED_ShowNum(40, 0, temp3, 3, 16); 											//��ʾ����
		}		
}

