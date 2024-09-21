#include "mainwindow.hpp"

#include <QApplication>
///#include "title_bar/QWinWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
