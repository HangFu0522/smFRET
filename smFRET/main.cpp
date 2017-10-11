#include "MainWindow.h"
#include <QtWidgets/QApplication>
#include<images_win.h>
#include<some_constants.h>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	images_win *images = new images_win();
	MainWindow *w = new MainWindow();
	QObject::connect(w, SIGNAL(sendfilename(const QString&)), images, SLOT(openImages(const QString&)));
	QObject::connect(images, SIGNAL(returnimagesinfo(const int)), w, SLOT(openimages_sucess(const int)));
	QObject::connect(w, SIGNAL(imageRotate(const _Rotate&)), images, SLOT(imageRotate(const _Rotate&)));
	QObject::connect(w, SIGNAL(showimagebyindex(int)), images, SLOT(showimage_index(int)));



	w->show();
	


	return a.exec();
}
