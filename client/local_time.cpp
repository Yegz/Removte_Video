#include "local_time.h"

/*
 * 函数功能: 获取系统当前时间
*/
void get_cur_sys_time(void)
{
	time_t ltime;
    
    time(&ltime); 
    sys_current_time = localtime(&ltime);
}