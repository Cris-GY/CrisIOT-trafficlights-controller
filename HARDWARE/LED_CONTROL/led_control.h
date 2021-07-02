#ifndef __LED_CONTROL_H
#define __LED_CONTROL_H
#include "sys.h"

#define sum  north_south_straight_flag+north_south_turnLeft_flag+east_west_straight_flag+east_west_turnLeft_flag

extern u32 north_south_straight_count,north_south_turnLeft_count,east_west_straight_count,east_west_turnLeft_count,yellow_count;
extern u8 north_south_straight_flag,north_south_turnLeft_flag,east_west_straight_flag,east_west_turnLeft_flag,receive_flag;
extern u32 north_south_straight_target,north_south_turnLeft_target,east_west_straight_target,east_west_turnLeft_target,yellow_target;
	 
void LED_Control_Init(void);//≥ı ºªØ
void north_south_straight_green(void);
void north_south_straight_yellow(void);
void north_south_turnLeft_green(void);
void north_south_turnLeft_yellow(void);
void east_west_straight_green(void);
void east_west_straight_yellow(void);
void east_west_turnLeft_green(void);
void east_west_turnLeft_yellow(void);
#endif
