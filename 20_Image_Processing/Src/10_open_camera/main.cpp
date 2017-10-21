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

/*none...*/

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
  VideoCapture cap(0);

  // Check if camera is opened successfully
  if(!cap.isOpened()){
    cout << "Error opening video device" << endl;
    return -1;
  }

  namedWindow("Live view", WINDOW_AUTOSIZE);

  while(1){
    // Create object to handle image
    Mat frame;
    // Get camera frame
    cap >> frame;

    // If the frame object is empty, there is a problem with stream
    if (frame.empty())
      break;

    // Display the current frame
    imshow("Live view", frame);

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
