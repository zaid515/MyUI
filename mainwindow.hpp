#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QPointer>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <iostream>
#include <windows.h>

#include "startdialog.hpp"
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

signals:
    void sizeChanged();
};
#endif // MAINWINDOW_HPP
