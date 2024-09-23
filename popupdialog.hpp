#ifndef POPUPDIALOG_HPP
#define POPUPDIALOG_HPP

#include <QDialog>
#include <QPropertyAnimation>
#include <QWidget>
#include <QWindow>

namespace Ui {
class PopUpDialog;
}

class PopUpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PopUpDialog(QWidget *parent = nullptr);
    ~PopUpDialog();
    QPoint centerDialog();
    void showMessage(const QString &message);

private:
    Ui::PopUpDialog *ui;

signals:
    void resizeEvent(QResizeEvent *) override;
private slots:
    void on_pushButton_clicked();
};

#endif // POPUPDIALOG_HPP
