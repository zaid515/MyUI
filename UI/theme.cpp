#include "theme.hpp"

Theme::Theme()
    : darkThemeEnabled(false)
{
    darkThemeEnabled = Settings::read("Settings.ini", "DarkThemeEnabled").toBool();
}

void Theme::init()
{
    darkThemeEnabled = Settings::read("Settings.ini", "DarkThemeEnabled").toBool();
    if (darkThemeEnabled) {
        titleBarButtons = read(":/Styles/Dark_Theme/Title_Bar_Buttons.txt");
        titleBarCloseButton = read(":/Styles/Dark_Theme/Title_Bar_Close_Button.txt");
        mainWindow = read(":/Styles/Dark_Theme/MainWindow.txt");
    } else {
        titleBarButtons = read(":/Styles/Light_Theme/Title_Bar_Buttons.txt");
        titleBarCloseButton = read(":/Styles/Light_Theme/Title_Bar_Close_Button.txt");
        mainWindow = read(":/Styles/Light_Theme/Main_Window.txt");
    }
}

QString Theme::read(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly)) {
        file.close();
        return "";
    }
    QTextStream style(&file);
    return style.readAll();
}
