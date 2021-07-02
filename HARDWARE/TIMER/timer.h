#ifndef _TIMER_H
#define _TIMER_H
#include "sys.h"

extern u32 north_south_straight_count,north_south_turnLeft_count,east_west_straight_count,east_west_turnLeft_count,yellow_count;

void TIM2_Int_Init(u16 arr,u16 psc);
void TIM3_Int_Init(u16 arr,u16 psc);
void TIM4_Int_Init(u16 arr,u16 psc);
void TIM5_Int_Init(u16 arr,u16 psc);
void TIM6_Int_Init(u16 arr,u16 psc);
void TIM7_Int_Init(u16 arr,u16 psc);
#endif
