#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //根据不同QT版本编译,在QT5以下版本中需要设置为UTF-8编码才能正常显示中文
    #if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
        QTextCodec *codec=QTextCodec::codecForName("UTF-8");
        QTextCodec::setCodecForLocale(codec);
        QTextCodec::setCodecForCStrings(codec);
        QTextCodec::setCodecForTr(codec);
    #endif

    MainWindow w;
    w.show();

    return a.exec();
}
