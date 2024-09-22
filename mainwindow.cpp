#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <windows.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setRippleColor(Qt::lightGray);
    ui->widget->setOpenButtton(ui->openSideBarBT);
    ui->widget->setLayout(MyUI::Layout::Vertical);
    ui->widget->setOpenDirction(MyUI::OpenDirction::ToRight);

    this->setParent(win.window());
    win.setGeometry(this->geometry());
    this->setGeometry(0, 30, this->geometry().width(), this->geometry().height());
    connect(&win, &QWinWidget::resizeEvent, this, [=]() { this->resize(win.size()); });
    win.show();
}

MainWindow::~MainWindow()
{
    this->setParent(nullptr);
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->widget->openSideBar();
}

void MainWindow::on_openSideBarBT_clicked() {}
