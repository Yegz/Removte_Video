#include <QtGui>
#include <QDebug>
#include "ui_Video_Play.h"
#include "video.h"
#include "c_socket.h"

Widget::Widget()
{
    setupUi(this);
    timer = new QTimer(this);                                       // 获取视频间隔触发器
    connect (timer, SIGNAL(timeout()), this, SLOT(showMe()));
    connect (this, SIGNAL(update_video_time(QString)), this, SLOT(video_timer_update(QString)));
    lcdNumber_1->display("00-00-00  00:00:00");
    lcdNumber_2->display("00-00-00  00:00:00");

    timer->start(1000);
}

void Widget::showMe()
{
    this->setAttribute(Qt::WA_PaintOutsidePaintEvent);
    int fd_server,fd_client;
    info_msg_t genmsg_req;
    info_msg_t *demo1;
    info_msg_t *demo = &genmsg_req;
    QString old_time("2014-12-12 09:09:09");
    QString text;
    int i = 1;

    memset(demo,0,sizeof(info_msg_t));
    struct sockaddr_in seraddr;
    fd_server = socket(AF_INET, SOCK_STREAM,0);
    bzero(&seraddr,sizeof(seraddr));
    seraddr.sin_family = AF_INET;                 //inet_addr("127.0.0.1")
    seraddr.sin_addr.s_addr = htonl(INADDR_ANY);  //192.168.23.235
    seraddr.sin_port = htons(8000);
    bind(fd_server,(struct sockaddr*)&seraddr,sizeof(seraddr));
    listen(fd_server,20);
    qDebug()<<__func__<<"   "<<__LINE__;
    fd_client = socket_accept(fd_server);
    qDebug()<<__func__<<"   "<<__LINE__;

    //label_camera->resize(320, 240);
    while(1)
    {     
        qApp->processEvents();
        memset(demo, 0, sizeof(info_msg_t));
        server_socket_struct_read(fd_client, demo, sizeof(info_msg_t));

        text = QString("%1 - %2 - %3   %4:%5:%6").arg(demo->cur_date.w_year).arg(demo->cur_date.w_month).arg(
                    demo->cur_date.w_date).arg(demo->cur_date.hour).arg(demo->cur_date.min).arg(demo->cur_date.sec);
        qDebug()<<"The Server time : "<< text;
        demo1 = (info_msg_t *)malloc(demo->len + sizeof(info_msg_t) );
        memset(demo1,  0, demo->len + sizeof(info_msg_t));
        server_socket_msg_read(fd_client, demo1, demo->len);
        pix.loadFromData((uchar *)(demo1->data),demo->len, "JPEG");
        camera1->setPixmap(pix);
        camera2->setPixmap(pix);
        //painter.drawImage(target1, image, image.rect());

        i = QString::compare(old_time, text, Qt::CaseSensitive);
        if(i != 0)
        {
            emit update_video_time(text);
        }

        old_time = text;
        free(demo1);
    }
    server_socket_close(fd_server);
}

Widget::~Widget()
{

}

void Widget::video_timer_update(QString system_date)
{
    lcdNumber_1->display(system_date);
    lcdNumber_2->display(system_date);
}

