#pragma once

#include <QtWidgets/QMainWindow>
#include<qlabel.h>

class QLabel;
class QAction;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);

private:
	QAction *newQAction;
};
