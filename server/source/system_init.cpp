#include "system_init.h"

void System_Init()
{
    int size;
    int staff_sid;
    int staff_name;
    int staff_password;
    int staff_type;
    int staff_remark;
    QSqlQuery query;
    QSqlRecord rec;
    int i = 0;

    Database_Connection();
    query.exec(QObject::tr("select * from Systemmanger"));
    rec = query.record();
    size = rec.count();
    plog("The database size = %d\n", size);

    Cstaffdatabase::Staff_list.resize(size);

    while(query.next() && size != 0)
    {
        rec = query.record();                                                      // 返回该列的索引
        staff_sid = rec.indexOf("sid");
        staff_name = rec.indexOf("name");
        staff_password = rec.indexOf("password");
        staff_type = rec.indexOf("type");
        staff_remark = rec.indexOf("remark");

        Cstaffdatabase::Staff_list[i].id = query.value(staff_sid).toString();      // 获取该列的值
        Cstaffdatabase::Staff_list[i].name = query.value(staff_name).toString();
        Cstaffdatabase::Staff_list[i].pwd = query.value(staff_password).toString();
        Cstaffdatabase::Staff_list[i].sort = query.value(staff_type).toString();

        qDebug()<<__func__<<"    "<<Cstaffdatabase::Staff_list[i].id;
        qDebug()<<__func__<<"    "<<Cstaffdatabase::Staff_list[i].name;
        qDebug()<<__func__<<"    "<<Cstaffdatabase::Staff_list[i].pwd;
        qDebug()<<__func__<<"    "<<Cstaffdatabase::Staff_list[i].sort;
    }

    query.clear();
    db.close();
}
