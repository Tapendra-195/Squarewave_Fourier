/*#############################################################################
#  Program for Showing simple Fourier series of square wave.                  #
##############################################################################*/

#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdio.h>
#include <opencv2/features2d.hpp>
#include <fstream>

using namespace cv;
using namespace std;
const float PI = acos(-1);

int main(int argc, char **argv){
float t=0;
  vector<float> wave;
  for(;;){
    Mat m = cv::Mat(cv::Size(1000, 1000), CV_64FC3, Scalar(0,250,250));
    float x=500;
    float y=500;
    for(int i=0; i<5; i++){
      float x0=x;
      float y0=y;

      float n = i*2+1;
      float r = 50*(4/(n*PI));
      x += r*cos(n*t);
      y += r*sin(n*t);
      
      //float r=80;
    circle( m, Point( x0, y0 ), r, Scalar(0,0,255), 1, 0 );
    //float x1=r*cos(t);
    //float y1=r*sin(t);;
    
    //circle( m, Point( x1+x0, y1+y0 ), 10, Scalar(0,0,255), 2, 0 );
    line(m,Point(x0,y0), Point(x,y), Scalar(0,255,0),2);
    }    
    wave.push_back(y);
    vector <float> r_wave(wave.rbegin(), wave.rend());
    if (r_wave.size()>500){
      r_wave.pop_back();
      wave.clear();
      wave = vector<float>(r_wave.rbegin(), r_wave.rend());
    }
    for(int i=0; i<r_wave.size();i++){
      circle( m, Point( 580+i, r_wave[i] ), 1, Scalar(0,0,255), 2, 0 );
    }
    line(m,Point(x , y),Point(580, r_wave[0]), Scalar(0,255,0),2);
    imshow("live",m);
    if (waitKey(5) >= 0)
      break;
    
    t+=0.05;
  }
}

