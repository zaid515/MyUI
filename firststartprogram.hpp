#ifndef FIRSTSTARTPROGRAM_HPP
#define FIRSTSTARTPROGRAM_HPP

#include <QDialog>
#include <QGraphicsDropShadowEffect>
#include <QGraphicsEllipseItem>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QPropertyAnimation>
namespace Ui {
class FirstStartProgram;
}

class MyEllipse : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int x READ getX WRITE setX NOTIFY xChanged)
    Q_PROPERTY(int y READ getY WRITE setY NOTIFY yChanged)
    Q_PROPERTY(int radius READ getRadius WRITE setRadius NOTIFY radiusChanged)
    Q_PROPERTY(int width READ getWidth WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(int height READ getHeight WRITE setHeight NOTIFY heightChanged)

public:
    MyEllipse(QWidget *parent);
    ~MyEllipse();
    QGraphicsEllipseItem *ellipse;

    int getX() const;
    void setX(const int &newX);

    int getY() const;
    void setY(const int &newY);

    int getRadius() const;
    void setRadius(const int &newRadius);

    int getWidth() const;
    void setWidth(const int &newWidth);

    int getHeight() const;
    void setHeight(const int &newHeight);

signals:
    void xChanged();
    void yChanged();
    void radiusChanged();
    void widthChanged();
    void heightChanged();

private:
    int width;
    int height;
    int x;
    int y;
    int radius;
    QPoint parentCenter;
};

class FirstStartProgram : public QDialog
{
    Q_OBJECT

public:
    explicit FirstStartProgram(QWidget *parent = nullptr);
    ~FirstStartProgram();

private:
    Ui::FirstStartProgram *ui;
    QGraphicsScene *scene;
    QPropertyAnimation animation;
    QPropertyAnimation shadowAnimation;
};

#endif // FIRSTSTARTPROGRAM_HPP
