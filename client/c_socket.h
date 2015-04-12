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
}all_type_t;          //δд��

typedef struct info_msg
{
//  all_type_t cmd;                                                              // type = 0 video;    type = 1 audio
	int   type;
	int   len;                                       //  lenΪ����ͷ���ݵĳ���
	Date_t cur_date;                                 //  ϵͳ��ǰ������
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

//������Ϣ��ӡ
void perr_exit(const char *buf);

//�����׽���
int server_socket(unsigned short port, int listen_num);

//��������
int socket_accept(int socket_Server);

//���з���
int server_socket_write(int socket_fd, info_msg *buf, int length);

//���ж��Ĳ���
int server_socket_read(int socket_fd, struct info_msg *buf, int length);

//�ر��׽���
int server_socket_close(int socket_fd);

//���ӷ�����
int server_socket_connect(const char *ip, unsigned short port);


#endif