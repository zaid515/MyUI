#include "ripplebutton.hpp"
#include <QPainterPath>
#include <QStyleOptionButton>
#include <QStylePainter>
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
    m_opacity = 50.0;
    m_color = color;
    m_color.setAlpha(m_opacity);
    m_expanded_finished = false;
    m_finished = false;
}

//--------------------------------------------------------------
// Ripple Button class defintion
//--------------------------------------------------------------
RippleButton::RippleButton(QWidget *parent)
{
    setParent(parent);
}

RippleButton::RippleButton(const QString &text, QWidget *parent)
    : QPushButton(text, parent)
{}

RippleButton::RippleButton(const QIcon &icon, const QString &text, QWidget *parent)
    : QPushButton(icon, text, parent)
{}

RippleButton::~RippleButton()
{
    //frees memory
    ripples_.clear();
    opacityAnimations_.clear();
    radiusAnimations_.clear();
}

void RippleButton::setRippleColor(const QColor &color)
{
    rippleColor = color;
}

void RippleButton::paintEvent(QPaintEvent *paintEvent)
{
    QWidget::paintEvent(paintEvent);

    //inti Button Style
    QStylePainter p(this);
    p.setRenderHints(QPainter::Antialiasing);
    QStyleOptionButton option;
    initStyleOption(&option);
    p.drawControl(QStyle::CE_PushButton, option);

    //init the painter
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

    //get border radius from styleSheet
    QRegularExpression regex("border-radius:\\s*(\\d+)px;");
    QRegularExpressionMatch match = regex.match(this->styleSheet());
    borderRadius = match.captured(1).toInt();

    //setting clip path
    QPainterPath path;
    path.addRoundedRect(this->rect(), borderRadius, borderRadius);
    painter.setClipPath(path);

    //draw the ripple
    for (const Ripple *ripple : ripples_) {
        painter.setPen(Qt::NoPen);
        painter.setBrush(ripple->color());
        painter.drawEllipse(ripple->center(), ripple->radius(), ripple->radius());
    }
}

void RippleButton::mousePressEvent(QMouseEvent *event)
{
    //create ripple
    QPushButton::mousePressEvent(event);
    std::shared_ptr<Ripple> ripple = std::make_shared<Ripple>(event->pos(), 0, rippleColor);
    ripples_.append(ripple.get());

    //init the radius animation
    float maxRadius = std::sqrt(std::pow(width(), 2) + std::pow(height(), 2));
    QPropertyAnimation *radiusAnimation = new QPropertyAnimation(ripple.get(), "radius");
    radiusAnimation->setEasingCurve(QEasingCurve::OutQuad);
    radiusAnimation->setDuration(1000);
    radiusAnimation->setStartValue(0);
    radiusAnimation->setEndValue(maxRadius);
    radiusAnimations_.append(radiusAnimation);

    connect(radiusAnimation, &QPropertyAnimation::finished, this, [=]() {
        ripple->setFinished(true);
        if (radiusAnimations_.size() >= 10 && ripple->opacity() == 0) {
            radiusAnimations_.clear();
        }
    });
    connect(radiusAnimation, &QPropertyAnimation::valueChanged, this, [=]() { update(); });

    //init the opacity animation
    QPropertyAnimation *opacityAnimation = new QPropertyAnimation(ripple.get(), "opacity");
    opacityAnimation->setEasingCurve(QEasingCurve::OutQuad);
    opacityAnimation->setDuration(800);
    opacityAnimation->setStartValue(ripple->opacity());
    opacityAnimation->setEndValue(0.0);
    opacityAnimations_.append(opacityAnimation);

    connect(opacityAnimation, &QPropertyAnimation::valueChanged, this, [=]() { update(); });

    radiusAnimation->start();
}

void RippleButton::mouseReleaseEvent(QMouseEvent *event)
{
    QPushButton::mouseReleaseEvent(event);

    //remove expanding finished ripples
    for (int index = 0; index < ripples_.size(); ++index) {
        if (ripples_[index]->isFinished()) {
            ripples_.removeAt(index);
            opacityAnimations_.removeAt(index);
        }
    }
    if (!opacityAnimations_.isEmpty())
        opacityAnimations_.last()->start();
}
