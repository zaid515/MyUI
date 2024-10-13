#include "widget.h"

Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
    , darkThemeEnabled(false)
{
    darkThemeEnabled = Settings::read("Settings.ini", "DarkThemeEnabled").toBool();
    //Set a black background for funsies
    QPalette Pal(palette());

    if (darkThemeEnabled) {
        Pal.setColor(QPalette::Window, QColor(20, 20, 20));
    } else {
        Pal.setColor(QPalette::Window, Qt::white);
    }
    setAutoFillBackground(true);
	setPalette(Pal);

    //Windows example of adding a toolbar + min/max/close buttons
#ifdef _WIN32

	//Add the toolbar
    toolBar = new QToolBar(this);
    toolBar->setMovable(false);
    toolBar->setFloatable(false);
    toolBar->layout()->setContentsMargins(0, 0, 0, 0);
    toolBar->setStyleSheet("background-color: none; border: none");
    addToolBar(toolBar);

    //Create a transparent-to-mouse-events widget that pads right for a fixed width equivalent to min/max/close buttons
    QWidget *btnSpacer = new QWidget(toolBar);
    btnSpacer->setAttribute(Qt::WA_TransparentForMouseEvents);
    btnSpacer->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    btnSpacer->setStyleSheet("background-color: none; border: none;");
    btnSpacer->setFixedWidth(135 /* rough width of close/min/max buttons */);
    toolBar->addWidget(btnSpacer);

    //Create a title label just because
    QLabel *titleLabel = new QLabel("              MyUI");
    if (darkThemeEnabled) {
        titleLabel->setStyleSheet("color: rgb(255,255,255);");
    } else {
        titleLabel->setStyleSheet("color: rgb(0,0,0);");
    }
    QFont font = titleLabel->font();
    font.setPointSize(12);
    titleLabel->setFont(font);
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
    minimizeButton = new RippleButton("");
    maximizeButton = new RippleButton("");
    closeButton = new RippleButton("");

    if (darkThemeEnabled) {
        minimizeButton->setIcon(QIcon(":/themeIcons/white_minimize.png"));
        maximizeButton->setIcon(QIcon(":/themeIcons/white_maximize.png"));
        closeButton->setIcon(QIcon(":/themeIcons/white_close.png"));
    } else {
        minimizeButton->setIcon(QIcon(":/themeIcons/Minimize.png"));
        maximizeButton->setIcon(QIcon(":/themeIcons/Maximize.png"));
        closeButton->setIcon(QIcon(":/themeIcons/Close.png"));
    }

    minimizeButton->setIconSize(QSize(15, 10));
    maximizeButton->setIconSize(QSize(10, 10));
    closeButton->setIconSize(QSize(10, 10));

    Theme::Get().init();
    QString style = Theme::Get().titleBarButtons;

    minimizeButton->setStyleSheet(style);
    maximizeButton->setStyleSheet(style);
    closeButton->setStyleSheet(Theme::Get().titleBarCloseButton);

    maximizeButton->setCheckable(true);

    connect(maximizeButton, &RippleButton::clicked, this, [=]() {
        if (maximizeButton->isChecked()) {
            if (darkThemeEnabled) {
                maximizeButton->setIcon(QIcon(":/themeIcons/white_Restore.png"));
            } else {
                maximizeButton->setIcon(QIcon(":/themeIcons/Restore.png"));
            }
        } else {
            if (darkThemeEnabled) {
                maximizeButton->setIcon(QIcon(":/themeIcons/white_maximize.png"));
            } else {
                maximizeButton->setIcon(QIcon(":/themeIcons/Maximize.png"));
            }
        }
    });

    minimizeButton->setFixedSize(48, 30);
    maximizeButton->setFixedSize(48, 30);
    closeButton->setFixedSize(48, 30);
    toolBar->setMinimumHeight(32);
    toolBar->setMinimumWidth(this->width());
    toolBar->addWidget(minimizeButton);
    toolBar->addWidget(maximizeButton);
    toolBar->addWidget(closeButton);
    toolBar->layout()->setAlignment(titleLabel, Qt::AlignCenter);
    toolBar->layout()->setAlignment(minimizeButton, Qt::AlignTop);
    toolBar->layout()->setAlignment(maximizeButton, Qt::AlignTop);
    toolBar->layout()->setAlignment(closeButton, Qt::AlignTop);

    //An actual app should use icons for the buttons instead of text
    //and style the different button states / widget margins in css

#endif

}
