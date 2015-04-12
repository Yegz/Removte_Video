#include <QApplication>
#include <QTextCodec>
#include "yuyv_to_rgb24.h"
#include "local_time.h"
#include "c_socket.h"
#include "camera.h"
#include "sys_debug.h"
#include "client_login.h"
#include <libr263.h>
#include <convert.h>
#include <Tmndec.h>
#include <def.h>
#include <Global.h>

extern struct v4l2_buffer buf;
extern VideoBuffer *camara_buffers;
extern int camara_fd;

char *common_p;
struct tm *sys_current_time;
client_config_t g_cfg_client;
CAM_V4L *cam;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("gb2312"));   // Ê¹ÓÃgb2312
    int ret;
    info_msg_t demo;
    info_msg_t *genmsg = &demo;
    CParam cparams;
    unsigned char *rgb;
    unsigned int *yuv;
    static unsigned char *cdata;
    static int count;
    CAM_V4L cam_v4l;

    Clogin lg;
    cam = &cam_v4l;

    if(lg.exec()==QDialog::Accepted)
    {
        if (v4l2_init(cam, "/dev/video0"))
        {
            printf("v4l2_init() is error!\n");
        }

        plog("The g_client_ser_ip: %s, g_client_ser_port: %d\n", g_cfg_client.ser_ip, g_cfg_client.ser_port);

        g_cfg_client.c_sid  = server_socket_connect(g_cfg_client.ser_ip, g_cfg_client.ser_port);

        plog("The client connect successfully\n");
        while(1)
        {
            unsigned char src[buf.length+1];
            unsigned char dest[buf.length+1];

            if (v4l2_read_pic(0))
            {
                return 0;
            }
            memcpy(src, camara_buffers[buf.index].start, buf.length);
            ret = compress_yuyv_to_jpeg(src, dest, (WIDTH * HEIGHT) ,40);

            genmsg = (struct info_msg*)malloc(sizeof(struct info_msg) + sizeof(dest));
            memset(genmsg, 0, sizeof(struct info_msg) + sizeof(dest));

            genmsg->type = 0;
            genmsg->len = ret+1;
            get_cur_sys_time();
            genmsg->cur_date.w_year = sys_current_time->tm_year + 1900;
            genmsg->cur_date.w_month = sys_current_time->tm_mon + 1;
            genmsg->cur_date.w_date = sys_current_time->tm_mday;
            genmsg->cur_date.hour = sys_current_time->tm_hour;
            genmsg->cur_date.min = sys_current_time->tm_min;
            genmsg->cur_date.sec = sys_current_time->tm_sec;
            common_p = (char*)dest;
            memcpy(genmsg->data, common_p, ret);

            plog(" LEN=%d    TYPE=%d ", genmsg->len, genmsg->type);

            if(server_socket_write(g_cfg_client.c_sid,genmsg,genmsg->len+sizeof(struct info_msg))<0)
                plog("server_socket_write error!");

            free(genmsg);
        }

        return app.exec();
    }
    else
        return 0;
}
