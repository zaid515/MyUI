#include "textedit.hpp"

TextEdit::TextEdit(QWidget *parent)
    : QLineEdit(parent)
    , xPressPos(0)
    , rectWidth(0)
    , active(false)
{
    this->setAlignment(Qt::AlignBottom);
    this->setFrame(false);
    this->setTextMargins(0, 0, 0, 5);
    activeRect = new MyRect(0, 0, 0, 0);

    a.setParent(this);
    a.setText("Product name");
    a.setAlignment(Qt::AlignLeft);
    a.move(0, this->height() - 25);
    a.show();
}

void TextEdit::paintEvent(QPaintEvent *event)
{
    QLineEdit::paintEvent(event);
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
    p.setPen(Qt::NoPen);

    p.setBrush(Qt::gray);
    p.drawRect(0, this->height() - 2, this->width(), 2);

    p.setBrush(Qt::blue);
    p.drawRect(xPressPos - (activeRect->getWidth() / 2),
               this->height() - 3,
               activeRect->getWidth(),
               3);
}

void TextEdit::mousePressEvent(QMouseEvent *event)
{
    QLineEdit::mousePressEvent(event);

    if (!active) {
        xPressPos = event->pos().x();
        QPointer<QPropertyAnimation> p = new QPropertyAnimation();
        p->setEasingCurve(QEasingCurve::OutQuad);
        p->setTargetObject(activeRect);
        p->setPropertyName("width");
        p->setDuration(750);
        p->setStartValue(0);
        p->setEndValue(this->width() + this->width());
        p->start();
        connect(p, &QPropertyAnimation::valueChanged, this, [=]() { update(); });
        connect(p, &QPropertyAnimation::finished, this, [=]() { delete p; });
        setActive(true);
    }
}

void TextEdit::focusOutEvent(QFocusEvent *event)
{
    QLineEdit::focusOutEvent(event);
    activeRect->setWidth(0);
    setActive(false);
    update();
}

int TextEdit::getRectWidth() const
{
    return rectWidth;
}

void TextEdit::setRectWidth(int newRectWidth)
{
    if (rectWidth == newRectWidth)
        return;
    rectWidth = newRectWidth;
    emit rectWidthChanged();
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

int MyRect::getWidth() const
{
    return width;
}

void MyRect::setWidth(int newWidth)
{
    if (width == newWidth)
        return;
    width = newWidth;
    emit widthChanged();
}

int MyRect::getHeight() const
{
    return height;
}

void MyRect::setHeight(int newHeight)
{
    if (height == newHeight)
        return;
    height = newHeight;
    emit heightChanged();
}

int MyRect::getX() const
{
    return x;
}

void MyRect::setX(int newX)
{
    x = newX;
}

int MyRect::getY() const
{
    return y;
}

void MyRect::setY(int newY)
{
    y = newY;
}

MyRect::MyRect(uint8_t _x, uint8_t _y, uint8_t _width, uint8_t _height)
    : x(_x)
    , y(_y)
    , width(_width)
    , height(_height)
{}
