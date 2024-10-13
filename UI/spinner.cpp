#include "spinner.hpp"

Spinner::Spinner(QWidget *parent)
    : QWidget{parent}
    , spinnerColor(QColor(33, 150, 243))
    , spinnerWidth(3)
    , duration(1000)
    , degree(0)
{
    QPropertyAnimation *a = new QPropertyAnimation(this, "degree");
    a->setDuration(duration);
    a->setStartValue(0);
    a->setEndValue(100);
    a->start();

    connect(a, &QPropertyAnimation::valueChanged, this, [=]() { update(); });
    connect(a, &QPropertyAnimation::finished, this, [=]() { a->start(); });
}

void Spinner::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    b = QBrush(gradient);
    gradient.setStart(this->width() / 2, 0);
    gradient.setFinalStop(this->width() / 2, this->height());
    gradient.setColorAt(0, Qt::black);
    gradient.setColorAt(1, spinnerColor);

    p.setPen(QPen(b, spinnerWidth));
    QRectF rect(p.pen().widthF() / 2.0,
                p.pen().widthF() / 2.0,
                width() - p.pen().widthF(),
                height() - p.pen().widthF());
    p.drawArc(rect, 90 * 16, (360 * (degree / 100.0)) * 16);

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
