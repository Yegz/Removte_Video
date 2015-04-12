#ifndef LOCAL_TIME__H_
#define LOCAL_TIME__H_
#include <stdio.h>
#include <time.h>
#include "sys_debug.h"

extern struct tm *sys_current_time;

typedef struct Date
{
	int hour;
	int min;
	int sec;			
	//公历日月年周
	int w_year;
	int w_month;
	int w_date;	
}Date_t;

void get_cur_sys_time(void);

#endif
