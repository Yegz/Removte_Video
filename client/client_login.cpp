#include "client_login.h"

Clogin::Clogin(QWidget * parrent, Qt::WindowFlags f)
    :QDialog(parrent, f = Qt::WindowMinimizeButtonHint)
{
    setupUi(this);

}

void Clogin::on_Button_Login_clicked()
{
    QString client_ip;
    QString client_port;
    QByteArray tmp;

    client_ip = lineEdit_ip->text().trimmed();
    client_port = lineEdit_port->text().trimmed();
    strcpy(g_cfg_client.ser_ip, client_ip.toLatin1().data());
    g_cfg_client.ser_port = client_port.toInt();

    plog("The client_ip: %s\n", g_cfg_client.ser_ip);
    plog("The client_port : %d\n", g_cfg_client.ser_port);

    accept();
}

void Clogin::on_Button_Cancle_clicked()
{
    close();
}
