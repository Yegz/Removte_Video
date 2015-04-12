/********************************************************************************
** Form generated from reading UI file 'Video_Play.ui'
**
** Created: Sat Feb 28 22:25:11 2015
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEO_PLAY_H
#define UI_VIDEO_PLAY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_camara
{
public:
    QLabel *camera2;
    QLabel *camera1;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_1;
    QLCDNumber *lcdNumber_1;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLCDNumber *lcdNumber_2;

    void setupUi(QWidget *camara)
    {
        if (camara->objectName().isEmpty())
            camara->setObjectName(QString::fromUtf8("camara"));
        camara->resize(653, 351);
        camera2 = new QLabel(camara);
        camera2->setObjectName(QString::fromUtf8("camera2"));
        camera2->setGeometry(QRect(325, 0, 320, 240));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(camera2->sizePolicy().hasHeightForWidth());
        camera2->setSizePolicy(sizePolicy);
        camera1 = new QLabel(camara);
        camera1->setObjectName(QString::fromUtf8("camera1"));
        camera1->setGeometry(QRect(0, 0, 320, 240));
        sizePolicy.setHeightForWidth(camera1->sizePolicy().hasHeightForWidth());
        camera1->setSizePolicy(sizePolicy);
        widget = new QWidget(camara);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 250, 624, 27));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_1 = new QLabel(widget);
        label_1->setObjectName(QString::fromUtf8("label_1"));

        horizontalLayout->addWidget(label_1);

        lcdNumber_1 = new QLCDNumber(widget);
        lcdNumber_1->setObjectName(QString::fromUtf8("lcdNumber_1"));
        lcdNumber_1->setNumDigits(19);
        lcdNumber_1->setProperty("value", QVariant(2014));

        horizontalLayout->addWidget(lcdNumber_1);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(48, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lcdNumber_2 = new QLCDNumber(widget);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        lcdNumber_2->setNumDigits(19);
        lcdNumber_2->setProperty("value", QVariant(2014));

        horizontalLayout_2->addWidget(lcdNumber_2);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(camara);

        QMetaObject::connectSlotsByName(camara);
    } // setupUi

    void retranslateUi(QWidget *camara)
    {
        camara->setWindowTitle(QApplication::translate("camara", "Camara", 0, QApplication::UnicodeUTF8));
        camera2->setText(QString());
        camera1->setText(QString());
        label_1->setText(QApplication::translate("camara", "  \347\233\221\346\216\247\347\224\273\351\235\242\344\270\200:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("camara", "  \347\233\221\346\216\247\347\224\273\351\235\242\344\272\214:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class camara: public Ui_camara {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEO_PLAY_H
