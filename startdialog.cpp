#include "startdialog.hpp"
#include "ui_startdialog.h"

StartDialog::StartDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StartDialog)
{
    ui->setupUi(this);

    this->setGeometry(0, 30, parent->width(), parent->height());
    dialog = new PopUpDialog(this, ui->dialog);
}

StartDialog::~StartDialog()
{
    delete ui;
}

void StartDialog::on_pushButton_clicked()
{
    dialog->close(this);
}
