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
    // 判断用户名和密码是否正确
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
                    lineEdit_account->clear();  // 清空账户输入框
                    lineEdit_pwd->clear();
                    lineEdit_account->setFocus();
                    break;
                }
                else
                {
                    // 如果密码不正确，则弹出密码错误提示框
                    QMessageBox::warning(this, QObject::tr("警告"), tr("对不起，您输入的密码不正确，请重新输入!"), QMessageBox::Yes);
                    lineEdit_pwd->clear();    // 清空密码输入框
                    lineEdit_pwd->setFocus();
                    break;
                }
            }
            else if((i+1) != Cstaffdatabase::Staff_list.size())
                continue;
            else
            {
                // 如果输入账号不存在，则弹出账号不存在错误提示
                QMessageBox::warning(this, QObject::tr("警告"), QObject::tr("对不起，您输入的帐号不存在，请重新输入!"), QMessageBox::Yes);
                lineEdit_account->clear();  // 清空账户输入框
                lineEdit_pwd->clear();
                lineEdit_account->setFocus();
            }
        }
    }
    else
    {
        QString account = "1";
        QString pwd = "y";
        QMessageBox::information(this, QObject::tr("信息"), QObject::tr("当前不存在成员信息，请登入后先添加成员信息!"), QMessageBox::Yes);
        if(lineEdit_account->text().trimmed() == account)
        {
            if(lineEdit_pwd->text().trimmed() == pwd)
            {
                accept();           // Hides the modal dialog and sets the result code to Accepted.
                lineEdit_account->clear();  // 清空账户输入框
                lineEdit_pwd->clear();
                lineEdit_account->setFocus();
            }
            else
            {
                // 如果密码不正确，则弹出密码错误提示框
                QMessageBox::warning(this, QObject::tr("警告"), QObject::tr("对不起，您输入的密码不正确，请重新输入!"), QMessageBox::Yes);
                lineEdit_pwd->clear();    // 清空密码输入框
                lineEdit_pwd->setFocus();
            }
        }
        else
        {
            // 如果输入账号不存在，则弹出账号不存在错误提示
            QMessageBox::warning(this, QObject::tr("警告"), QObject::tr("对不起，您输入的帐号不存在，请重新输入!"), QMessageBox::Yes);
            lineEdit_account->clear();  // 清空账户输入框
            lineEdit_pwd->clear();
            lineEdit_account->setFocus();
        }
    }
}

void Clogin::on_bt_logincancel_clicked()
{
    close();
}


