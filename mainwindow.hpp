#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <windows.h>

#include "popupdialog.hpp"
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
    void on_openSideBarBT_clicked();

private:
    Ui::MainWindow *ui;
    QWinWidget win;
    QSqlQueryModel model;
};
#endif // MAINWINDOW_HPP
