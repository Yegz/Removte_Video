#include "login.h"
#include "staffdatabase.h"

Clogin::Clogin(QWidget * parrent, Qt::WindowFlags f)
    :QDialog(parrent, f = Qt::WindowMinimizeButtonHint)
{
    setupUi(this);
    lineEdit_pwd->setEchoMode(QLineEdit::Password);
}

void Clogin::on_bt_login_clicked()
{
    // �ж��û����������Ƿ���ȷ
    int i;
    if(Cstaffdatabase::Staff_list.size() != 0)
    {
        for(i=0; i<Cstaffdatabase::Staff_list.size(); i++)
        {
            if(lineEdit_account->text().trimmed() == Cstaffdatabase::Staff_list[i].name)
            {
                if(lineEdit_pwd->text().trimmed() == Cstaffdatabase::Staff_list[i].pwd)
                {
                    accept();           // Hides the modal dialog and sets the result code to Accepted.
                    emit send_signal();
                    lineEdit_account->clear();  // ����˻������
                    lineEdit_pwd->clear();
                    lineEdit_account->setFocus();
                    break;
                }
                else
                {
                    // ������벻��ȷ���򵯳����������ʾ��
                    QMessageBox::warning(this, QObject::tr("����"), tr("�Բ�������������벻��ȷ������������!"), QMessageBox::Yes);
                    lineEdit_pwd->clear();    // ������������
                    lineEdit_pwd->setFocus();
                    break;
                }
            }
            else if((i+1) != Cstaffdatabase::Staff_list.size())
                continue;
            else
            {
                // ��������˺Ų����ڣ��򵯳��˺Ų����ڴ�����ʾ
                QMessageBox::warning(this, QObject::tr("����"), QObject::tr("�Բ�����������ʺŲ����ڣ�����������!"), QMessageBox::Yes);
                lineEdit_account->clear();  // ����˻������
                lineEdit_pwd->clear();
                lineEdit_account->setFocus();
            }
        }
    }
    else
    {
        QString account = "1";
        QString pwd = "y";
        QMessageBox::information(this, QObject::tr("��Ϣ"), QObject::tr("��ǰ�����ڳ�Ա��Ϣ������������ӳ�Ա��Ϣ!"), QMessageBox::Yes);
        if(lineEdit_account->text().trimmed() == account)
        {
            if(lineEdit_pwd->text().trimmed() == pwd)
            {
                accept();           // Hides the modal dialog and sets the result code to Accepted.
                lineEdit_account->clear();  // ����˻������
                lineEdit_pwd->clear();
                lineEdit_account->setFocus();
            }
            else
            {
                // ������벻��ȷ���򵯳����������ʾ��
                QMessageBox::warning(this, QObject::tr("����"), QObject::tr("�Բ�������������벻��ȷ������������!"), QMessageBox::Yes);
                lineEdit_pwd->clear();    // ������������
                lineEdit_pwd->setFocus();
            }
        }
        else
        {
            // ��������˺Ų����ڣ��򵯳��˺Ų����ڴ�����ʾ
            QMessageBox::warning(this, QObject::tr("����"), QObject::tr("�Բ�����������ʺŲ����ڣ�����������!"), QMessageBox::Yes);
            lineEdit_account->clear();  // ����˻������
            lineEdit_pwd->clear();
            lineEdit_account->setFocus();
        }
    }
}

void Clogin::on_bt_logincancel_clicked()
{
    close();
}


