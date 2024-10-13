#ifndef WIDGET_H
#define WIDGET_H

#include <QGraphicsEffect>
#include <QLabel>
#include <QLayout>
#include <QMainWindow>
#include <QToolBar>
#include "UI/ripplebutton.hpp"
#include "UI/settings.hpp"
#include "UI/theme.hpp"

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
    QToolBar *toolBar = nullptr;

signals:

public slots:

private:
    bool darkThemeEnabled;
};

#endif // WIDGET_H
