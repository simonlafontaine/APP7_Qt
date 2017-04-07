#include <QApplication>
#include "InterfaceQt.h"
#include "Garduino.h"



int main(int argcounter, int argvector) {

	QApplication application(argcounter, argvector);
	Interface interface;
	interface.show();

	return application.exec();
}

