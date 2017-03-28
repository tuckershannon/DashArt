/**************************************************************
* DASH STYLE ART BY TUCKER SHANNON
***************************************************************/

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>


using namespace cv;
using namespace std;
			
int main(){
	int ncols,point;
	string filename;

	cout << "Photo name with extension: ";		
	cin >> filename;

	Mat image = imread(filename, CV_LOAD_IMAGE_COLOR); //reading in the image
	cout << "Columns wide (standard 60): ";
 	cin >> ncols;
	Mat blank(20*(ncols*((double) image.rows/image.cols)),ncols*20,CV_8UC3,Scalar(255,255,255));
	resize(image, image,Size(ncols,(ncols*((double) image.rows/image.cols))));

	Mat imageRef = image;
	cvtColor( image, image, CV_BGR2GRAY ); //converting to grayscale for easier analysis
   for (int y = 0; y < image.rows; y++) {        
		for (int x = 0; x < image.cols; x++){     
			point = (int) image.at<uchar>(Point(x, y));
			if (point <= 40 ){		
				line(blank,Point(x*20,y*20),Point(x*20+20,y*20+20),Scalar(0,0,0),3,8); 
				line(blank,Point(x*20+20,y*20),Point(x*20,y*20+20),Scalar(0,0,0),3,8);
			}
			if (point > 40 && point <= 155){
				line(blank,Point(x*20,y*20),Point(x*20+20,y*20+20),Scalar(0,0,0),3,8);
			}
  }  
}	
	cout << "Name of save (no extension): ";		
	cin >> filename;

	imwrite(filename+".png",blank);
	return 0;

}
