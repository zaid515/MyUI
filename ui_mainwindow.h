/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "UI/ripplebutton.hpp"
#include "UI/sidebar.hpp"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    RippleButton *openSideBarBT;
    SideBar *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_7;
    QPushButton *pushButton_5;
    RippleButton *pushButton;
    QPushButton *pushButton_4;
    QTableView *tableView;
    QWidget *widget_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1195, 663);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(221, 221, 221);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        openSideBarBT = new RippleButton(centralwidget);
        openSideBarBT->setObjectName("openSideBarBT");
        openSideBarBT->setGeometry(QRect(970, 130, 221, 111));
        openSideBarBT->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: rgb(35, 35, 35);\n"
"	color: #ffffff;\n"
"	border-style: solid;\n"
"	border-width: 1px;\n"
"	border-radius: 50px;\n"
"	border-color: rgb(35, 35, 35);\n"
"	padding: 5px;\n"
"	font: 15pt \"Microsoft Sans Serif\";\n"
"\n"
"}\n"
"\n"
"QPushButton::hover\n"
"{\n"
"	\n"
"	background-color: rgb(40,40,40);\n"
"	color: rgb(255,255,255);\n"
"	border-style: solid;\n"
"	border-radius: 50px;\n"
"	padding: 5px;\n"
"\n"
"}"));
        openSideBarBT->setIconSize(QSize(100, 60));
        openSideBarBT->setFlat(true);
        widget = new SideBar(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(-170, 0, 163, 661));
        widget->setMinimumSize(QSize(2, 2));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 4);"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMinimumSize(QSize(50, 100));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(35,35,35);\n"
"border-radius: 0px;"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_7 = new QPushButton(widget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setMinimumSize(QSize(50, 100));
        pushButton_7->setStyleSheet(QString::fromUtf8("background-color: rgb(35,35,35);\n"
"border-radius: 0px;"));

        verticalLayout->addWidget(pushButton_7);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setMinimumSize(QSize(50, 100));
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: rgb(35,35,35);\n"
"border-radius: 0px;"));

        verticalLayout->addWidget(pushButton_5);

        pushButton = new RippleButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(50, 100));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: rgb(35, 35, 35);\n"
"	color: #ffffff;\n"
"	padding: 5px;\n"
"	border-radius: 0px;\n"
"	font: 15pt \"Microsoft Sans Serif\";\n"
"}\n"
"\n"
"QPushButton::hover\n"
"{\n"
"	background-color: rgb(85, 85, 85);\n"
"	color: rgb(255,255,255);\n"
"	border-radius: 0px;\n"
"	padding: 5px;\n"
"}"));

        verticalLayout->addWidget(pushButton);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setMinimumSize(QSize(50, 100));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(35,35,35);\n"
"border-radius: 0px;\n"
""));

        verticalLayout->addWidget(pushButton_4);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(210, 30, 751, 631));
        tableView->setStyleSheet(QString::fromUtf8("QTableView\n"
"{\n"
"    \n"
"	background-color: rgb(35,35,35);\n"
"    border: 1px solid #32414B;\n"
"    color: rgb(255,255,255);\n"
"    gridline-color:  rgb(0,0,0);\n"
"    outline : 0;\n"
"}\n"
"\n"
"\n"
"QTableView::disabled\n"
"{\n"
"    background-color: #242526;\n"
"    border: 1px solid #32414B;\n"
"    color: #656565;\n"
"    gridline-color: #656565;\n"
"    outline : 0;\n"
"\n"
"}\n"
"\n"
"\n"
"QTableView::item:hover \n"
"{\n"
"    background-color: rgb(85,85,85);\n"
"    color: rgb(255,255,255);\n"
"\n"
"}\n"
"\n"
"\n"
"QTableView::item:selected \n"
"{\n"
"    background-color: rgb(0,0,0);\n"
"    border: 1px solid rgb(255,235,12);\n"
"    color: rgb(255,235,12);\n"
"\n"
"}\n"
"\n"
"\n"
"QTableView::item:selected:disabled\n"
"{\n"
"    background-color: #1a1b1c;\n"
"    border: 2px solid #525251;\n"
"    color: #656565;\n"
"\n"
"}\n"
"\n"
"\n"
"QTableCornerButton::section\n"
"{\n"
"	\n"
"	\n"
"    background-color: rgb(255,235,12);\n"
"    color: rgb(255,255,255);\n"
"\n"
"}\n"
"\n"
"\n"
"QHeaderV"
                        "iew::section\n"
"{\n"
"    background-color: rgb(255,235,12);\n"
"    color: rgb(0,0,0);\n"
"    text-align: left;\n"
"	padding: 4px;\n"
"	font: 12pt \"Segoe UI\";\n"
"}\n"
"\n"
"\n"
"QHeaderView::section:disabled\n"
"{\n"
"    background-color: rgb(0,0,0);\n"
"    color: #656565;\n"
"\n"
"}\n"
"\n"
"\n"
"QHeaderView::section:checked\n"
"{\n"
"	\n"
"	border-color: rgb(0, 0, 0);\n"
"    color: #fff;\n"
"    background-color:  rgb(25,25,25);\n"
"\n"
"}\n"
"\n"
"\n"
"QHeaderView::section:checked:disabled\n"
"{\n"
"    color: #656565;\n"
"    background-color: #525251;\n"
"\n"
"}\n"
"\n"
"\n"
"QHeaderView::section::vertical::first,\n"
"QHeaderView::section::vertical::only-one\n"
"{\n"
"    border-top: 1px solid #353635;\n"
"}\n"
"\n"
"\n"
"QHeaderView::section::vertical\n"
"{\n"
"    border-top: 1px solid #353635;\n"
"\n"
"}\n"
"\n"
"\n"
"QHeaderView::section::horizontal::first,\n"
"QHeaderView::section::horizontal::only-one\n"
"{\n"
"    border-left: 1px solid #353635;\n"
"\n"
"}\n"
"\n"
"\n"
"QHeaderView::sectio"
                        "n::horizontal\n"
"{\n"
"    border-left: 1px solid #353635;\n"
"\n"
"}\n"
"QScrollBar:vertical\n"
"{\n"
"    background-color: #3d3d3d;\n"
"    width: 13px;\n"
"	border-radius: 5px;\n"
"    margin: 16px 0 16px 0;\n"
"    border: 1px solid #222222;\n"
"\n"
"}\n"
"\n"
"\n"
"QScrollBar::handle:vertical\n"
"{\n"
"    background-color: rgb(255,235,12);\n"
"	width: 5px;\n"
"    min-height: 20px;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"\n"
"QScrollBar::add-line:vertical\n"
"{\n"
"   background: none;\n"
"}\n"
"\n"
"\n"
"QScrollBar::sub-line:vertical\n"
"{\n"
"   background: none;\n"
"}\n"
"\n"
"\n"
"QScrollBar::up-arrow:vertical\n"
"{\n"
"    background: none;\n"
"}\n"
"\n"
"\n"
"QScrollBar::down-arrow:vertical\n"
"{\n"
"   background: none;\n"
"}\n"
"\n"
"\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical\n"
"{\n"
"    background: none;\n"
"\n"
"}\n"
""));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(990, 310, 171, 141));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        openSideBarBT->setText(QCoreApplication::translate("MainWindow", "push", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "product", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "product", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "product", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Quantity", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
