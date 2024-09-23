#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "title_bar/QWinWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_openSideBarBT_clicked();

    void on_offofofoofo_clicked();

private:
    Ui::MainWindow *ui;
    QWinWidget win;
};
#endif // MAINWINDOW_HPP
