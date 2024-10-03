#ifndef SPINNER_HPP
#define SPINNER_HPP

#include <QPainter>
#include <QPropertyAnimation>
#include <QWidget>

class Spinner : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int degree READ getDegree WRITE setDegree NOTIFY degreeChanged FINAL)

public:
    explicit Spinner(QWidget *parent = nullptr);

    int getDegree() const;
    void setDegree(int newDegree);

    int getSpinnerWidth() const;
    void setSpinnerWidth(int newSpinnerWidth);

    int getDuration() const;
    void setDuration(int newDuration);

    QColor getSpinnerColor() const;
    void setSpinnerColor(const QColor &newSpinnerColor);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QLinearGradient gradient;
    QColor spinnerColor;
    QBrush b;
    int spinnerWidth;
    int duration;
    int degree;

signals:
    void degreeChanged();
};

#endif // SPINNER_HPP
