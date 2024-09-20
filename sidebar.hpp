#ifndef SIDEBAR_HPP
#define SIDEBAR_HPP

#include <QPropertyAnimation>
#include <QPushButton>
#include <QStyleOptionButton>
#include <QStylePainter>
#include <QWidget>

namespace MyUI {
enum class Layout { Vertical = 0, Horizontal };
enum class OpenDirction { ToRight = 0, ToLeft, ToTop, ToBottom };
} // namespace MyUI

class SideBar : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int x READ getX WRITE setX NOTIFY xChanged)
    Q_PROPERTY(int y READ getY WRITE setY NOTIFY yChanged)

public:
    explicit SideBar(QWidget *parent = nullptr);

    MyUI::Layout getLayout() const;
    void setLayout(const MyUI::Layout &newLayout);

    MyUI::OpenDirction getOpenDirction() const;
    void setOpenDirction(const MyUI::OpenDirction &newOpenDirction);

    int getX() const;
    void setX(const int &newX);

    int getY() const;
    void setY(const int &newY);

    void openSideBar();
    void setOpenButtton(QPushButton *button);

    int getOpenDuration() const;
    void setOpenDuration(int newOpenDuration);

private:
    int x;
    int y;
    int openDuration;
    MyUI::Layout layout;
    MyUI::OpenDirction openDirction;
    bool openStat = false;

protected:
    void paintEvent(QPaintEvent *event) override;

signals:
    void xChanged();
    void yChanged();
};

#endif // SIDEBAR_HPP
