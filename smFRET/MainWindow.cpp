#include<MainWindow.h>


MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	creatframe();
	creatAction();
	creatmenubar();
}

void MainWindow::creatframe(void)
{
	QImage defaultimg = creatdefault(256, 512);
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

	//设置帧滚动条
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

	QVBoxLayout *mainfretlayout = new QVBoxLayout;
	mainfretlayout->addWidget(title);
	mainfretlayout->addLayout(fret_win);
	mainfretlayout->addLayout(all_framelayout);
	mainfretlayout->addLayout(ch1_framelayout);
	mainfretlayout->addLayout(ch2_framelayout);



	QHBoxLayout *mainlayout = new QHBoxLayout;

	mainlayout->addLayout(mainfretlayout);
	cenwid->setLayout(mainlayout);
	setCentralWidget(cenwid);
}

QImage& MainWindow::creatdefault(int width, int height)
{
	QImage *grayImg;
	int bytePerLine = (width * 3 * 8 + 31) / 8;//图像每行4字节对齐

	auto graydata = new unsigned char[bytePerLine*height];//存储处理后的数据

	unsigned char r, g, b;
	for (int i = 0; i<height; i++)
	{
		for (int j = 0; j<width; j++)
		{
			graydata[i*bytePerLine + j * 3] = (unsigned char)(i/2);
			graydata[i*bytePerLine + j * 3 + 1] = (unsigned char)j;
			graydata[i*bytePerLine + j * 3 + 2] = 128;
		}
	}
	grayImg = new QImage(graydata, width, height, bytePerLine, QImage::Format_RGB888);
	return (*grayImg);
}

void MainWindow::creatAction(void)
{
	openQAction = new QAction(tr("&Open"));
	connect(openQAction, SIGNAL(triggered()), this, SLOT(openimages()));

	Map = new QAction(tr("&Map"));

	rotateL90 = new QAction(tr("&L90"));
	rotateR90 = new QAction(tr("&R90"));
}
void MainWindow::openimages(void)
{
	QString filename = QFileDialog::getOpenFileName(this, "open FRET files", ".", "FRET files (*.tif)");
	if (!filename.isEmpty())
	{
		title->setText(filename);
		SrcImg->setEnabled(true);
		emit sendfilename(filename);
	}
}

void MainWindow::creatmenubar(void)
{
	filemenu = menuBar()->addMenu(tr("&File"));
	filemenu->addAction(openQAction);


	toolmenu = menuBar()->addMenu(tr("&Tool"));
	toolmenu->addAction(Map);


	SrcImg =menuBar()->addMenu(tr("&SrcImg"));
	imrotate = SrcImg->addMenu(tr("&Image Rotate"));
	imrotate->addAction(rotateL90);
	imrotate->addAction(rotateR90);


	//SrcImg->setEnabled(false);

}