#include "textedit.hpp"

TextEdit::TextEdit(QWidget *parent)
    : QLineEdit(parent)
    , xPressPos(0)
    , rectWidth(0)
    , active(false)
{
    this->setAlignment(Qt::AlignBottom);
    this->setFrame(false);
    activeRect = std::make_unique<MyUI::MyRect>();
    ///this->setStyleSheet("background-color: transperant;");
}

void TextEdit::paintEvent(QPaintEvent *event)
{
    QLineEdit::paintEvent(event);
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
    p.setPen(Qt::NoPen);
    //p.drawRect(QRect(0, 0, 200, 60));
    p.setBrush(Qt::black);
    p.drawRect(0, this->height() - 2, this->width(), 2);

    p.setBrush(Qt::blue);
    p.drawRect(xPressPos, this->height() - 3, activeRect->getWidth(), 3);
}

void TextEdit::mousePressEvent(QMouseEvent *event)
{
    QLineEdit::mousePressEvent(event);
    setActive(true);

    xPressPos = this->width() / 2;

    QPropertyAnimation *p = new QPropertyAnimation(activeRect.get(), "width");
    p->setEasingCurve(QEasingCurve::OutBack);
    p->setDuration(3000);
    p->setStartValue(0);
    p->setEndValue(this->width() + 100);

    connect(p, &QPropertyAnimation::valueChanged, this, [=]() { update(); });
    connect(p, &QPropertyAnimation::finished, this, [=]() { delete p; });

    p->start();
}

void TextEdit::focusOutEvent(QFocusEvent *event)
{
    QLineEdit::focusOutEvent(event);
    setActive(false);

    //xPressPos = 0;

    QPropertyAnimation *p = new QPropertyAnimation(activeRect.get(), "width");
    p->setEasingCurve(QEasingCurve::OutBack);
    p->setDuration(1000);
    p->setStartValue(this->width());
    p->setEndValue(0);

    connect(p, &QPropertyAnimation::valueChanged, this, [=]() { update(); });
    connect(p, &QPropertyAnimation::finished, this, [=]() { delete p; });

    p->start();
}

bool TextEdit::isActive() const
{
    return active;
}

void TextEdit::setActive(const bool &newActive)
{
    active = newActive;
}

// MyRect

uint8_t MyUI::MyRect::getWidth() const
{
    return width;
}

void MyUI::MyRect::setWidth(const uint8_t &newWidth)
{
    if (width == newWidth)
        return;
    width = newWidth;
    emit widthChanged();
}

uint8_t MyUI::MyRect::getHeight() const
{
    return height;
}

void MyUI::MyRect::setHeight(const uint8_t &newHeight)
{
    if (height == newHeight)
        return;
    height = newHeight;
    emit heightChanged();
}

uint8_t MyUI::MyRect::getX() const
{
    return x;
}

void MyUI::MyRect::setX(uint8_t newX)
{
    x = newX;
}

uint8_t MyUI::MyRect::getY() const
{
    return y;
}

void MyUI::MyRect::setY(uint8_t newY)
{
    y = newY;
}

MyUI::MyRect::MyRect(uint8_t _x, uint8_t _y, uint8_t _width, uint8_t _height)
    : x(_x)
    , y(_y)
    , width(_width)
    , height(_height)
{}
