#include "led_control.h" 


	GPIO_InitTypeDef  A_GPIO_InitStructure;
	GPIO_InitTypeDef  C_GPIO_InitStructure;

void LED_Control_Init(void)
{    	 

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//使能GPIOA时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);//使能GPIOC时钟

	//GPIOA1~6初始化设置 6个
	A_GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 ;
	A_GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
	A_GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
	A_GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
	A_GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
	GPIO_Init(GPIOA, &A_GPIO_InitStructure);//初始化
	
	GPIO_ResetBits(GPIOA,A_GPIO_InitStructure.GPIO_Pin);//GPIOA1~6设置低
	
	
	//GPIOC1~6初始化设置 6个
	C_GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6  ;
	C_GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
	C_GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
	C_GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
	C_GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
	GPIO_Init(GPIOC, &C_GPIO_InitStructure);//初始化
	
	GPIO_ResetBits(GPIOC,C_GPIO_InitStructure.GPIO_Pin);//GPIOC1~6设置低
	
}

void north_south_straight_green(void)
{
	GPIO_ResetBits(GPIOA,A_GPIO_InitStructure.GPIO_Pin);
	GPIO_ResetBits(GPIOC,C_GPIO_InitStructure.GPIO_Pin);
	GPIO_SetBits(GPIOA,GPIO_Pin_4); //东西面直行红
	GPIO_SetBits(GPIOA,GPIO_Pin_1); //东西面左转红
	GPIO_SetBits(GPIOC,GPIO_Pin_5); //南北面直行绿
	GPIO_SetBits(GPIOC,GPIO_Pin_2); //南北面左转绿
}

void north_south_straight_yellow(void)
{
	GPIO_ResetBits(GPIOA,A_GPIO_InitStructure.GPIO_Pin);
	GPIO_ResetBits(GPIOC,C_GPIO_InitStructure.GPIO_Pin);
	GPIO_SetBits(GPIOA,GPIO_Pin_4); //东西面直行红
	GPIO_SetBits(GPIOA,GPIO_Pin_1); //东西面左转红
	GPIO_SetBits(GPIOC,GPIO_Pin_6); //南北面直行黄
	GPIO_SetBits(GPIOC,GPIO_Pin_3); //南北面左转黄
}

void north_south_turnLeft_green(void)
{
	GPIO_ResetBits(GPIOA,A_GPIO_InitStructure.GPIO_Pin);
	GPIO_ResetBits(GPIOC,C_GPIO_InitStructure.GPIO_Pin);
	GPIO_SetBits(GPIOA,GPIO_Pin_4); //东西面直行红
	GPIO_SetBits(GPIOA,GPIO_Pin_1); //东西面左转红
	GPIO_SetBits(GPIOC,GPIO_Pin_4); //南北面直行红
	GPIO_SetBits(GPIOC,GPIO_Pin_2); //南北面左转绿
}

void north_south_turnLeft_yellow(void)
{
	GPIO_ResetBits(GPIOA,A_GPIO_InitStructure.GPIO_Pin);
	GPIO_ResetBits(GPIOC,C_GPIO_InitStructure.GPIO_Pin);
	GPIO_SetBits(GPIOA,GPIO_Pin_4); //东西面直行红
	GPIO_SetBits(GPIOA,GPIO_Pin_1); //东西面左转红
	GPIO_SetBits(GPIOC,GPIO_Pin_4); //南北面直行红
	GPIO_SetBits(GPIOC,GPIO_Pin_3); //南北面左转黄
}

void east_west_straight_green(void)
{
	GPIO_ResetBits(GPIOA,A_GPIO_InitStructure.GPIO_Pin);
	GPIO_ResetBits(GPIOC,C_GPIO_InitStructure.GPIO_Pin);
	GPIO_SetBits(GPIOA,GPIO_Pin_5); //东西面直行绿
	GPIO_SetBits(GPIOA,GPIO_Pin_1); //东西面左转红
	GPIO_SetBits(GPIOC,GPIO_Pin_4); //南北面直行红
	GPIO_SetBits(GPIOC,GPIO_Pin_1); //南北面左转红
}

void east_west_straight_yellow(void)
{
	GPIO_ResetBits(GPIOA,A_GPIO_InitStructure.GPIO_Pin);
	GPIO_ResetBits(GPIOC,C_GPIO_InitStructure.GPIO_Pin);
	GPIO_SetBits(GPIOA,GPIO_Pin_6); //东西面直行黄
	GPIO_SetBits(GPIOA,GPIO_Pin_1); //东西面左转红
	GPIO_SetBits(GPIOC,GPIO_Pin_4); //南北面直行红
	GPIO_SetBits(GPIOC,GPIO_Pin_1); //南北面左转红
}

void east_west_turnLeft_green(void)
{
	GPIO_ResetBits(GPIOA,A_GPIO_InitStructure.GPIO_Pin);
	GPIO_ResetBits(GPIOC,C_GPIO_InitStructure.GPIO_Pin);
	GPIO_SetBits(GPIOA,GPIO_Pin_5); //东西面直行绿
	GPIO_SetBits(GPIOA,GPIO_Pin_2); //东西面左转绿
	GPIO_SetBits(GPIOC,GPIO_Pin_4); //南北面直行红
	GPIO_SetBits(GPIOC,GPIO_Pin_1); //南北面左转红
}

void east_west_turnLeft_yellow(void)
{
	
	GPIO_ResetBits(GPIOA,A_GPIO_InitStructure.GPIO_Pin);
	GPIO_ResetBits(GPIOC,C_GPIO_InitStructure.GPIO_Pin);
	GPIO_SetBits(GPIOA,GPIO_Pin_6); //东西面直行黄
	GPIO_SetBits(GPIOA,GPIO_Pin_3); //东西面左转黄
	GPIO_SetBits(GPIOC,GPIO_Pin_4); //南北面直行红
	GPIO_SetBits(GPIOC,GPIO_Pin_1); //南北面左转红
}



