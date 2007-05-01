#include <QDebug>
#include <QtGui>
#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
	Q_INIT_RESOURCE(static);
	Q_INIT_RESOURCE(qtreal);
	
	
	QApplication app(argc, argv);
	MainWindow window;
	window.show();
	return app.exec();
}
