/*
********************************************************************************************************
�ļ�����bsp_NVIC.c
��  �ܣ��ж�����
��  ע��
��  ����https://shop60670850.taobao.com
��  �ߣ�lilianhe
��  ��: 2017-2-6
*********************************************************************************************************
*/

/*
********************************************************************************************************
������־��
1.2017-2-6,��дuart��time�ж�


*********************************************************************************************************
*/

#include "bsp_nvic.h"

/*
********************************************************************************************************
�������ƣ�void NVIC_Config(void)
�������ܣ����ø����жϵ����ȼ�
Ӳ�����ӣ�
��    ע��
��    ��: 2017-2-6
*********************************************************************************************************
*/
void NVIC_Config(void)
{
	NVIC_TIM1_Config();
}





//����timer3���ж�����
void NVIC_TIM1_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
	NVIC_InitStructure.NVIC_IRQChannel=TIM1_UP_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

//------------------End of File----------------------------