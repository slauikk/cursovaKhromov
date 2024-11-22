QT       += core gui graphs charts network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addoutlaydialog.cpp \
    addprofiledialog.cpp \
    analysisdialog.cpp \
    currentapiservice.cpp \
    exchangedialog.cpp \
    main.cpp \
    mainwindow.cpp \
    outlay.cpp \
    profile.cpp \
    sqlitedbmanager.cpp

HEADERS += \
    addoutlaydialog.h \
    addprofiledialog.h \
    analysisdialog.h \
    currentapiservice.h \
    exchangedialog.h \
    mainwindow.h \
    outlay.h \
    profile.h \
    sqlitedbmanager.h

FORMS += \
    addoutlaydialog.ui \
    addprofiledialog.ui \
    analysisdialog.ui \
    exchangedialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
RC_ICONS = myappico.ico
