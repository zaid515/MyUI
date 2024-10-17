#include "spinner.hpp"

Spinner::Spinner(QWidget *parent)
    : QWidget{parent}
    , a(this, "degree")
    , spinnerColor(QColor(33, 150, 243))
    , spinnerWidth(4)
    , duration(750)
    , degree(0)
{
    //init animation
    a.setDuration(duration);
    a.setStartValue(0);
    a.setEndValue(360);
    a.start();

    connect(&a, &QPropertyAnimation::valueChanged, this, [=]() { update(); });
    connect(&a, &QPropertyAnimation::finished, this, [=]() {
        a.start();
    });
}

void Spinner::paintEvent(QPaintEvent *event)
{
    //init painter
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    //make color faded
    gradient.setStart(this->width() / 2, 0);
    gradient.setFinalStop(this->width() / 2, this->height());
    gradient.setColorAt(0, spinnerColor);
    gradient.setColorAt(1, QColor(5, 239, 97));

    b = QBrush(gradient);

    //init painter pen
    QPen a;
    a.setBrush(b);
    a.setWidth(spinnerWidth);
    a.setCapStyle(Qt::RoundCap);
    p.setPen(a);

    //init painter rect and ignor spinner width
    QRectF rect((p.pen().widthF() / 2.0) - (this->width() / 2),
                (p.pen().widthF() / 2.0) - (this->height() / 2),
                width() - p.pen().widthF(),
                height() - p.pen().widthF());

    //draw spinner
    p.translate((this->width() / 2), (this->height() / 2));
    p.rotate(degree);
    p.drawArc(rect, 90 * 16, (360 * (25 / 100.0)) * 16);

    QWidget::paintEvent(event);
}

QColor Spinner::getSpinnerColor() const
{
    return spinnerColor;
}

void Spinner::setSpinnerColor(const QColor &newSpinnerColor)
{
    spinnerColor = newSpinnerColor;
}

int Spinner::getDuration() const
{
    return duration;
}

void Spinner::setDuration(int newDuration)
{
    duration = newDuration;
}

int Spinner::getSpinnerWidth() const
{
    return spinnerWidth;
}

void Spinner::setSpinnerWidth(int newSpinnerWidth)
{
    spinnerWidth = newSpinnerWidth;
}

int Spinner::getDegree() const
{
    return degree;
}

void Spinner::setDegree(int newDegree)
{
    if (degree == newDegree)
        return;
    degree = newDegree;
    emit degreeChanged();
}
