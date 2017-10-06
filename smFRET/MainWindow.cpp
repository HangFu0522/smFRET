#include<MainWindow.h>
#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include<QPixmap>
#include<QFileDialog>
MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	creatframe();
}

void MainWindow::creatframe(void)
{
	QImage defaultimg("default.png");
	QWidget *cenwid = new QWidget(this);


	title = new QLabel;
	title->setText("FRET");
	ch1_title = new QLabel;
	ch1_title->setText("CH1");
	ch2_title = new QLabel;
	ch2_title->setText("CH2");

	ch1 = new QLabel;
	ch2 = new QLabel;
	ch1->resize(256, 512);
	ch1->setPixmap(QPixmap::fromImage(defaultimg));
	ch2->resize(256, 512);
	ch2->setPixmap(QPixmap::fromImage(defaultimg));


	QVBoxLayout *ch1_win = new QVBoxLayout;
	ch1_win->addWidget(ch1_title);
	ch1_win->addWidget(ch1);
	QVBoxLayout *ch2_win = new QVBoxLayout;
	ch2_win->addWidget(ch2_title);
	ch2_win->addWidget(ch2);
	QHBoxLayout *fret_win = new QHBoxLayout;
	fret_win->addLayout(ch1_win);
	fret_win->addLayout(ch2_win);

	//ÉèÖÃÖ¡¹ö¶¯Ìõ
	ch1_frame = new QLabel;
	ch1_frame->setText("CH1");
	ch1_spinbox = new QSpinBox;
	ch1_slider = new QSlider(Qt::Horizontal);
	ch1_spinbox->setRange(0, 130);
	ch1_slider->setRange(0, 130);
	QHBoxLayout *ch1_framelayout = new QHBoxLayout;
	ch1_framelayout->addWidget(ch1_frame);
	ch1_framelayout->addWidget(ch1_spinbox);
	ch1_framelayout->addWidget(ch1_slider);

	connect(ch1_slider, SIGNAL(valueChanged(int)), ch1_spinbox, SLOT(setValue(int)));
	connect(ch1_spinbox, SIGNAL(valueChanged(int)), ch1_slider, SLOT(setValue(int)));
	ch1_slider->setEnabled(false);
	ch1_spinbox->setEnabled(false);

	ch2_frame = new QLabel;
	ch2_frame->setText("CH2");
	ch2_spinbox = new QSpinBox;
	ch2_slider = new QSlider(Qt::Horizontal);
	ch2_spinbox->setRange(0, 130);
	ch2_slider->setRange(0, 130);
	QHBoxLayout *ch2_framelayout = new QHBoxLayout;
	ch2_framelayout->addWidget(ch2_frame);
	ch2_framelayout->addWidget(ch2_spinbox);
	ch2_framelayout->addWidget(ch2_slider);
	connect(ch2_slider, SIGNAL(valueChanged(int)), ch2_spinbox, SLOT(setValue(int)));
	connect(ch2_spinbox, SIGNAL(valueChanged(int)), ch2_slider, SLOT(setValue(int)));
	ch2_slider->setEnabled(false);
	ch2_spinbox->setEnabled(false);


	all_frame = new QLabel;
	all_frame->setText("ALL");
	all_sliper = new QSlider(Qt::Horizontal);
	all_spinbox = new QSpinBox;
	all_spinbox->setRange(0, 130);
	all_sliper->setRange(0, 130);
	QHBoxLayout *all_framelayout = new QHBoxLayout;
	all_framelayout->addWidget(all_frame);
	all_framelayout->addWidget(all_spinbox);
	all_framelayout->addWidget(all_sliper);
	connect(all_sliper, SIGNAL(valueChanged(int)), ch1_slider, SLOT(setValue(int)));
	connect(all_spinbox, SIGNAL(valueChanged(int)), ch1_slider, SLOT(setValue(int)));
	connect(all_sliper, SIGNAL(valueChanged(int)), ch2_slider, SLOT(setValue(int)));
	connect(all_spinbox, SIGNAL(valueChanged(int)), ch2_slider, SLOT(setValue(int)));
	connect(all_sliper, SIGNAL(valueChanged(int)), all_spinbox, SLOT(setValue(int)));
	connect(all_spinbox, SIGNAL(valueChanged(int)), all_sliper, SLOT(setValue(int)));
	all_sliper->setEnabled(false);
	all_spinbox->setEnabled(false);

	QVBoxLayout *mainlayout = new QVBoxLayout;
	mainlayout->addWidget(title);
	mainlayout->addLayout(fret_win);
	mainlayout->addLayout(ch1_framelayout);
	mainlayout->addLayout(ch2_framelayout);
	mainlayout->addLayout(all_framelayout);


	cenwid->setLayout(mainlayout);
	setCentralWidget(cenwid);
	//setFixedSize(this->width(), this->height());
}