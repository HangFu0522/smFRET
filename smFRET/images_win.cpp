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

	for (size_t i = 0; i < mats.size(); i++)
	{
		cv::equalizeHist(mats[i], mats[i]);
	}

	cv::equalizeHist(mats[0], mats[0]);
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

cv::Mat images_win::getHeatMap(cv::Mat input)
{
	cv::Mat result(input.rows, input.cols, CV_8UC3);
	for (int yy = 0; yy < input.rows; ++yy)
	{
		for (int xx = 0; xx < input.cols; ++xx)
		{
			int pixelValue = input.at<uchar>(yy, xx);
			if (pixelValue < 128) {
				result.at<cv::Vec3b>(yy, xx) = cv::Vec3b(0, 0 + 2 * pixelValue, 255 - 2 * pixelValue);
			}
			else {
				result.at<cv::Vec3b>(yy, xx) = cv::Vec3b(0 + 2 * pixelValue, 255 - 2 * pixelValue, 0);
			}
		}
	}
	return result;
}