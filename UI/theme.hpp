#ifndef THEME_HPP
#define THEME_HPP

#include <QTextStream>
#include <QtCore>

#include "UI/settings.hpp"

class Theme
{
public:
    Theme();

    static Theme &Get()
    {
        static Theme instance;
        return instance;
    }

    QString mainWindow;
    QString titleBarButtons;
    QString titleBarCloseButton;

    void init();
    QString read(const QString &fileName);

private:
    bool darkThemeEnabled;
};

#endif // THEME_HPP
