#ifndef POPUPDIALOG_HPP
#define POPUPDIALOG_HPP

#include <QDialog>
#include <QGraphicsEffect>
#include <QPointer>
#include <QPropertyAnimation>

class PopUpDialog : public QDialog
{
    Q_OBJECT
public:
    explicit PopUpDialog(QWidget *parent = nullptr, QWidget *m_dialog = nullptr);
    ~PopUpDialog() {}
    QPoint getCenter();
    void centerDialog();
    void showMessage(const QString &message);

protected:
    void resizeEvent(QResizeEvent *) override;

private:
    QWidget *dialog;
    QWidget *fadeWidget;

signals:
    void windowResized();
};

#endif // POPUPDIALOG_HPP
