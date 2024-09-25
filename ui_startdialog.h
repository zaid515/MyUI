/********************************************************************************
** Form generated from reading UI file 'startdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTDIALOG_H
#define UI_STARTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QWidget>
#include "UI/ripplebutton.hpp"

QT_BEGIN_NAMESPACE

class Ui_StartDialog
{
public:
    QWidget *dialog;
    RippleButton *pushButton;

    void setupUi(QDialog *StartDialog)
    {
        if (StartDialog->objectName().isEmpty())
            StartDialog->setObjectName("StartDialog");
        StartDialog->resize(801, 569);
        StartDialog->setStyleSheet(QString::fromUtf8(""));
        dialog = new QWidget(StartDialog);
        dialog->setObjectName("dialog");
        dialog->setGeometry(QRect(210, 150, 371, 221));
        dialog->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius: 15px;\n"
""));
        pushButton = new RippleButton(dialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(270, 170, 91, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sans Serif Collection")});
        font.setPointSize(15);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: rgb(255,255,255);\n"
"	color: #000000;\n"
"	border-radius: 10px;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton::hover\n"
"{\n"
"	background-color: rgb(215,215,215);\n"
"	color: #000000;\n"
"	border-radius: 10px;\n"
"	padding: 5px;\n"
"}"));

        retranslateUi(StartDialog);

        QMetaObject::connectSlotsByName(StartDialog);
    } // setupUi

    void retranslateUi(QDialog *StartDialog)
    {
        StartDialog->setWindowTitle(QCoreApplication::translate("StartDialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("StartDialog", "create", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartDialog: public Ui_StartDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTDIALOG_H
