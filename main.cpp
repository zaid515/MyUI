#include "mainwindow.hpp"

#include <QApplication>
#include "firststartprogram.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

#if 1
    FirstStartProgram p;
    p.show();
#endif

    return a.exec();
}
