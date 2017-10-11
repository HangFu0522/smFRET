#include "images_win.h"

images_win::images_win()
{

}
void images_win::openImages(const QString& filename)
{
    ImageandWinName=filename.toStdString();
    cv::imreadmulti(ImageandWinName,mats,0);
    cv::namedWindow(ImageandWinName,cv::WINDOW_NORMAL|cv::WINDOW_KEEPRATIO|CV_GUI_EXPANDED);
    cv::imshow(ImageandWinName,mats[0]);
    cv::waitKey();
    cv::destroyWindow(ImageandWinName);
    mats.swap(std::vector<cv::Mat>());
    v_FRETPoint.swap(std::vector<FRETPoint>());
}
void images_win::showimage_index(int index)
{
    cv::imshow(ImageandWinName, mats[index]);
}

