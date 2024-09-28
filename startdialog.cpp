#include "startdialog.hpp"
#include "ui_startdialog.h"

StartDialog::StartDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StartDialog)
{
    ui->setupUi(this);

    this->setGeometry(0, 30, parent->width(), parent->height());
    dialog = new PopUpDialog(this, ui->dialog);
    this->setParent(parent->window());
}

StartDialog::~StartDialog()
{
    delete ui;
}

void StartDialog::resizeEvent(QResizeEvent *event)
{
    QDialog::resizeEvent(event);
    dialog->centerDialog();
}

void StartDialog::on_pushButton_clicked()
{
    this->close();
}
