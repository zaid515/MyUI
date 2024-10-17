#include "sidebar.hpp"
#include <QPointer>

SideBar::SideBar(QWidget *parent)
    : QWidget(parent)
{
    openDuration = 250;
}

MyUI::Layout SideBar::getLayout() const
{
    return layout;
}

void SideBar::setLayout(const MyUI::Layout &newLayout)
{
    layout = newLayout;
}

MyUI::OpenDirction SideBar::getOpenDirction() const
{
    return openDirction;
}

void SideBar::setOpenDirction(const MyUI::OpenDirction &newOpenDirction)
{
    openDirction = newOpenDirction;
}

int SideBar::getX() const
{
    return x;
}

void SideBar::setX(const int &newX)
{
    if (x == newX)
        return;
    x = newX;
    this->move(newX, geometry().y());
    emit xChanged();
}

int SideBar::getY() const
{
    return y;
}

void SideBar::setY(const int &newY)
{
    if (y == newY)
        return;
    y = newY;
    this->move(geometry().x(), newY);
    emit yChanged();
}

void SideBar::openSideBar()
{
    QPointer<QPropertyAnimation> openAnimation = new QPropertyAnimation();
    openAnimation->setEasingCurve(QEasingCurve::OutQuad);
    openAnimation->setDuration(openDuration);
    openAnimation->setTargetObject(this);

    if (openStat) {
        //open sidebar
        if (layout == MyUI::Layout::Vertical) {
            openAnimation->setPropertyName("x");
            if (openDirction == MyUI::OpenDirction::ToRight) {
                openAnimation->setStartValue(0);
                openAnimation->setEndValue(-this->width());
            } else if (openDirction == MyUI::OpenDirction::ToLeft) {
                openAnimation->setStartValue(this->parentWidget()->width() - this->width());
                openAnimation->setEndValue(this->parentWidget()->width());
            }
        } else if (layout == MyUI::Layout::Horizontal) {
            openAnimation->setPropertyName("y");
            if (openDirction == MyUI::OpenDirction::ToTop) {
                openAnimation->setStartValue(this->parentWidget()->height() - this->height());
                openAnimation->setEndValue(this->parentWidget()->height());
            } else if (openDirction == MyUI::OpenDirction::ToBottom) {
                openAnimation->setStartValue(this->parentWidget()->y());
                openAnimation->setEndValue(-this->height());
            }
        }
    }
    else{
        //close sidebar
        if (layout == MyUI::Layout::Vertical) {
            openAnimation->setPropertyName("x");
            if (openDirction == MyUI::OpenDirction::ToRight) {
                openAnimation->setStartValue(-this->width());
                openAnimation->setEndValue(0);
            } else if (openDirction == MyUI::OpenDirction::ToLeft) {
                openAnimation->setStartValue(this->parentWidget()->width());
                openAnimation->setEndValue(this->parentWidget()->width() - this->width());
            }
        } else if (layout == MyUI::Layout::Horizontal) {
            openAnimation->setPropertyName("y");
            if (openDirction == MyUI::OpenDirction::ToTop) {
                openAnimation->setStartValue(this->parentWidget()->height());
                openAnimation->setEndValue(this->parentWidget()->height() - this->height());
            } else if (openDirction == MyUI::OpenDirction::ToBottom) {
                openAnimation->setStartValue(-this->height());
                openAnimation->setEndValue(0);
            }
        }
    }
    openStat = !openStat;
    connect(openAnimation, &QPropertyAnimation::valueChanged, this, [=]() { update(); });
    openAnimation->start(QAbstractAnimation::DeleteWhenStopped);
}

//set open side bar button
void SideBar::setOpenButtton(QPushButton *button)
{
    connect(button, &QPushButton::clicked, this, &SideBar::openSideBar);
}

int SideBar::getOpenDuration() const
{
    return openDuration;
}

void SideBar::setOpenDuration(int newOpenDuration)
{
    openDuration = newOpenDuration;
}

void SideBar::paintEvent(QPaintEvent *event)
{    
    //paint background
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(this->rect(), QColor(23,33,43));
    QWidget::paintEvent(event);
}
