#ifndef RIPPLEBUTTON_HPP
#define RIPPLEBUTTON_HPP

#include <QMouseEvent>
#include <QObject>
#include <QPainter>
#include <QPoint>
#include <QPropertyAnimation>
#include <QPushButton>

class Ripple : public QObject
{
public:
    Q_OBJECT
    Q_PROPERTY(float radius READ radius WRITE setRadius NOTIFY radiusChanged)
    Q_PROPERTY(float opacity READ opacity WRITE setOpacity NOTIFY opacityChanged)

protected:
    QPointF m_center;
    QColor m_color;
    float m_radius;
    float m_opacity;
    bool m_expanded_finished;
    bool m_finished;

public:
    Ripple(const QPoint &center = QPoint(0, 0),
           const float &radius = 0,
           const QColor &color = Qt::white);
    virtual ~Ripple() {};
    QPointF center() const;
    void setCenter(QPointF newCenter);
    float radius() const;
    float setRadius(float newRadius);
    float opacity() const;
    void setOpacity(float newOpacity);
    bool expanded_finished() const;
    void setExpanded_finished(bool newExpanded_finished);
    bool isFinished() const;
    void setFinished(bool newFinished);
    QColor color() const;
    void setColor(const QColor &newColor);

signals:
    void radiusChanged(double radius);
    void opacityChanged(double opacity);
};

class RippleButton : public QPushButton
{
    Q_OBJECT

public:
    RippleButton(QWidget *parent = nullptr);
    virtual ~RippleButton();
    void setRippleColor(const QColor &color);

protected:
    void paintEvent(QPaintEvent *paintEvent = nullptr) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QColor rippleColor;
    QList<Ripple *> ripples_;
    QList<QPropertyAnimation *> opacityAnimations_;
    QList<QPropertyAnimation *> radiusAnimations_;
    bool hoverd;
    int borderRadius;
};
#endif // RIPPLEBUTTON_HPP
