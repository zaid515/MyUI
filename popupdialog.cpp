#include "popupdialog.hpp"
#include "ui_popupdialog.h"

PopUpDialog::PopUpDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PopUpDialog)
{
    ui->setupUi(this);
    this->setParent(parent->window());
    this->setGeometry(0, 30, parent->width(), parent->height());
    centerDialog();
    connect(this, &PopUpDialog::resizeEvent, this, &PopUpDialog::centerDialog);

    QPropertyAnimation *a = new QPropertyAnimation(ui->dialog, "pos", this);
    a->setEasingCurve(QEasingCurve::OutQuad);
    a->setDuration(250);
    a->setStartValue(QPoint((this->width() / 2) - (ui->dialog->width() / 2), this->height()));
    a->setEndValue(centerDialog());
    a->start();
}

PopUpDialog::~PopUpDialog()
{
    delete ui;
}

QPoint PopUpDialog::centerDialog()
{
    qDebug() << this->parentWidget()->height();
    return QPoint((this->parentWidget()->width() / 2) - (ui->dialog->width() / 2),
                  (this->parentWidget()->height() / 2) - (ui->dialog->height() / 2));
}

void PopUpDialog::showMessage(const QString &message) {}

void PopUpDialog::on_pushButton_clicked()
{
    QPropertyAnimation *an = new QPropertyAnimation(ui->dialog, "pos", this);
    an->setEasingCurve(QEasingCurve::OutQuad);
    an->setDuration(250);
    an->setEndValue(QPoint((this->width() / 2) - (ui->dialog->width() / 2), -ui->dialog->height()));
    an->setStartValue(centerDialog());
    an->start();

    connect(an, &QPropertyAnimation::finished, this, [=]() { this->close(); });
}
