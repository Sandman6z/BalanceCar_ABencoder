#include "car.h"

int Encoder_Left, Encoder_Right;
int Left_t, Right_t, Encoder_L, Encoder_R;
int Moto_Left, Moto_Right; 
int para_L, para_R;												//增量
int SetPoint = 50;												//设置目标值单位RPM

//使用减速比是1：120的减速箱
#define SetPointL SetPoint * 6240 / 600		//换算成编码器速度，因为最终pid控制的是编码器的脉冲数量
#define SetPointR SetPoint * 6240 / 600
u32 temp1, temp2, temp3;	

//Time1定时器1中断服务函数
//200ms定时
void TIM1_UP_IRQHandler(void)
{
	if(TIM_GetFlagStatus(TIM1, TIM_IT_Update) != RESET)   		//时间到了
	{
		TIM_ClearITPendingBit(TIM1, TIM_FLAG_Update);						//清中断
			LED_Flash(5);																					//500ms闪烁一次
		
			Encoder_Left = Read_Encoder(2);  											//读取编码器 
			Encoder_Right = Read_Encoder(4);  										//读取编码器 			
		
			para_L = PID_Calc_Left(Encoder_Left,SetPointL);				//左电机，计数得到增量式PID的增量数值 
		  para_R = PID_Calc_Right(Encoder_Right,SetPointR);			//右电机，计数得到增量式PID的增量数值 
		
			if((para_L < -3)||(para_L > 3)) 											// 不做 PID 调整，避免误差较小时频繁调节引起震荡。
			{
				Moto_Left += para_L;  
			}   
			if((para_R < -3)||(para_R > 3)) 											// 不做 PID 调整，避免误差较小时频繁调节引起震荡。
			{
				Moto_Right += para_R;  
			}			
  		if(Moto_Left > 3500)Moto_Left = 3500;									//限幅
			if(Moto_Right > 3500)Moto_Right = 3500;								//限幅
			
			TIM3 -> CCR3 = Moto_Left;															//更新pwm
			TIM3 -> CCR4 = Moto_Right;														//更新pwm


			
//			OLED_ShowNum(32,0,SetPoint,5,12);								//编码器目标值
//			temp=SetPoint*300/2496;          								//6240=13*4*120：霍尔编码器13线，STM32编码器模式 4倍频，减速箱1：120
//			OLED_ShowNum(56,1,temp,4,12);    								//减速箱输出目标值

			OLED_ShowNum(70, 2, SetPoint, 3, 16);    								//左轮减速箱输出值
		  //OLED_ShowNum(70, 6, Encoder_Right, 4, 16);    				//右轮减速箱输出值
			
			temp1 = Encoder_Left * 600 / 6240;
			OLED_ShowNum(70, 4, temp1, 3, 16);    									//左实际减速箱输出转速 单位RPM
			
			temp2 = Encoder_Right * 600 / 6240;
			OLED_ShowNum(70, 6, temp2, 3, 16);    									//右实际减速箱输出转速
			//车速
			temp3 = Encoder_Right * 600 / 6240 * 0.065 * 3.1415;		//计算车速
			OLED_ShowNum(40, 0, temp3, 3, 16); 											//显示车速
		}		
}

