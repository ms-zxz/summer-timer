#include "timer.h"
#include "led.h"
	 
//ͨ�ö�ʱ��3�жϳ�ʼ��
void TIM3_Int_Init(u16 arr,u16 psc)
	{
		TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
		NVIC_InitTypeDef NVIC_InitStructure;                         //�������

		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);         //ʱ��ʹ��
		
		//��ʱ��TIM3��ʼ��
		TIM_TimeBaseStructure.TIM_Period = arr;                      //��һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	
		TIM_TimeBaseStructure.TIM_Prescaler =psc;                    //������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
		TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;      //ʱ�ӷָ�:TDTS = Tck_tim
		TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //���ϼ���ģʽ
		TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);              //����ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
	 
		TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE );                    //ʹ�ܶ�ʱ��TIM3�ж�,��������ж�

		//�ж����ȼ�NVIC����
		NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;              //TIM3�ж�
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;    //��ռ���ȼ�0��
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;           //�����ȼ�3��
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;              //IRQͨ����ʹ��
		NVIC_Init(&NVIC_InitStructure);                              //��ʼ��NVIC�Ĵ���

		TIM_Cmd(TIM3, ENABLE);                                       //ʹ�ܶ�ʱ��TIM3				 
	}
//��ʱ��3�жϷ������
void TIM3_IRQHandler(void)                                           //TIM3�ж�
	{
		if (TIM_GetITStatus(TIM3, TIM_IT_Update) == SET)             //�ж�TIM3�����ж��Ƿ���
			{
				TIM_ClearITPendingBit(TIM3, TIM_IT_Update  );        //��������жϱ�־ 
				
				LED1=!LED1;
				LED0=!LED0;                                          //LED0,LED1ͬʱ��ת
			}
	}
