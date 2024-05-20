#include "mainwindow.h"
#include "log_in.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    log_in log_in;
    log_in.exec();

    return a.exec();
}
