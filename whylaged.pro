QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = whylaged
TEMPLATE = app

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

win32 {
  SOURCES += \
      main.cpp \
      mainwindow.cpp \
      ripplebutton.cpp \
      sidebar.cpp \
      title_bar/qwinwidget.cpp \
      title_bar/widget.cpp \
      title_bar/winnativewindow.cpp

  HEADERS += \
      mainwindow.hpp \
      ripplebutton.hpp \
      sidebar.hpp \
      title_bar/OSXHideTitleBar.h \
      title_bar/QWinWidget.h \
      title_bar/widget.h \
      title_bar/winnativewindow.h

  FORMS += \
      mainwindow.ui


  LIBS += -L"C:\Program Files\Microsoft SDKs\Windows\v7.1\Lib" \
          -ldwmapi \
          -lgdi32
}
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
  Resources.qrc

HEADERS += \
  popupdialog.hpp

SOURCES += \
  popupdialog.cpp

FORMS += \
  popupdialog.ui

