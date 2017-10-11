#ifndef IMAGES_WIN_H
#define IMAGES_WIN_H

#include <QObject>
#include<QString>
#include<string>
#include<opencv2/core.hpp>
#include<opencv2/highgui/highgui.hpp>


#include<some_constants.h>

enum FRET_TYPE{Donator,Acceptor};
typedef struct _FRETPoint
{
    cv::Rect ROI;
    FRET_TYPE PointType;
}FRETPoint;
class images_win:public QObject
{
    Q_OBJECT
public:
    images_win();
signals:
	void returnimagesinfo(const int num);
public slots:
    void openImages(const QString& filename);
    void showimage_index(int index);
	void imageRotate(const _Rotate& r);
private:
	int currindex = 0;
    std::string ImageandWinName;                                //图像文件和窗口的名字
    std::vector<cv::Mat> mats;                                  //保存的图像
    std::vector<FRETPoint> v_FRETPoint;                         //荧光点的框

};

#endif // IMAGES_WIN_H
