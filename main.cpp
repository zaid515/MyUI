#include "mainwindow.hpp"

#include <QApplication>
#include "title_bar/QWinWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QWinWidget winWidget(w.parentWidget());
    winWidget.setGeometry(w.geometry().x(),
                          w.geometry().y(),
                          w.geometry().width(),
                          w.geometry().height());
    winWidget.show();
    w.show();
    return a.exec();
}
