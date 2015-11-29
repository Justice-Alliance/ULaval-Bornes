#include <QtGui>
#include <QApplication>
#include "registrebornegui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RegistreBorneGUI w;
    w.show();
    return a.exec();
}
