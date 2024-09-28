#ifndef TEXTEDIT_HPP
#define TEXTEDIT_HPP

#include <QLineEdit>
#include <QMouseEvent>
#include <QPainter>
#include <QPropertyAnimation>
#include <QWidget>

namespace MyUI {

class MyRect : public QObject
{
    Q_OBJECT
    Q_PROPERTY(uint8_t width READ getWidth WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(uint8_t height READ getHeight WRITE setHeight NOTIFY heightChanged)

public:
    MyRect(uint8_t _x = 0, uint8_t _y = 0, uint8_t _width = 0, uint8_t _height = 0);

    uint8_t getWidth() const;
    void setWidth(const uint8_t &newWidth);

    uint8_t getHeight() const;
    void setHeight(const uint8_t &newHeight);

    uint8_t getX() const;
    void setX(uint8_t newX);

    uint8_t getY() const;
    void setY(uint8_t newY);

signals:
    void widthChanged();

    void heightChanged();

private:
    uint8_t x;
    uint8_t y;
    uint8_t width;
    uint8_t height;
};
} // namespace MyUI

class TextEdit : public QLineEdit
{
    Q_OBJECT
public:
    TextEdit(QWidget *parent = nullptr);

    bool isActive() const;
    void setActive(const bool &newActive);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void focusOutEvent(QFocusEvent *event) override;

private:
    QColor activeColor;
    std::unique_ptr<MyUI::MyRect> activeRect;
    uint8_t xPressPos;
    int rectWidth;
    bool active;
};

#endif // TEXTEDIT_HPP
