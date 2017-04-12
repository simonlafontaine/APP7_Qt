#include "InterfaceGarduino.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    InterfaceGarduino w;
    w.show();

    return a.exec();
}
