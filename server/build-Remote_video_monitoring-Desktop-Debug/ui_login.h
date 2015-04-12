/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created: Sat Feb 28 22:25:11 2015
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_account;
    QLineEdit *lineEdit_account;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_pwd;
    QLineEdit *lineEdit_pwd;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *bt_login;
    QSpacerItem *horizontalSpacer;
    QPushButton *bt_logincancel;
    QLabel *label;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QString::fromUtf8("login"));
        login->setWindowModality(Qt::ApplicationModal);
        login->resize(862, 565);
        QFont font;
        font.setPointSize(38);
        login->setFont(font);
        login->setFocusPolicy(Qt::NoFocus);
        login->setContextMenuPolicy(Qt::NoContextMenu);
        login->setStyleSheet(QString::fromUtf8("#login{	\n"
"	background-image: url(:/images/images/bj.jpg);\n"
"	\n"
"}\n"
"#login * {\n"
"background-image: url();\n"
"}"));
        login->setInputMethodHints(Qt::ImhNone);
        layoutWidget = new QWidget(login);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(400, 250, 203, 126));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_account = new QLabel(layoutWidget);
        label_account->setObjectName(QString::fromUtf8("label_account"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_account->sizePolicy().hasHeightForWidth());
        label_account->setSizePolicy(sizePolicy);
        label_account->setStyleSheet(QString::fromUtf8("font: 12pt \"Song Ti\";"));
        label_account->setFrameShape(QFrame::WinPanel);
        label_account->setFrameShadow(QFrame::Sunken);
        label_account->setTextFormat(Qt::RichText);

        horizontalLayout->addWidget(label_account);

        lineEdit_account = new QLineEdit(layoutWidget);
        lineEdit_account->setObjectName(QString::fromUtf8("lineEdit_account"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_account->sizePolicy().hasHeightForWidth());
        lineEdit_account->setSizePolicy(sizePolicy1);
        lineEdit_account->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(lineEdit_account);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_pwd = new QLabel(layoutWidget);
        label_pwd->setObjectName(QString::fromUtf8("label_pwd"));
        sizePolicy.setHeightForWidth(label_pwd->sizePolicy().hasHeightForWidth());
        label_pwd->setSizePolicy(sizePolicy);
        label_pwd->setStyleSheet(QString::fromUtf8("font: 12pt \"Song Ti\";"));
        label_pwd->setFrameShape(QFrame::StyledPanel);
        label_pwd->setFrameShadow(QFrame::Sunken);
        label_pwd->setTextFormat(Qt::RichText);

        horizontalLayout_2->addWidget(label_pwd);

        lineEdit_pwd = new QLineEdit(layoutWidget);
        lineEdit_pwd->setObjectName(QString::fromUtf8("lineEdit_pwd"));
        sizePolicy1.setHeightForWidth(lineEdit_pwd->sizePolicy().hasHeightForWidth());
        lineEdit_pwd->setSizePolicy(sizePolicy1);
        lineEdit_pwd->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(lineEdit_pwd);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        bt_login = new QPushButton(layoutWidget);
        bt_login->setObjectName(QString::fromUtf8("bt_login"));
        sizePolicy.setHeightForWidth(bt_login->sizePolicy().hasHeightForWidth());
        bt_login->setSizePolicy(sizePolicy);
        bt_login->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 255);"));

        horizontalLayout_3->addWidget(bt_login);

        horizontalSpacer = new QSpacerItem(17, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        bt_logincancel = new QPushButton(layoutWidget);
        bt_logincancel->setObjectName(QString::fromUtf8("bt_logincancel"));
        sizePolicy.setHeightForWidth(bt_logincancel->sizePolicy().hasHeightForWidth());
        bt_logincancel->setSizePolicy(sizePolicy);
        bt_logincancel->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 255);"));

        horizontalLayout_3->addWidget(bt_logincancel);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 1);

        label = new QLabel(login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(400, 230, 121, 21));
        label->setStyleSheet(QString::fromUtf8("\n"
"font: 12pt \"\346\226\260\345\256\213\344\275\223\";"));

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QApplication::translate("login", "\350\277\234\347\250\213\350\247\206\351\242\221\347\233\221\346\216\247\347\263\273\347\273\237\347\231\273\345\205\245\347\225\214\351\235\242", 0, QApplication::UnicodeUTF8));
        label_account->setText(QApplication::translate("login", "\350\264\246\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_pwd->setText(QApplication::translate("login", "\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        bt_login->setText(QApplication::translate("login", "\347\231\273\345\205\245", 0, QApplication::UnicodeUTF8));
        bt_logincancel->setText(QApplication::translate("login", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("login", "\347\224\250 \346\210\267 \347\231\273 \345\205\245 ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
