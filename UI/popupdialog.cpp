#include "popupdialog.hpp"
#include "UI/ripplebutton.hpp"

PopUpDialog::PopUpDialog(QWidget *parent, QWidget *m_dialog)
    : QDialog(parent)
    , dialog(m_dialog)
{
    QGraphicsBlurEffect *blur = new QGraphicsBlurEffect;
    parent->setGraphicsEffect(blur);

    this->setParent(parent->window());
    this->setFixedSize(parent->width(), parent->height());

    parent->setStyleSheet("background-color: rgba(0,0,0,200)");
    dialog->move((this->width() / 2) - (dialog->width() / 2), parent->height());
    connect(this, &PopUpDialog::windowResized, this, [=]() { dialog->move(getCenter()); });

    QPointer<QPropertyAnimation> a = new QPropertyAnimation();
    a->setEasingCurve(QEasingCurve::OutBack);
    a->setDuration(500);
    a->setTargetObject(dialog);
    a->setPropertyName("pos");
    a->setStartValue(QPoint((dialog->parentWidget()->width() / 2) - (dialog->width() / 2),
                            dialog->parentWidget()->height()));
    a->setEndValue(getCenter());
    a->start(QAbstractAnimation::DeleteWhenStopped);
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

void PopUpDialog::showMessage(const QString &message, QWidget *parent)
{
    QDialog *fade = new QDialog();
    fade->setParent(parent->window());
    fade->setGeometry(0, 30, parent->width(), parent->height());
    fade->setStyleSheet("background-color: rgba(0,0,0,150);");

    QMessageBox *m = new QMessageBox();
    m->setParent(fade);
    m->setStyleSheet(
        "QLabel{color: #000000; height: 200px; min-height: 200px; width: 300px; font-size: 24px;"
        "min-width: 300px;} QWidget{ "
        "background-color: rgb(255,255,255); border-radius: 15px;}");
    m->setText(message);
    m->setStandardButtons(QMessageBox::NoButton);
    m->setFixedSize(300, 200);

    RippleButton *b = new RippleButton("Ok", m);
    b->setFixedSize(100, 35);
    b->move(m->width() - b->width() + 10, m->height() - b->height() + 10);
    qDebug() << m->size();
    b->setStyleSheet("background-color: rgb(200,200,200); color: #000000; border-radius: 15px;");

    m->show();

    QPoint startPoint = QPoint((m->parentWidget()->width() / 2) - (m->width() / 2),
                               m->parentWidget()->height());
    QPoint endPoint = QPoint((m->parentWidget()->width() / 2) - (m->width() / 2),
                             (m->parentWidget()->height() / 2) - (m->height() / 2));
    int duration = 500;

    QPointer<QPropertyAnimation> a = new QPropertyAnimation();
    a->setEasingCurve(QEasingCurve::OutBack);
    a->setDuration(duration);
    a->setTargetObject(m);
    a->setPropertyName("pos");
    a->setStartValue(startPoint);
    a->setEndValue(endPoint);
    a->start();

    fade->show();

    connect(b, &RippleButton::clicked, m, [=]() {
        a->setStartValue(endPoint);
        a->setEndValue(QPoint((m->parentWidget()->width() / 2) - (m->width() / 2), -m->height()));
        a->setEasingCurve(QEasingCurve::InBack);
        a->start();

        QTimer::singleShot(duration + 50, m, [=]() {
            m->setParent(nullptr);
            delete b;
            delete m;
            delete fade;
        });
    });
}

void PopUpDialog::resizeEvent(QResizeEvent *event)
{
    QDialog::resizeEvent(event);
    emit windowResized();
}

void PopUpDialog::closeEvent(QCloseEvent *event)
{
    QDialog::closeEvent(event);
}
