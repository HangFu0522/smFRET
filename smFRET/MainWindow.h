#pragma once

#include<QtWidgets/QMainWindow>
#include<QLabel>
#include<QSpinBox>
#include<QSlider>
#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include<QPixmap>
#include<QFileDialog>
#include<QMenuBar>


#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>

#include<string>


#include<some_constants.h>
class QSpinBox;
class QLabel;
class QAction;
class QSlider;
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);


signals:
void sendfilename(const QString& filename);
void imageRotate(const _Rotate& r);
void showimagebyindex(int index);


private:
	QSlider *ch1_slider, *ch2_slider,*all_sliper;
	QSpinBox *ch1_spinbox, *ch2_spinbox,*all_spinbox;
	QLabel *title,*ch1_title, *ch2_title, *ch1_frame,*all_frame, *ch2_frame, *ch1, *ch2;


	QMenu *SrcImg, *imrotate;
	QAction *adjust,*rotateL90,*rotateR90;

	//file menu
	QMenu *filemenu;
	QAction *openQAction,*exit;

	QMenu *toolmenu;
	QAction *Map,*setdefaultMap;

	QAction *addPoint;

	void creatframe(void);
	void creatmenubar(void);
	void creatAction(void);
	void creattoolbar(void);
	QImage& creatdefault(int w, int h);

private slots:	
	void openimages_sucess(const int num);


	void on_openQAction_triggered(void);
	void on_rotateL90_triggered(void);
	void on_rotateR90_triggered(void);
};
