TEMPLATE = app
TARGET = RegistreBorneGUI
QT += core \
    gui
HEADERS += bornestationnementinterface.h \
    bornefontaineinterface.h \
    registrebornegui.h
SOURCES += bornestationnementinterface.cpp \
    bornefontaineinterface.cpp \
    registrebornegui.cpp \
    main.cpp
FORMS += bornestationnementinterface.ui \
    bornefontaineinterface.ui \
    registrebornegui.ui
RESOURCES += 
LIBS += "../Borne/Debug/libBorne.a"
INCLUDEPATH += "../Borne/."
