#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <QToolBar>
#include "ripplebutton.hpp"

class Widget : public QMainWindow
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
	
	//If you want to have Max/Min/Close buttons, look at how QWinWidget uses these
    RippleButton *maximizeButton = nullptr;
    RippleButton *minimizeButton = nullptr;
    RippleButton *closeButton = nullptr;

    //If you want to enable dragging the window when the mouse is over top of, say, a QToolBar, 
	//then look at how QWinWidget uses this
	QToolBar* toolBar = nullptr;

signals:

public slots:
};

#endif // WIDGET_H
