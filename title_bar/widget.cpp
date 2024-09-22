#include "widget.h"

#include <QLabel>
#include <QLayout>

Widget::Widget(QWidget *parent)
	: QMainWindow(parent)
{

	//Set a black background for funsies
	QPalette Pal(palette());
    Pal.setColor(QPalette::Window, Qt::white);
    setAutoFillBackground(true);
	setPalette(Pal);


	//Windows example of adding a toolbar + min/max/close buttons
#ifdef _WIN32

	//Add the toolbar
	toolBar = new QToolBar(this);
    toolBar->setMovable(false);
    toolBar->setFloatable(false);
    addToolBar(toolBar);

    //Create a transparent-to-mouse-events widget that pads right for a fixed width equivalent to min/max/close buttons
    QWidget *btnSpacer = new QWidget(toolBar);
    btnSpacer->setAttribute(Qt::WA_TransparentForMouseEvents);
    btnSpacer->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    btnSpacer->setStyleSheet("background-color: none; border: none;");
    btnSpacer->setFixedWidth(135 /* rough width of close/min/max buttons */);
    toolBar->addWidget(btnSpacer);

    //Create a title label just because
    QLabel *titleLabel = new QLabel("MyUI");
    titleLabel->setStyleSheet("color: rgb(0,0,0);");
    QFont font = titleLabel->font();
    font.setPointSize(12);
    titleLabel->setFont(font);
    titleLabel->setMinimumHeight(30);
    titleLabel->setAlignment(Qt::AlignTop);
    titleLabel->setFixedWidth(160);

    //Set it transparent to mouse events such that you can click and drag when moused over the label
    titleLabel->setAttribute(Qt::WA_TransparentForMouseEvents);

    //Create spacer widgets to keep the title centered
    QWidget *leftSpacer = new QWidget(toolBar);
    QWidget *rightSpacer = new QWidget(toolBar);

    //Set them transparent to mouse events + auto-expanding in size
    leftSpacer->setAttribute(Qt::WA_TransparentForMouseEvents);
    leftSpacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    leftSpacer->setStyleSheet("background-color: none; border: none;");
    rightSpacer->setAttribute(Qt::WA_TransparentForMouseEvents);
    rightSpacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    rightSpacer->setStyleSheet("background-color: none; border: none;");

    //Add spacers & title label
	toolBar->addWidget(leftSpacer);
	toolBar->addWidget(titleLabel);
	toolBar->addWidget(rightSpacer);


	//Create the min/max/close buttons
    minimizeButton = new RippleButton("-");
    maximizeButton = new RippleButton("O");
    closeButton = new RippleButton("X");

    const QString style
        = "QPushButton{background-color: rgb(255, 255, 255);color: #000000;padding: "
          "5px;border-radius: 0px;font: 15pt "
          "Microsoft Sans Serif"
          ";}QPushButton::hover{background-color: rgb(200, 200, "
          "200);color:rgb(255,255,255);border-radius: 0px;padding: 5px;}";

    minimizeButton->setStyleSheet(style);
    maximizeButton->setStyleSheet(style);
    closeButton->setStyleSheet(style);

    maximizeButton->setCheckable(true);

    minimizeButton->setMinimumHeight(30);
    maximizeButton->setMinimumHeight(30);
    closeButton->setMinimumHeight(30);
    toolBar->setMinimumHeight(30);
    toolBar->addWidget(minimizeButton);
    toolBar->addWidget(maximizeButton);
    toolBar->addWidget(closeButton);
    toolBar->layout()->setAlignment(minimizeButton, Qt::AlignTop);
	toolBar->layout()->setAlignment(maximizeButton, Qt::AlignTop);
	toolBar->layout()->setAlignment(closeButton, Qt::AlignTop);

	//An actual app should use icons for the buttons instead of text
	//and style the different button states / widget margins in css

#endif

}
