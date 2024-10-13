#include "settings.hpp"

Settings::Settings() {}

Settings::~Settings() {}

bool Settings::contains(const QString &fileName, const QString &key)
{
    QSettings m_settings(fileName, QSettings::IniFormat);
    return m_settings.contains(key);
}

QVariant Settings::read(const QString &fileName, const QString &key, const QVariant &defaultValue)
{
    QSettings m_settings(fileName, QSettings::IniFormat);
    return m_settings.value(key, defaultValue);
}

void Settings::write(const QString &fileName, const QString &key, const QVariant &value)
{
    QSettings m_settings(fileName, QSettings::IniFormat);
    return m_settings.setValue(key, value);
}
