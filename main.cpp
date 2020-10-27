#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //DnD?
    MainWindow w;
    w.show();
    return a.exec();
}
