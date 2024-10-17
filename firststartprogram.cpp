#include "firststartprogram.hpp"
#include <QTimer>
#include "ui_firststartprogram.h"

//-----------------------------------
//MyEllipse class
//-----------------------------------

MyEllipse::MyEllipse(QWidget *parent)
    : width(0)
    , height(0)
    , x(0)
    , y(0)
    , radius(0)
    , parentCenter((parent->width() / 2), (parent->height() / 2))
{
    ellipse = new QGraphicsEllipseItem;
}

MyEllipse::~MyEllipse() {}

int MyEllipse::getX() const
{
    return x;
}

void MyEllipse::setX(const int &newX)
{
    if (x == newX)
        return;
    x = newX;
    ellipse->setX(x);
    emit xChanged();
}

int MyEllipse::getY() const
{
    return y;
}

void MyEllipse::setY(const int &newY)
{
    if (y == newY)
        return;
    y = newY;
    ellipse->setY(y);
    emit yChanged();
}

int MyEllipse::getRadius() const
{
    return radius;
}

void MyEllipse::setRadius(const int &newRadius)
{
    if (radius == newRadius)
        return;
    radius = newRadius;
    ellipse->setRect(parentCenter.x() - radius / 2, parentCenter.y() - radius / 2, radius, radius);
    emit radiusChanged();
}

int MyEllipse::getWidth() const
{
    return width;
}

void MyEllipse::setWidth(const int &newWidth)
{
    if (width == newWidth)
        return;
    width = newWidth;
    ellipse->setRect(parentCenter.x() - width / 2,
                     parentCenter.y(),
                     width,
                     ellipse->rect().height());
    emit widthChanged();
}

int MyEllipse::getHeight() const
{
    return height;
}

void MyEllipse::setHeight(const int &newHeight)
{
    if (height == newHeight)
        return;
    height = newHeight;
    ellipse->setRect(ellipse->x(), ellipse->y(), ellipse->rect().width(), height);
    emit heightChanged();
}

//-------------------------------------------------------------
//FirstStartProgram class
//-------------------------------------------------------------

FirstStartProgram::FirstStartProgram(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FirstStartProgram)
{
    ui->setupUi(this);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    // Sets the scene rect to its maximum possible ranges to avoid autu scene range
    // re-calculation when expanding the all QGraphicsItems common rect.
    ui->graphicsView->setSceneRect(0, 0, this->width(), this->height());

    scene = new QGraphicsScene(ui->graphicsView);
    scene->setBackgroundBrush(Qt::white);
    ui->graphicsView->setScene(scene);

    MyEllipse *shadow = new MyEllipse(this);
    shadow->ellipse->setRect(QRect((this->width() / 2) - 50, (this->height() / 2), 100, 20));
    shadow->ellipse->setBrush(QColor(0, 0, 0, 100));
    shadow->ellipse->setPen(Qt::NoPen);

    scene->addItem(shadow->ellipse);

    MyEllipse *ripple = new MyEllipse(this);
    ripple->ellipse->setRect(QRect((this->width() / 2) - 50, (this->height() / 2) - 90, 100, 100));
    ripple->ellipse->setBrush(QColor(14, 22, 33));
    ripple->ellipse->setPen(Qt::NoPen);
    scene->addItem(ripple->ellipse);

    animation.setTargetObject(ripple);
    animation.setPropertyName("y");
    animation.setEasingCurve(QEasingCurve::OutCubic);
    animation.setDuration(750);
    animation.setStartValue(0);
    animation.setEndValue(-250);

    shadowAnimation.setTargetObject(shadow);
    shadowAnimation.setPropertyName("width");
    shadowAnimation.setEasingCurve(QEasingCurve::OutCubic);
    shadowAnimation.setDuration(750);
    shadowAnimation.setStartValue(100);
    shadowAnimation.setEndValue(75);

    animation.start();
    shadowAnimation.start();

    QTimer::singleShot(850, this, [=]() {
        animation.setEasingCurve(QEasingCurve::InCubic);
        animation.setStartValue(-250);
        animation.setEndValue(-40);

        shadowAnimation.setEasingCurve(QEasingCurve::InCubic);
        shadowAnimation.setStartValue(75);
        shadowAnimation.setEndValue(100);

        animation.start();
        shadowAnimation.start();
    });

    float maxRadius = std::sqrt(std::pow(width(), 2) + std::pow(height(), 2));
    QTimer::singleShot(1605, this, [=]() {
        animation.setEasingCurve(QEasingCurve::OutBack);
        animation.setPropertyName("radius");
        animation.setStartValue(100);
        animation.setEndValue(maxRadius + 100);
        animation.start();
    });

    QTimer::singleShot(2360, this, [=]() { ui->graphicsView->close(); });
}

FirstStartProgram::~FirstStartProgram()
{
    delete ui;
}
