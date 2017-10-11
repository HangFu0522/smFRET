#include "images_win.h"
#include "opencv2/imgproc.hpp"
images_win::images_win()
{

}
void images_win::openImages(const QString& filename)
{
    ImageandWinName=filename.toStdString();
    cv::imreadmulti(ImageandWinName,mats,0);
	emit returnimagesinfo(mats.size());
    cv::namedWindow(ImageandWinName,cv::WINDOW_NORMAL|cv::WINDOW_KEEPRATIO|CV_GUI_EXPANDED);

	cv::equalizeHist(mats[0], mats[0]);
	cv::rotate(mats[0], mats[0], cv::ROTATE_90_CLOCKWISE);
    cv::imshow(ImageandWinName,mats[0]);
    cv::waitKey();
    cv::destroyWindow(ImageandWinName);
    mats.swap(std::vector<cv::Mat>());
    v_FRETPoint.swap(std::vector<FRETPoint>());
}
void images_win::showimage_index(int index)
{
	if (index < mats.size()&& index>0)
	{
		currindex = index;
		cv::imshow(ImageandWinName, mats[currindex]);
	}

}
void images_win::imageRotate(const _Rotate& r)
{
	cv::imshow(ImageandWinName, mats[0]);
	switch(r)
	{
	case _Rotate::R90:
		for (size_t i = 0; i < mats.size(); i++)
		{
			cv::rotate(mats[i], mats[i], cv::ROTATE_90_CLOCKWISE);
		}
		cv::imshow(ImageandWinName, mats[currindex]);
		break;
	case _Rotate::L90:
		for (size_t i = 0; i < mats.size(); i++)
		{
			cv::rotate(mats[i], mats[i], cv::ROTATE_90_COUNTERCLOCKWISE);
		}
		cv::imshow(ImageandWinName, mats[currindex]);
		break;
	}
}
