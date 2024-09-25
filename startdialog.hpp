#ifndef STARTDIALOG_HPP
#define STARTDIALOG_HPP

#include <QDialog>
#include "UI/popupdialog.hpp"

namespace Ui {
class StartDialog;
}

class StartDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StartDialog(QWidget *parent = nullptr);
    ~StartDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::StartDialog *ui;
    PopUpDialog *dialog;
};

#endif // STARTDIALOG_HPP
