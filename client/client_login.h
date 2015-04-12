#ifndef CLIENT_LOGIN__H_
#define CLIENT_LOGIN__H_

#include "ui_login.h"
#include "c_socket.h"

extern client_config_t g_cfg_client;

class Clogin:public QDialog, public Ui_Client_Login
{
    Q_OBJECT
public:
    Clogin(QWidget * parrent = NULL, Qt::WindowFlags f = 0);
public slots:
    void on_Button_Login_clicked();
    void on_Button_Cancle_clicked();
};

#endif
