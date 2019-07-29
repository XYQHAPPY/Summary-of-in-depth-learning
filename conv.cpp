#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

using namespace  std;
using namespace  cv;

Mat Kernel_test_3_3 = (
	Mat_<double>(3, 3) <<
	0, -1, 0,
	-1, 5, -1,
	0, -1, 0);
void Convlution(Mat  InputImage, Mat  OutputImage, Mat kernel)
{
	//计算卷积核的半径
	int sub_x = kernel.cols / 2;
	int sub_y = kernel.rows / 2;
	//遍历图片  
	for (int image_y = 0; image_y < InputImage.rows - 2 * sub_y; image_y++)
	{
		for (int image_x = 0; image_x < InputImage.cols - 2 * sub_x; image_x++)
		{
			int pix_value = 0;
			for (int kernel_y = 0; kernel_y < kernel.rows; kernel_y++)
			{
				for (int kernel_x = 0; kernel_x < kernel.cols; kernel_x++)
				{
					double  weihgt = kernel.at<double>(kernel_y, kernel_x);
					int value = (int)InputImage.at<uchar>(image_y + kernel_y, image_x + kernel_x);
					pix_value += weihgt*value;
				}
			}
			OutputImage.at<uchar>(image_y + sub_y, image_x + sub_x) = (uchar)pix_value;
		}
	}
}

int main()
{
	Mat srcImage = imread("1.jpg", 0);
	namedWindow("srcImage", WINDOW_AUTOSIZE);
	imshow("原图", srcImage);

	//filter2D卷积
	Mat dstImage_oprncv(srcImage.rows, srcImage.cols, CV_8UC1, Scalar(0));;
	filter2D(srcImage, dstImage_oprncv, srcImage.depth(), Kernel_test_3_3);
	imshow("filter2D卷积图", dstImage_oprncv);
	imwrite("1.jpg", dstImage_oprncv);

	//自定义卷积
	Mat dstImage_mycov(srcImage.rows, srcImage.cols, CV_8UC1, Scalar(0));
	Convlution(srcImage, dstImage_mycov, Kernel_test_3_3);
	imshow("卷积图3", dstImage_mycov);
	imwrite("2.jpg", dstImage_mycov);

	waitKey(0);
	return 0;

}
