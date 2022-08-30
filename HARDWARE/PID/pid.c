#include "pid.h"

//����ʽpid
//int      SetPoint;                  //�趨Ŀ�� Desired Value

//����PID��غ�
// �����������趨�Ե������Ӱ��ǳ���
/*************************************/
//#define  P_DATA      0.6                          //P����
//#define  I_DATA      0.1                          //I����
//#define  D_DATA      0                            //D����
	static double   Proportion = 0.6;                 //�������� Proportional Const
	static double   Integral   = 0.1;                 //���ֳ��� Integral Const
	static double   Derivative = 0;  


/********************����ʽPID�������************************************/
//NextPoint��ǰ���ֵ
//SetPoint�趨ֵ
int PID_Calc_Left(int NextPoint,int SetPoint) 
{
																										//΢�ֳ��� Derivative Const
	static int      LastError;                        //Error[-1]
	static int      PrevError;                        //Error[-2]
  int iError, Outpid;                               //��ǰ���
	
  iError = SetPoint - NextPoint;                    //��������
  Outpid = (Proportion * iError)                   	//E[k]��
              - (Integral * LastError)      				//E[k-1]��
              + (Derivative * PrevError);   				//E[k-2]��
              
  PrevError = LastError;                    			 	//�洢�������´μ���
  LastError = iError;
	
  return(Outpid);                                   //��������ֵ
}

int PID_Calc_Right(int NextPoint,int SetPoint) 
{
//	static double   Proportion;                     //�������� Proportional Const
//	static double   Integral;                       //���ֳ��� Integral Const
//	static double   Derivative;                     //΢�ֳ��� Derivative Const
	static int      LastError;                        //Error[-1]
	static int      PrevError;                        //Error[-2]
  int iError, Outpid;                               //��ǰ���
	
  iError = SetPoint - NextPoint;                    //��������
  Outpid = (Proportion * iError)										//E[k]��
              - (Integral * LastError)      				//E[k-1]��
              + (Derivative * PrevError);  	 				//E[k-2]��
              
  PrevError = LastError;                     				//�洢�������´μ���
  LastError = iError;
	
  return(Outpid);                                   //��������ֵ
}
