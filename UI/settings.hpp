#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <QSettings>

class Settings
{
public:
    Settings();
    ~Settings();

    static bool contains(const QString &fileName, const QString &key);
    static QVariant read(const QString &fileName,
                         const QString &key,
                         const QVariant &defaultValue = QVariant());
    static void write(const QString &fileName, const QString &key, const QVariant &value);

private:
};
#endif // SETTINGS_HPP
