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

    ui->openSideBarBT->setRippleColor(Qt::lightGray);

    this->setParent(win.window());
    win.setGeometry(this->geometry());
    this->setGeometry(0, 30, this->geometry().width(), this->geometry().height());
    connect(&win, &QWinWidget::sizeChanged, this, [=]() { this->resize(win.size()); });
    win.show();

    QSqlDatabase database = QSqlDatabase::addDatabase("QPSQL");
    database.setUserName("postgres");
    database.setPassword("zqid45mroot");
    database.setDatabaseName("postgres");
    database.setHostName("localhost");

    if (database.open()) {
        qDebug() << "database opened";
        model.setQuery("SELECT * FROM products_tb");
        ui->tableView->setModel(&model);
        ui->tableView->show();
    } else {
        qDebug() << "database not open";
    }
}

MainWindow::~MainWindow()
{
    this->setParent(nullptr);
    delete ui;
}

void MainWindow::on_openSideBarBT_clicked()
{
    win.onMaximizeButtonClicked();
    StartDialog *d = new StartDialog(this);
    connect(&win, &QWinWidget::sizeChanged, this, [=]() { d->resize(win.size()); });
    d->show();
}
