QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    korpa.cpp \
    kupci.cpp \
    kupi.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    onama.cpp \
    proizvodi.cpp

HEADERS += \
    admin.h \
    connection.h \
    korpa.h \
    kupci.h \
    kupi.h \
    login.h \
    mainwindow.h \
    onama.h \
    proizvodi.h

FORMS += \
    admin.ui \
    korpa.ui \
    kupci.ui \
    kupi.ui \
    login.ui \
    mainwindow.ui \
    onama.ui \
    proizvodi.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    slika.qrc
