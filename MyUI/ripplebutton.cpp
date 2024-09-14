#include "ripplebutton.hpp"
#include "qwidget.h"

//--------------------------------------------------------------
// Ripple class
//--------------------------------------------------------------
float Ripple::radius() const
{
    return m_radius;
}

float Ripple::setRadius(float newRadius)
{
    m_radius = newRadius;
    //emit radiusChanged(newRadius);
    return newRadius;
}

float Ripple::opacity() const
{
    return m_opacity;
}

void Ripple::setOpacity(float newOpacity)
{
    m_color.setAlpha(m_opacity);
    m_opacity = newOpacity;
}

bool Ripple::expanded_finished() const
{
    return m_expanded_finished;
}

void Ripple::setExpanded_finished(bool newExpanded_finished)
{
    m_expanded_finished = newExpanded_finished;
}

bool Ripple::isFinished() const
{
    return m_finished;
}

void Ripple::setFinished(bool newFinished)
{
    m_finished = newFinished;
}

QColor Ripple::color() const
{
    return m_color;
}

void Ripple::setColor(const QColor &newColor)
{
    m_color = newColor;
}

QPointF Ripple::center() const
{
    return m_center;
}

void Ripple::setCenter(QPointF newCenter)
{
    m_center = newCenter;
}

Ripple::Ripple(const QPoint &center, const float &radius, const QColor &color)
{
    m_center = center;
    m_radius = radius;
    m_opacity = 255.0;
    m_color = color;
    m_expanded_finished = false;
    m_finished = false;
}

//--------------------------------------------------------------
// Ripple Button class
//--------------------------------------------------------------
RippleButton::RippleButton(QWidget *parent)
{
    setParent(parent);
}

RippleButton::~RippleButton() {}

void RippleButton::setRippleColor(const QColor &color)
{
    rippleColor = color;
}

void RippleButton::paintEvent(QPaintEvent *paintEvent)
{
    Q_UNUSED(paintEvent);
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing
                           | QPainter::SmoothPixmapTransform);
    painter.setPen(Qt::NoPen);

    for (const Ripple *ripple : ripples_) {
        painter.setBrush(ripple->color());
        painter.drawEllipse(ripple->center(), ripple->radius(), ripple->radius());
        painter.drawText(ripple->center(), "zaidamier");
    }
}

void RippleButton::mousePressEvent(QMouseEvent *event)
{
    QPushButton::mousePressEvent(event);
    std::shared_ptr<Ripple> ripple = std::make_shared<Ripple>(event->pos(), 0, rippleColor);
    ripples_.append(ripple.get());

    float maxRadius = std::sqrt(std::pow(width(), 2) + std::pow(height(), 2));
    QPropertyAnimation *radiusAnimation = new QPropertyAnimation(ripple.get(), "radius");
    radiusAnimation->setEasingCurve(QEasingCurve::OutQuad);
    radiusAnimation->setDuration(1500);
    radiusAnimation->setStartValue(0);
    radiusAnimation->setEndValue(maxRadius);

    connect(radiusAnimation, &QPropertyAnimation::finished, [=]() { ripple->setFinished(true); });
    connect(radiusAnimation, &QPropertyAnimation::valueChanged, [=]() { update(); });

    QPropertyAnimation *opacityAnimation = new QPropertyAnimation(ripple.get(), "opacity");
    opacityAnimation->setEasingCurve(QEasingCurve::OutQuad);
    opacityAnimation->setDuration(800);
    opacityAnimation->setStartValue(255.0);
    opacityAnimation->setEndValue(0.0);
    OpacityAnimations_.append(opacityAnimation);

    connect(opacityAnimation, &QPropertyAnimation::valueChanged, [=]() { update(); });

    radiusAnimation->start();
}

void RippleButton::mouseReleaseEvent(QMouseEvent *event)
{
    QPushButton::mouseReleaseEvent(event);

    for (int index = 0; index < ripples_.size(); ++index) {
        if (ripples_[index]->isFinished()) {
            ripples_.removeAt(index);
            OpacityAnimations_.removeAt(index);
        }
    }
    if (!OpacityAnimations_.isEmpty())
        OpacityAnimations_.last()->start();
}
