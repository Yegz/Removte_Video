#ifndef  SYSTEM_INIT__H
#define  SYSTEM_INIT__H

#include <QSqlDatabase>
#include <QtSql>
#include <QSqlQuery>
#include <QSettings>
#include <QVariant>
#include <QString>
#include <QStringList>
#include <QDebug>
#include "debug.h"
#include "staffdatabase.h"

extern QSqlDatabase db;

void System_Init();

#endif
