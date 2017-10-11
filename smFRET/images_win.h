#ifndef IMAGES_WIN_H
#define IMAGES_WIN_H

#include <QObject>
#include<QString>
#include<string>
#include<opencv2/core.hpp>
#include<opencv2/highgui/highgui.hpp>

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
public slots:
    void openImages(const QString& filename);
    void showimage_index(int index);

private:
    std::string ImageandWinName;                                //图像文件和窗口的名字
    std::vector<cv::Mat> mats;                                  //保存的图像
    std::vector<FRETPoint> v_FRETPoint;                         //荧光点的框

};

#endif // IMAGES_WIN_H
