#include "local_time.h"

/*
 * ��������: ��ȡϵͳ��ǰʱ��
*/
void get_cur_sys_time(void)
{
	time_t ltime;
    
    time(&ltime); 
    sys_current_time = localtime(&ltime);
}