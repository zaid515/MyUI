#include "textedit.hpp"

TextEdit::TextEdit(QWidget *parent)
    : QLineEdit(parent)
    , activeColor(QColor(33, 150, 243))
    , activeRect(std::make_unique<MyRect>(0, 0, 0, 0))
    , xPressPos(0)
    , duration(500)
    , active(false)
{
    this->setAlignment(Qt::AlignBottom);
    this->setFrame(false);
    this->setTextMargins(0, 0, 0, 5);
}

void TextEdit::paintEvent(QPaintEvent *event)
{
    //init painter
    QLineEdit::paintEvent(event);
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
    p.setPen(Qt::NoPen);

    //paint unactive line
    p.setBrush(Qt::gray);
    p.drawRect(0, this->height() - 2, this->width(), 2);

    //paint active line
    p.setBrush(activeColor);
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

        //init animation
        QPointer<QPropertyAnimation> p = new QPropertyAnimation();
        p->setEasingCurve(QEasingCurve::OutQuad);
        p->setTargetObject(activeRect.get());
        p->setPropertyName("width");
        p->setDuration(duration);
        p->setStartValue(0);
        p->setEndValue(this->width() + this->width());
        p->start(QAbstractAnimation::DeleteWhenStopped);

        connect(p, &QPropertyAnimation::valueChanged, this, [=]() { update(); });
        connect(p, &QPropertyAnimation::finished, this, [=]() { delete p; });
        setActive(true);
    }
}

void TextEdit::focusOutEvent(QFocusEvent *event)
{
    QLineEdit::focusOutEvent(event);
    //hide active line
    activeRect->setWidth(0);
    setActive(false);
    update();
}

int TextEdit::getDuration() const
{
    return duration;
}

void TextEdit::setDuration(int newDuration)
{
    duration = newDuration;
}

QColor TextEdit::getActiveColor() const
{
    return activeColor;
}

void TextEdit::setActiveColor(const QColor &newActiveColor)
{
    activeColor = newActiveColor;
}

bool TextEdit::isActive() const
{
    return active;
}

void TextEdit::setActive(const bool &newActive)
{
    active = newActive;
}
//----------------------------------------------------
// MyRect class
//----------------------------------------------------

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

MyRect::MyRect(int _x, int _y, int _width, int _height)
    : x(_x)
    , y(_y)
    , width(_width)
    , height(_height)
{}
