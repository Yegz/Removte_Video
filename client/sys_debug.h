#ifndef SYS_DEBUG__H_
#define SYS_DEBUG__H_
#include <stdio.h>

#define plog(fmt,args...) \
do \
{                  \
    printf("Plog-->[%s %d]: "fmt"\n",__func__,__LINE__,##args);  \
    fflush(0); \
}while(0);

#endif
