#include "MainWindow.h"
#include <QtWidgets/QApplication>
#include<images_win.h>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	images_win *images=new images_win();
	MainWindow *w=new MainWindow();
	QObject::connect(w, SIGNAL(sendfilename(const QString&)), images, SLOT(openImages(const QString&)));

	w->show();
	


	return a.exec();
}
