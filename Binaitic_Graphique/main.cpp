#include "mainwindow.h"
#include "qstd.h"
#include "evolutionprocess.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
