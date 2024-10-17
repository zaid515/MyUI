#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include "UI/settings.hpp"
#include "UI/theme.hpp"
#include "startdialog.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //init win32 window and link Qt window with win32 window
    this->setParent(win.window());
    win.setGeometry(this->geometry());
    this->setGeometry(0, 30, this->geometry().width(), this->geometry().height());
    connect(&win, &QWinWidget::sizeChanged, this, [=]() { this->resize(win.size()); });
    win.show();

    //apply theme
    Theme::Get().init();
    this->setStyleSheet(Theme::Get().mainWindow);

    //ui stuff
    ui->widget->setOpenButtton(ui->billBt);
    ui->widget->setFixedWidth(200);
    ui->widget->setLayout(MyUI::Layout::Vertical);
    ui->widget->setOpenDirction(MyUI::OpenDirction::ToRight);
    ui->billBt->setRippleColor(QColor(33, 150, 243, 240));
    ui->lineEdit_3->setTextMargins(8, 0, 0, 0);

    connect(ui->checkBox, &QCheckBox::checkStateChanged, this, [=]() {
        if (ui->checkBox->isChecked()) {
            Settings::write("Settings.ini", "DarkThemeEnabled", 1);
        } else {
            Settings::write("Settings.ini", "DarkThemeEnabled", 0);
        }
        Theme::Get().init();
        this->setStyleSheet(Theme::Get().mainWindow);
    });

    /*QSqlDatabase database = QSqlDatabase::addDatabase("QPSQL");
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
    }*/

    connect(ui->openSideBarBT, &RippleButton::clicked, this, [=]() {
        //dialog
        StartDialog *d = new StartDialog(this);
        connect(&win, &QWinWidget::sizeChanged, this, [=]() { d->resize(win.size()); });
        d->exec();
    });
}

MainWindow::~MainWindow()
{
    this->setParent(nullptr);
    delete ui;
}

void MainWindow::on_pushButton_6_clicked()
{
    ///modern message box
    PopUpDialog::showMessage("message...", this);
}
