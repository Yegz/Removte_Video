#ifndef  STAFFDATABASE__H
#define STAFFDATABASE__H

#include <QSqlDatabase>
#include <QtSql>
#include <QSqlQuery>
#include <QString>
#include <QVector>
#include "debug.h"

/**************************************        函数声明        ***********************************************/
void Database_Connection(void);
int Database_Size(void);

class Cstaff
{
public:
    QString  id;          // 账户的
    QString  name;        // 账户昵称
    QString  pwd;         // 账户密码
    QString  sort;        // 账户级别
};

class Cstaffdatabase
{
public:
    static QVector<Cstaff> Staff_list;  // 声明一个指向Cstaff类的链表指针变量
};

#endif
