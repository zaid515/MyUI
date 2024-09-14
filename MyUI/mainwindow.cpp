#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    b = new RippleButton(this);
    b->setText("zaid");
    b->setRippleColor(QColor(155, 155, 155));
    b->setFixedSize(200, 200);
    b->setStyleSheet("background-color: rgb(0, 0, 0);color: rgb(225, 255, 33);");
    b->show();

    QPushButton *p = new RippleButton(this);
    p->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    delete b;
}
