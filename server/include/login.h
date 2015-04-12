#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QMessageBox>
#include <QSettings>
#include <QObject>
#include <QDebug>
#include "ui_login.h"

class Clogin:public QDialog, public Ui_login
{
    Q_OBJECT
public:
    Clogin(QWidget * parrent = NULL, Qt::WindowFlags f = 0);
public slots:
    void on_bt_login_clicked();
    void on_bt_logincancel_clicked();
signals:
    void send_signal();
};

#endif
