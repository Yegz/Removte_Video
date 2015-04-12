#ifndef DEBUG__H_
#define DEBUG__H_

#include <stdio.h>
#include <time.h>

//调试打印
#define plog(fmt,args...) \
do \
{                  \
    time_t now = time(NULL); \
    tm *cur = localtime(&now);  \
    printf("\n%02d:%02d:%02d->[%s %d]:"fmt"\n",cur->tm_hour,cur->tm_min, \
    cur->tm_sec,__func__,__LINE__,##args);  \
    fflush(0); \
}while(0);

#endif
