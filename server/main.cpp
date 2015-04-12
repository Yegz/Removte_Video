#include <QApplication>
#include <QTextCodec>
#include "system_init.h"
#include "login.h"
#include "video.h"
#include "debug.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("gb2312"));
    Clogin lg;

    System_Init();
    if(lg.exec()==QDialog::Accepted)
    {
        Widget video;

        video.show();

        return app.exec();
    }
    else
        return 0;
}
