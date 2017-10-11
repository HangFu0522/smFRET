#pragma once

#include<QtWidgets/QMainWindow>
#include<QLabel>
#include<QSpinBox>
#include<QSlider>
class QSpinBox;
class QLabel;
class QAction;
class QSlider;
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);

private:
	QSlider *ch1_slider, *ch2_slider,*all_sliper;
	QSpinBox *ch1_spinbox, *ch2_spinbox,*all_spinbox;
	QLabel *title,*ch1_title, *ch2_title, *ch1_frame,*all_frame, *ch2_frame, *ch1, *ch2;

	QMenu *filemenu, *toolmenu;
	//file menu
	QAction *openQAction,*exit;
	QAction *Map,*setdefaultMap;

	//point mean
	QAction *addPoint;

	void creatframe(void);
	void creatmenubar(void);
	void creatAction(void);
	void creattoolbar(void);
	QImage& creatdefault(int w, int h);


};
