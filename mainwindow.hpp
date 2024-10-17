#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QMovie>
#include <QPointer>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <windows.h>

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

private:
    Ui::MainWindow *ui;
    QWinWidget win;
    QSqlQueryModel model;

signals:
    void sizeChanged();
private slots:
    void on_pushButton_6_clicked();
};
#endif // MAINWINDOW_HPP
