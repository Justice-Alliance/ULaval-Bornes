TEMPLATE = app
TARGET = RegistreBorneGUI
QT += core \
    gui
HEADERS += bornefontaineinterface.h \
    registrebornegui.h
SOURCES += bornefontaineinterface.cpp \
    registrebornegui.cpp \
    main.cpp
FORMS += bornefontaineinterface.ui \
    registrebornegui.ui
RESOURCES += 
LIBS += "../Borne/Debug/libBorne.a"
INCLUDEPATH += "../Borne/."
