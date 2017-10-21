/****************************************************************
 *
 * www.payitforward.edu.vn
 * 
 ****************************************************************/
/****************************************************************
 *
 * PIF TUTORIALS - Raise Your ARM 2017 - Compiler
 * 
 ****************************************************************/

/****************************************************************
 *
 *	Module		: opencv example
 *	Description	: 
 *  Tool		  : gcc
 *	Platform  : Ubuntu
 * 	History		: 18/10/2017
 *  Version   : 1.0
 *				
 *	Author		: Hong-Hiep Nghiem, Pay It Forward Club
 *	Notes		  :
 *				
 *
 ****************************************************************/
 

 /****************************************************************
 * IMPORT
 ****************************************************************/
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;
 
 /****************************************************************
 * EXTERN
 ****************************************************************/
 
/*none...*/

/*****************************************************************
GLOBAL VARIABLE
******************************************************************/
int s16_max_h = 255;
int s16_max_s = 255;
int s16_max_v = 255;
int s16_min_h = 0;
int s16_min_s = 0;
int s16_min_v = 0;

/*****************************************************************
* ROUTINES
******************************************************************/


/*****************************************************************
 * MAIN
 *****************************************************************/
//Main program
int main (void)
{
  // Create a VideoCapture object to capture image from camera
  // Change the initial parameter to select the right camera
  VideoCapture cap(1);

  // Check if camera is opened successfully
  if(!cap.isOpened()){
    cout << "Error opening video device" << endl;
    return -1;
  }

  namedWindow("Live view", WINDOW_AUTOSIZE);
  namedWindow("Result", WINDOW_AUTOSIZE);
  
  createTrackbar("Min H", "Result", &s16_min_h, 255, NULL);
  createTrackbar("Max H", "Result", &s16_max_h, 255, NULL);
  createTrackbar("Min S", "Result", &s16_min_s, 255, NULL);
  createTrackbar("Max S", "Result", &s16_max_s, 255, NULL);
  createTrackbar("Min V", "Result", &s16_min_v, 255, NULL);
  createTrackbar("Max V", "Result", &s16_max_v, 255, NULL);
  
  while(1){
    // Create object to handle image
    Mat frame;
    Mat hsv_img;
    Mat res_img;
    
    // Get camera frame
    cap >> frame;

    // If the frame object is empty, there is a problem with stream
    if (frame.empty())
      break;

    // Display the current frame
    imshow("Live view", frame);
    
    // Convert to HSV color space
    cvtColor(frame, hsv_img, CV_BGR2HSV);

    // Apply threshold
    inRange(hsv_img, Scalar(s16_min_h, s16_min_s, s16_min_v),
            Scalar(s16_max_h, s16_max_s, s16_max_v), res_img);
    
    // Display the result
    imshow("Result", res_img);
    
    // Get the input from keyboard
    char c = (char)waitKey(25);
    
    // If the ESC key is pressed, terminate program
    if(c==27)
      break;
  }

  // When everything done, release the video capture object
  cap.release();

  // Closes all the frames
  destroyAllWindows();

  return 0;
}

/****************************************************************
 * END OF main.cpp
 ****************************************************************/
