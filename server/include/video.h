#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui>
#include "ui_Video_Play.h"
#include <QString>

class Widget : public QDialog,public Ui_camara
{
    Q_OBJECT
public:
    Widget();
    ~Widget();

private slots:
    void showMe();
    void video_timer_update(QString system_date);
signals:
    void update_video_time(QString);

private:
     QPixmap pix;
     QTimer *timer;
};

#endif
