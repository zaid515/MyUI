#ifndef POPUPDIALOG_HPP
#define POPUPDIALOG_HPP

#include <QDialog>
#include <QGraphicsEffect>
#include <QMessageBox>
#include <QPointer>
#include <QPropertyAnimation>
#include <QTimer>

class PopUpDialog : public QDialog
{
    Q_OBJECT
public:
    explicit PopUpDialog(QWidget *parent = nullptr, QWidget *m_dialog = nullptr);
    ~PopUpDialog() {}
    QPoint getCenter();
    void centerDialog();
    static void showMessage(const QString &message, QWidget *parent);

protected:
    void resizeEvent(QResizeEvent *event) override;
    void closeEvent(QCloseEvent *event) override;

private:
    QWidget *dialog;
    QWidget *fadeWidget;

signals:
    void windowResized();
};

#endif // POPUPDIALOG_HPP
