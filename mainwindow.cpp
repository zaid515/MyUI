#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setRippleColor(Qt::lightGray);
    ui->widget->setOpenButtton(ui->openSideBarBT);
    ui->widget->setLayout(MyUI::Layout::Vertical);
    ui->widget->setOpenDirction(MyUI::OpenDirction::ToRight);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->widget->openSideBar();
}
