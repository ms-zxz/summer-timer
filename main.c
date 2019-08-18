#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "timer.h"
 

 int main(void)
 {		
 
	delay_init();	    	                        //��ʼ����ʱ���� 
	LED_Init();			                            //��ʼ��LED�˿�
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC�жϷ���2
	
	TIM3_Int_Init(19999,7199);                      //arr=19999��psc=7199��������20000Ϊ2000ms

	/*
	
	 (19999+1)*(7199+1)/(72*1000)=2000ms=2s
  
	*/	 
   	
	while(1)
	
	{

	}	 
 
 }	 
 
