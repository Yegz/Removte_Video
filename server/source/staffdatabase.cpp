#include "staffdatabase.h"

QVector<Cstaff> Cstaffdatabase::Staff_list;   // 静态指针变量初始化
QSqlDatabase db;

void Database_Connection(void)
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("Systemmanger");
    db.setUserName("root");
    db.setPassword("ygz");

    if(!db.open())
    {
        qDebug()<<"Unable to open database!";
    }
    else
    {
        qDebug()<<"Database connection established!";
    }
}

int Database_Size(void)
{
    int counter;

    QSqlQuery query;

    query.exec(QObject::tr("select * from Systemmanger"));
    QSqlRecord rec = query.record();
    counter = rec.count();

   // query.clear();

    return counter;
}
