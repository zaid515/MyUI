#include "popupdialog.hpp"

PopUpDialog::PopUpDialog(QWidget *parent, QWidget *m_dialog)
    : QDialog(parent)
    , dialog(m_dialog)
{
    this->setParent(parent->window());
    this->setFixedSize(parent->width(), parent->height());

    parent->setStyleSheet("background-color: rgba(0,0,0,200)");
    dialog->move((this->width() / 2) - (dialog->width() / 2), parent->height());
    connect(this, &PopUpDialog::windowResized, this, [=]() { dialog->move(getCenter()); });

    QGraphicsOpacityEffect e;
    e.setOpacity(0);
    parent->setGraphicsEffect(&e);

    QPointer<QPropertyAnimation> a = new QPropertyAnimation();
    a->setEasingCurve(QEasingCurve::OutBack);
    a->setDuration(500);
    a->setTargetObject(dialog);
    a->setPropertyName("pos");
    a->setStartValue(QPoint((dialog->parentWidget()->width() / 2) - (dialog->width() / 2),
                            dialog->parentWidget()->height()));
    a->setEndValue(getCenter());
    a->start();
    connect(a, &QPropertyAnimation::finished, this, [=]() { delete a; });
}

QPoint PopUpDialog::getCenter()
{
    return QPoint((this->parentWidget()->width() / 2) - (dialog->width() / 2),
                  (this->parentWidget()->height() / 2) - (dialog->height() / 2));
}

void PopUpDialog::centerDialog()
{
    dialog->move(getCenter());
}

void PopUpDialog::showMessage(const QString &message)
{
    Q_UNUSED(message)
}

void PopUpDialog::resizeEvent(QResizeEvent *)
{
    emit windowResized();
}
