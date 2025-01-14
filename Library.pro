QT       += core gui sql widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addbook.cpp \
    addclient.cpp \
    addreport.cpp \
    books.cpp \
    clients.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    addbook.h \
    addclient.h \
    addreport.h \
    books.h \
    clients.h \
    mainwindow.h

FORMS += \
    addbook.ui \
    addclient.ui \
    addreport.ui \
    books.ui \
    clients.ui \
    mainwindow.ui

win32:RC_FILE = rcfile.rc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
