#include "pid.h"

//增量式pid
//int      SetPoint;                  //设定目标 Desired Value

//定义PID相关宏
// 这三个参数设定对电机运行影响非常大
/*************************************/
//#define  P_DATA      0.6                          //P参数
//#define  I_DATA      0.1                          //I参数
//#define  D_DATA      0                            //D参数
	static double   Proportion = 0.6;                 //比例常数 Proportional Const
	static double   Integral   = 0.1;                 //积分常数 Integral Const
	static double   Derivative = 0;  


/********************增量式PID控制设计************************************/
//NextPoint当前输出值
//SetPoint设定值
int PID_Calc_Left(int NextPoint,int SetPoint) 
{
																										//微分常数 Derivative Const
	static int      LastError;                        //Error[-1]
	static int      PrevError;                        //Error[-2]
  int iError, Outpid;                               //当前误差
	
  iError = SetPoint - NextPoint;                    //增量计算
  Outpid = (Proportion * iError)                   	//E[k]项
              - (Integral * LastError)      				//E[k-1]项
              + (Derivative * PrevError);   				//E[k-2]项
              
  PrevError = LastError;                    			 	//存储误差，用于下次计算
  LastError = iError;
	
  return(Outpid);                                   //返回增量值
}

int PID_Calc_Right(int NextPoint,int SetPoint) 
{
//	static double   Proportion;                     //比例常数 Proportional Const
//	static double   Integral;                       //积分常数 Integral Const
//	static double   Derivative;                     //微分常数 Derivative Const
	static int      LastError;                        //Error[-1]
	static int      PrevError;                        //Error[-2]
  int iError, Outpid;                               //当前误差
	
  iError = SetPoint - NextPoint;                    //增量计算
  Outpid = (Proportion * iError)										//E[k]项
              - (Integral * LastError)      				//E[k-1]项
              + (Derivative * PrevError);  	 				//E[k-2]项
              
  PrevError = LastError;                     				//存储误差，用于下次计算
  LastError = iError;
	
  return(Outpid);                                   //返回增量值
}
