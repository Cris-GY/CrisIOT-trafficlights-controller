#include "stm32f4xx.h"
#include "usart.h"
#include "delay.h"
#include "timer.h"
#include "led.h"
#include "usart3.h"
#include <string.h>
#include "led_control.h" 


u8 north_south_straight_flag,north_south_turnLeft_flag,east_west_straight_flag,east_west_turnLeft_flag,receive_flag;
u32 north_south_straight_count,north_south_turnLeft_count,east_west_straight_count,east_west_turnLeft_count,yellow_count;
u32 north_south_straight_target,north_south_turnLeft_target,east_west_straight_target,east_west_turnLeft_target,yellow_target;


void flag_init(void);
void target_init(void);

int main(void)
{
	u8 reclen=0,reclen1=0;
	int a[6], i = 0, j = 0, num = 0; //用于接收数据转换，处理好的数据存放与a[]中
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	uart_init(115200);
	delay_init(168);  //初始化延时函数
	LED_Init();				//初始化LED端口
	LED_Control_Init();//初始化红绿灯控制端口
	usart3_init(115200);	//初始化串口3为:115200波特率.
	TIM2_Int_Init(10000-1,8400-1);
	TIM3_Int_Init(10000-1,8400-1);
	TIM4_Int_Init(10000-1,8400-1);
	TIM5_Int_Init(10000-1,8400-1);
 	TIM6_Int_Init(10000-1,8400-1);	//定时器时钟84M，分频系数8400，所以84M/8400=10Khz的计数频率，计数10000次为1s   
	flag_init();
	target_init();
	while(1){
		if((east_west_turnLeft_flag==1)&&sum==1)
		{
			east_west_turnLeft_green();
			TIM_Cmd(TIM6,ENABLE);
			TIM_Cmd(TIM2,DISABLE);
			TIM_SetCounter(TIM2, 0);
			yellow_count=0;
			if(east_west_turnLeft_count>=east_west_turnLeft_target)
			{
				east_west_turnLeft_flag=2;
			}
		}
		else if((east_west_turnLeft_flag==2)&&sum==2)
		{
			east_west_turnLeft_yellow();
			TIM_Cmd(TIM2,ENABLE);
			TIM_Cmd(TIM6,DISABLE);
			TIM_SetCounter(TIM6, 0);
			if(yellow_count>=yellow_target)
			{
				north_south_straight_flag=1;
			}
		}
//		else if((east_west_straight_flag==1)&&sum==3)
//		{
//			east_west_straight_green();
//			TIM_Cmd(TIM5,ENABLE);
//			TIM_Cmd(TIM2,DISABLE);
//			TIM_SetCounter(TIM2, 0);
//			yellow_count=0;
//			if(east_west_straight_count>=east_west_straight_target)
//			{
//				east_west_straight_flag=2;
//			}
//		}
//		else if((east_west_straight_flag==2)&&sum==4)
//		{
//			east_west_straight_yellow();

//			TIM_Cmd(TIM2,ENABLE);
//			TIM_Cmd(TIM5,DISABLE);
//			TIM_SetCounter(TIM5, 0);
//			if(yellow_count>=yellow_target)
//			{
//				north_south_turnLeft_flag=1;
//			}
//		}
//		else if((north_south_turnLeft_flag==1)&&sum==5)
//		{
//			north_south_turnLeft_green();
//			TIM_Cmd(TIM4,ENABLE);
//			TIM_Cmd(TIM2,DISABLE);
//			TIM_SetCounter(TIM2, 0);
//			yellow_count=0;
//			if(north_south_turnLeft_count>=north_south_turnLeft_target)
//			{
//				north_south_turnLeft_flag=2;
//			}
//		}
//		
//		else if((north_south_turnLeft_flag==2)&&sum==6)
//		{
//			north_south_turnLeft_yellow();
//			TIM_Cmd(TIM2,ENABLE);
//			TIM_Cmd(TIM4,DISABLE);
//			TIM_SetCounter(TIM4, 0);
//			if(yellow_count>=yellow_target)
//			{
//				north_south_straight_flag=1;
//			}
//		}
		
		else if((north_south_straight_flag==1)&&sum==3)
		{
			north_south_straight_green();
			
			TIM_Cmd(TIM3,ENABLE);
			TIM_Cmd(TIM2,DISABLE);
			TIM_SetCounter(TIM2, 0);
			yellow_count=0;
			if(north_south_straight_count>=north_south_straight_target)
			{
				north_south_straight_flag=2;
			}
		}
		
		else if((north_south_straight_flag==2)&&sum==4)
		{
			north_south_straight_yellow();
			
			TIM_Cmd(TIM2,ENABLE);
			TIM_Cmd(TIM3,DISABLE);
			TIM_SetCounter(TIM3, 0);
			if(yellow_count>=yellow_target)
			{
				if(receive_flag==1)
				{
					east_west_turnLeft_target=a[1];
					east_west_straight_target=a[2];
					north_south_turnLeft_target=a[3];
					north_south_straight_target=a[4];
					yellow_target=3;
				}
				else if(receive_flag==0)
				{
					target_init();
				}
				flag_init();
			}
		}
		
		
		
   if(USART3_RX_STA&0X8000)			//接收到一次数据了
		{
			
 			reclen=USART3_RX_STA&0X7FFF;	//得到数据长度
		  USART3_RX_BUF[reclen]='\r';	 	//加入结束符
			j=0;
			
			for (i = 0; i < 6; i++)
	{
			a[i]=15;	
		printf("clc=%d,", a[i]);
	}
	for (i = 0; i < reclen; i++)
	{
		if ((USART3_RX_BUF[i] - '0') >= 0 && (USART3_RX_BUF[i] - '0') <= 9)
		{
			num = num * 10 + (USART3_RX_BUF[i] - '0');
			
		}
		else if (USART3_RX_BUF[i] == ',' || USART3_RX_BUF[i] == ']')
		{
			a[j] = num;
			j++;
			num = 0;
		}
	}
	  printf("net_receive=");
		for (i = 0; i < j; i++)
	{
		printf("%d,", a[i]);
	}
		printf("\r\n");
		memset(USART3_RX_BUF, 0, reclen);
		receive_flag=1;
 			USART3_RX_STA=0;	 
		}	 

if(USART_RX_STA&0X8000)			//接收到一次数据了
		{
			reclen1=USART_RX_STA&0X7FFF;	//得到数据长度
//			u3_printf("receive=%s",USART_RX_BUF);
			memset(USART_RX_BUF, 0, reclen1);
 			USART_RX_STA=0;	
			
		}	
	}
}


void flag_init(void)
{
	north_south_straight_flag=0;
	north_south_turnLeft_flag=0;
	east_west_straight_flag=0;
	east_west_turnLeft_flag=1;
	receive_flag=0;
	north_south_straight_count=0;
	north_south_turnLeft_count=0;
	east_west_straight_count=0;
	east_west_turnLeft_count=0;
	
}

void target_init(void)
{
	north_south_straight_target=15;
	north_south_turnLeft_target=15;
	east_west_straight_target=15;
	east_west_turnLeft_target=15;
	yellow_target=3;
}

