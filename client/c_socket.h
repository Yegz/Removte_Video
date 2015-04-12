#ifndef  C_SOCKET__H
#define  C_SOCKET__H

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include "sys_debug.h"
#include "local_time.h"


typedef enum all_type
{
	video = 0,
	audio,
}all_type_t;          //未写完

typedef struct info_msg
{
//  all_type_t cmd;                                                              // type = 0 video;    type = 1 audio
	int   type;
	int   len;                                       //  len为摄像头数据的长度
	Date_t cur_date;                                 //  系统当前的日期
	char  data[0];
	//int written;
}info_msg_t;

typedef struct client_config
{
	int            c_sid;
	char           ser_ip[255];
	unsigned short ser_port;
}client_config_t;

//extern client_config_t g_cfg_client;

//错误信息打印
void perr_exit(const char *buf);

//设置套接字
int server_socket(unsigned short port, int listen_num);

//接受请求
int socket_accept(int socket_Server);

//进行发送
int server_socket_write(int socket_fd, info_msg *buf, int length);

//进行读的操作
int server_socket_read(int socket_fd, struct info_msg *buf, int length);

//关闭套接字
int server_socket_close(int socket_fd);

//连接服务器
int server_socket_connect(const char *ip, unsigned short port);


#endif
