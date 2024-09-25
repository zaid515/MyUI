#ifndef POPUPDIALOG_HPP
#define POPUPDIALOG_HPP

#include <QDialog>
#include <QPalette>
#include <QPointer>
#include <QPropertyAnimation>
#include <QWidget>

class PopUpDialog : public QDialog
{
    Q_OBJECT
public:
    explicit PopUpDialog(QWidget *parent = nullptr,QWidget *m_dialog = nullptr)
        : QDialog(parent)
        , dialog(m_dialog)
    {
        this->setParent(parent->window());
        this->setFixedSize(parent->width(), parent->height());

        parent->setStyleSheet("background-color: rgba(0,0,0,200)");
        dialog->move((this->width() / 2) - (dialog->width() / 2), parent->height());
        connect(this, &PopUpDialog::windowResized, this, [=]() { dialog->move(centerDialog()); });

        QPointer<QPropertyAnimation> a = new QPropertyAnimation();
        a->setEasingCurve(QEasingCurve::OutQuad);
        a->setDuration(1000);
        a->setTargetObject(dialog);
        a->setPropertyName("pos");
        a->setStartValue(QPoint((dialog->parentWidget()->width() / 2) - (dialog->width() / 2),
                                dialog->parentWidget()->height()));
        a->setEndValue(centerDialog());
        a->start();
        /*connect(animation, &QPropertyAnimation::valueChanged, this, [=]() {
            dialog->parentWidget()->update();
            dialog->update();
        });
        connect(animation, &QPropertyAnimation::finished, this, [=]() { delete animation; });*/
    }

    ~PopUpDialog() {}

    inline QPoint centerDialog()
    {
        return QPoint((this->parentWidget()->width() / 2) - (dialog->width() / 2),
                      (this->parentWidget()->height() / 2) - (dialog->height() / 2));
    }
    inline void showMessage(const QString &message) { Q_UNUSED(message) }
    inline void close(QWidget *widget = nullptr) { Q_UNUSED(widget) }

protected:
    inline void resizeEvent(QResizeEvent *) override { emit windowResized(); }

private:
    QWidget *dialog;
    QWidget *fadeWidget;

signals:
    void windowResized();
    void opacityChanged();
    void openAnimat();
};

#endif // POPUPDIALOG_HPP
