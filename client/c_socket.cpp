#include "c_socket.h"

void perr_exit(const char *buf)
{
	perror(buf);
	exit(1);
}

int server_socket(unsigned short port,int listen_num)
{
  	int socket_fd = 0;
  	int opt = 1;
  	int n;
  	struct sockaddr_in serveraddr;
	
  	//�����׽���,���ж�
  	if(socket_fd = socket(AF_INET,SOCK_STREAM,0) == -1)
  	{
		perr_exit("socket error\n");
	}
  	
  	//���а�
  	bzero(&serveraddr,sizeof(serveraddr));
  	serveraddr.sin_family = AF_INET;
  	serveraddr.sin_addr.s_addr = htons(INADDR_ANY);
  	serveraddr.sin_port = htons(port);
  	//�������˿ں���ͬ��IP��ַ��ͬ�Ķ��socket������
  	n = setsockopt(socket_fd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
  	if(-1 == n)
  	{
  	  	perr_exit("setsockopt error\n");
  	}
  	if(bind(socket_fd,(struct sockaddr*)&serveraddr,sizeof(serveraddr)) < 0)
  	{
  		perr_exit("bind error\n");
  	}
  	//���ü�����
  	if(listen(socket_fd, listen_num) == -1)
  	{
  	  	perr_exit("listen error\n");
  	}
	
  	return(0);  
}


int socket_accept(int socket_Server)
{
    int ret = 0;
    int tmp_flag;
    int err;
    int client_socket;
    socklen_t socket_len;
    socklen_t sockaddr_len = sizeof(struct sockaddr);
    struct sockaddr their_addr;

    fd_set fds;
	

    // ����Ϊ������
    tmp_flag = fcntl(socket_Server, F_GETFL);
    fcntl(socket_Server, F_SETFL, tmp_flag | O_NONBLOCK);

	// �ȴ��ͻ�������
    client_socket = accept(socket_Server, &their_addr, &sockaddr_len);
    if (-1 == client_socket)
    {
        FD_ZERO(&fds);
        FD_SET(socket_Server, &fds);
        ret = select(socket_Server + 1, &fds, NULL, NULL, NULL);
        if (ret <= 0)
        {
            printf("select is error, error code is %d.\n", errno);
            ret = -errno;
            goto exit;
        }

        if (FD_ISSET(socket_Server, &fds))
        {
            client_socket = accept(socket_Server, &their_addr, &sockaddr_len);
            printf("accept socket is %d.\n", client_socket);
        }
    }
	
    ret = client_socket;

	return ret;
	
exit:
    return ret;
}

int server_socket_write(int socket_fd, info_msg * buf, int length)
{
    int ret = 0;
    int send_len = 0; 
    int send_len_two = 0;
    fd_set fds;

    plog(" send data!");
    ret = send(socket_fd, buf, length, 0);
    if (ret < 0)
    {
        ret = -errno;
        plog("Send error, error code is %d\n", -errno);
        goto exit;
    }
    plog(" ret = %d�� length = %d", ret, length);
    send_len += ret;

    while (send_len < length)
    {
        FD_ZERO(&fds);
        FD_SET(socket_fd, &fds);
        ret = select(socket_fd + 1, NULL, &fds, NULL, NULL);
        if (ret <= 0)
        {
            ret = -errno;
            plog("Select error, error code is %d", ret);
            goto exit;
        }

        ret = send(socket_fd, ((char *)buf) + send_len, length - send_len, 0);
        if (ret < 0)
        {
            ret = -errno;
            plog("Send error, error code is %d", -errno);
            goto exit;
        }
        send_len += ret;
    }
    ret = 0;

exit:
    return ret;
}

/*
 * ��������:  ����ͷ����
*/
int server_socket_struct_read(int socket_fd,struct info_msg * buf,int length)
{
    int ret = 0;
    int recv_len = 0;
    fd_set fds;

    while (recv_len < sizeof(struct info_msg))
    {
        struct timeval timeout;

        FD_ZERO(&fds);
        FD_SET(socket_fd, &fds);
        timeout.tv_sec = 2;
        timeout.tv_usec = 0;
        ret = select(socket_fd + 1, &fds, NULL, NULL, &timeout);         // �ж��Ƿ�ɶ�
        if(ret<0)
        {
            ret = recv_len;
            continue;
            goto exit;
        }
        else if(ret == 0)
        {
            plog("time out");
        }
        else
        {
            ret = recv(socket_fd, buf + recv_len, sizeof(struct info_msg) - recv_len, MSG_WAITALL);
            if (ret < 0)
            {
                ret = -errno;
                plog("Net is disconnected!\n");
                goto exit;
            }
            else if (0 == sizeof(buf))
            {
                ret = recv_len;
                goto exit;
            }
            recv_len += ret;
        }
    }

    ret = recv_len;
exit:
    return ret;
}

/*
 * ��������: ������Ϣʵ���ȡ�Ĳ���
*/
int server_socket_msg_read(int socket_fd,struct info_msg *buf,int length)
{
  int ret = 0;
  int recv_len_two = 0;
  fd_set fds;

  //�������յ�ʵ��
    while (recv_len_two < length)
    {
        struct timeval timeout;
        timeout.tv_sec = 2;
        timeout.tv_usec = 0;
        FD_ZERO(&fds);
        FD_SET(socket_fd, &fds);
        ret = select(socket_fd + 1, &fds, NULL, NULL,&timeout);
        if (ret <= 0)
        {
            ret = recv_len_two;
            goto exit;
        }

        ret = recv(socket_fd, (char *)buf->data+ recv_len_two, length - recv_len_two,MSG_WAITALL);
        if(ret == 0)
            {
              break;
            }
        if (ret < 0)
        {
            ret = -errno;
            plog("Net is disconnected!1111\n");
            goto exit;
        }
        else if (0 == (length))
        {
            ret = recv_len_two;
            goto exit;
        }
        recv_len_two += ret;
    }
    ret = recv_len_two;
exit:
    return ret;
}


int server_socket_connect(const char *ip, unsigned short port)
{
  int opt = 0;
  int rc;
  int socket_fd;
  int flags;
  struct sockaddr_in serveraddr;
  fd_set fds;

  
  //�����׽���
  if(-1 == (socket_fd = socket(AF_INET, SOCK_STREAM, 0)))
  {
	perr_exit("socket error\n");
	goto exit;
  }
  
  //���з�����ģʽ����
  flags = fcntl(socket_fd,F_GETFL,0);
  fcntl(socket_fd,F_SETFL,flags | O_NONBLOCK);

  bzero(&serveraddr,sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_addr.s_addr = inet_addr(ip);
  serveraddr.sin_port = htons(port);

  if(connect(socket_fd, (struct sockaddr*)&serveraddr, sizeof(struct sockaddr))==-1)
  	{
  	  if(errno != EINPROGRESS)
  	  {
  	  	  rc = -errno;
  	  	  perr_exit("connect error\n");
		  goto exit;
  	  }
  	  FD_ZERO(&fds);
	  FD_SET(socket_fd,&fds);
      rc = select(socket_fd+1,NULL,&fds,NULL,NULL);
	  if(rc < 0)
	  {
	  	  rc = -errno;
	  	  perr_exit("server_accept_socket_select error\n");		 
		  goto exit;
	  }
      if(0 == rc)
      {
      	  perr_exit("server_socket_connect_select_timeout\n");
      }
	  //�������˿ں���ͬ��IP��ַ��ͬ�Ķ��socket������
      setsockopt(socket_fd,SOL_SOCKET,SO_ERROR,&opt,sizeof(opt));//���һ�������е������
      if(opt != 0)
  	  {
  	      rc = -errno;
  	      perr_exit("setsockopt error\n");
		  goto exit;
  	  }
  	}
  
  rc = socket_fd;
  exit:
  	if(rc < 0 &&socket_fd != -1)
  	{
    	close(socket_fd);
  	}
	return rc;
}


int server_socket_close(int socket_Server)
{
  close(socket_Server);
  sleep(3);
}

