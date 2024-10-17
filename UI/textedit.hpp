#ifndef TEXTEDIT_HPP
#define TEXTEDIT_HPP

#include <QLabel>
#include <QLineEdit>
#include <QMouseEvent>
#include <QObject>
#include <QPainter>
#include <QPointer>
#include <QPropertyAnimation>
#include <QWidget>

class MyRect : public QObject
{
public:
    Q_OBJECT
    Q_PROPERTY(int width READ getWidth WRITE setWidth NOTIFY widthChanged)

public:
    MyRect(int _x = 0, int _y = 0, int _width = 0, int _height = 0);

    int getWidth() const;
    void setWidth(int newWidth);

    int getHeight() const;
    void setHeight(int newHeight);

    int getX() const;
    void setX(int newX);

    int getY() const;
    void setY(int newY);

signals:
    void widthChanged();

    void heightChanged();

protected:
    int x;
    int y;
    int width;
    int height;
};

class TextEdit : public QLineEdit
{
    Q_OBJECT

public:
    TextEdit(QWidget *parent = nullptr);

    bool isActive() const;
    void setActive(const bool &newActive);

    int getRectWidth() const;
    void setRectWidth(int newRectWidth);

    QColor getActiveColor() const;
    void setActiveColor(const QColor &newActiveColor);

    int getDuration() const;
    void setDuration(int newDuration);

signals:
    void rectWidthChanged();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void focusOutEvent(QFocusEvent *event) override;

private:
    QColor activeColor;
    std::unique_ptr<MyRect> activeRect;
    int xPressPos;
    int duration;
    bool active;
};

#endif // TEXTEDIT_HPP
