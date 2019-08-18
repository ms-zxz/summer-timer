#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "timer.h"
 

 int main(void)
 {		
 
	delay_init();	    	                        //初始化延时函数 
	LED_Init();			                            //初始化LED端口
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2
	
	TIM3_Int_Init(19999,7199);                      //arr=19999，psc=7199，计数到20000为2000ms

	/*
	
	 (19999+1)*(7199+1)/(72*1000)=2000ms=2s
  
	*/	 
   	
	while(1)
	
	{

	}	 
 
 }	 
 
