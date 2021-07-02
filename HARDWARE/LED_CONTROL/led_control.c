#include "led_control.h" 


	GPIO_InitTypeDef  A_GPIO_InitStructure;
	GPIO_InitTypeDef  C_GPIO_InitStructure;

void LED_Control_Init(void)
{    	 

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);//ʹ��GPIOAʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);//ʹ��GPIOCʱ��

	//GPIOA1~6��ʼ������ 6��
	A_GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 ;
	A_GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
	A_GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
	A_GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
	A_GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
	GPIO_Init(GPIOA, &A_GPIO_InitStructure);//��ʼ��
	
	GPIO_ResetBits(GPIOA,A_GPIO_InitStructure.GPIO_Pin);//GPIOA1~6���õ�
	
	
	//GPIOC1~6��ʼ������ 6��
	C_GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6  ;
	C_GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
	C_GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
	C_GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
	C_GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
	GPIO_Init(GPIOC, &C_GPIO_InitStructure);//��ʼ��
	
	GPIO_ResetBits(GPIOC,C_GPIO_InitStructure.GPIO_Pin);//GPIOC1~6���õ�
	
}

void north_south_straight_green(void)
{
	GPIO_ResetBits(GPIOA,A_GPIO_InitStructure.GPIO_Pin);
	GPIO_ResetBits(GPIOC,C_GPIO_InitStructure.GPIO_Pin);
	GPIO_SetBits(GPIOA,GPIO_Pin_4); //������ֱ�к�
	GPIO_SetBits(GPIOA,GPIO_Pin_1); //��������ת��
	GPIO_SetBits(GPIOC,GPIO_Pin_5); //�ϱ���ֱ����
	GPIO_SetBits(GPIOC,GPIO_Pin_2); //�ϱ�����ת��
}

void north_south_straight_yellow(void)
{
	GPIO_ResetBits(GPIOA,A_GPIO_InitStructure.GPIO_Pin);
	GPIO_ResetBits(GPIOC,C_GPIO_InitStructure.GPIO_Pin);
	GPIO_SetBits(GPIOA,GPIO_Pin_4); //������ֱ�к�
	GPIO_SetBits(GPIOA,GPIO_Pin_1); //��������ת��
	GPIO_SetBits(GPIOC,GPIO_Pin_6); //�ϱ���ֱ�л�
	GPIO_SetBits(GPIOC,GPIO_Pin_3); //�ϱ�����ת��
}

void north_south_turnLeft_green(void)
{
	GPIO_ResetBits(GPIOA,A_GPIO_InitStructure.GPIO_Pin);
	GPIO_ResetBits(GPIOC,C_GPIO_InitStructure.GPIO_Pin);
	GPIO_SetBits(GPIOA,GPIO_Pin_4); //������ֱ�к�
	GPIO_SetBits(GPIOA,GPIO_Pin_1); //��������ת��
	GPIO_SetBits(GPIOC,GPIO_Pin_4); //�ϱ���ֱ�к�
	GPIO_SetBits(GPIOC,GPIO_Pin_2); //�ϱ�����ת��
}

void north_south_turnLeft_yellow(void)
{
	GPIO_ResetBits(GPIOA,A_GPIO_InitStructure.GPIO_Pin);
	GPIO_ResetBits(GPIOC,C_GPIO_InitStructure.GPIO_Pin);
	GPIO_SetBits(GPIOA,GPIO_Pin_4); //������ֱ�к�
	GPIO_SetBits(GPIOA,GPIO_Pin_1); //��������ת��
	GPIO_SetBits(GPIOC,GPIO_Pin_4); //�ϱ���ֱ�к�
	GPIO_SetBits(GPIOC,GPIO_Pin_3); //�ϱ�����ת��
}

void east_west_straight_green(void)
{
	GPIO_ResetBits(GPIOA,A_GPIO_InitStructure.GPIO_Pin);
	GPIO_ResetBits(GPIOC,C_GPIO_InitStructure.GPIO_Pin);
	GPIO_SetBits(GPIOA,GPIO_Pin_5); //������ֱ����
	GPIO_SetBits(GPIOA,GPIO_Pin_1); //��������ת��
	GPIO_SetBits(GPIOC,GPIO_Pin_4); //�ϱ���ֱ�к�
	GPIO_SetBits(GPIOC,GPIO_Pin_1); //�ϱ�����ת��
}

void east_west_straight_yellow(void)
{
	GPIO_ResetBits(GPIOA,A_GPIO_InitStructure.GPIO_Pin);
	GPIO_ResetBits(GPIOC,C_GPIO_InitStructure.GPIO_Pin);
	GPIO_SetBits(GPIOA,GPIO_Pin_6); //������ֱ�л�
	GPIO_SetBits(GPIOA,GPIO_Pin_1); //��������ת��
	GPIO_SetBits(GPIOC,GPIO_Pin_4); //�ϱ���ֱ�к�
	GPIO_SetBits(GPIOC,GPIO_Pin_1); //�ϱ�����ת��
}

void east_west_turnLeft_green(void)
{
	GPIO_ResetBits(GPIOA,A_GPIO_InitStructure.GPIO_Pin);
	GPIO_ResetBits(GPIOC,C_GPIO_InitStructure.GPIO_Pin);
	GPIO_SetBits(GPIOA,GPIO_Pin_5); //������ֱ����
	GPIO_SetBits(GPIOA,GPIO_Pin_2); //��������ת��
	GPIO_SetBits(GPIOC,GPIO_Pin_4); //�ϱ���ֱ�к�
	GPIO_SetBits(GPIOC,GPIO_Pin_1); //�ϱ�����ת��
}

void east_west_turnLeft_yellow(void)
{
	
	GPIO_ResetBits(GPIOA,A_GPIO_InitStructure.GPIO_Pin);
	GPIO_ResetBits(GPIOC,C_GPIO_InitStructure.GPIO_Pin);
	GPIO_SetBits(GPIOA,GPIO_Pin_6); //������ֱ�л�
	GPIO_SetBits(GPIOA,GPIO_Pin_3); //��������ת��
	GPIO_SetBits(GPIOC,GPIO_Pin_4); //�ϱ���ֱ�к�
	GPIO_SetBits(GPIOC,GPIO_Pin_1); //�ϱ�����ת��
}



