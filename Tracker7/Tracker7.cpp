////Trakcer7.cpp
//#include <opencv/cvaux.h>
//#include <opencv/highgui.h>
//#include <opencv/cxcore.h>
//
//#include <stdio.h>
//#include <stdlib.h>
//
//
////////////////////////////////////
//int main(int argc,char* argv[]){
//
//	CvSize size640x480=cvSize(640,480);  //use a 640x480 size for all windos ,also make sure your web cam is set  to this 
// 
//	CvCapture* p_capWebcam;  //to assign web cam video stream
//
//	IplImage* p_imgOriginal; //pointer to an image structer,this will be the input image from the web cam
//	IplImage* p_imgProcessed;//pointer to an image structer ,this will be the processed image
//
//	CvMemStorage* p_strStorage;       //necessary strorage variable to pass into cvHoughCircles()
//
//	CvSeq* p_seqCircles;  //Pointer to an openCV sequence,will be returented by cvHough circles() and will contain all circles
//							//CALL CVGETsEQeLEM(p_seqCircles
//
//
//	float* p_fltXYRadius;  //point to a 3 element array of floats
//							//[0] ==> x position of detected object
//							//[1] ==> y position of detected objecct
//							//[2] ==> radius of detected objecct
//
//	int i;//loop counter
//	int charCheckForEscKey;
//	p_capWebcam=cvCaptureFromCAM(0);//0=> 1st web camm ,may have to change to different number if you have multiple cameras
//
//	if(p_capWebcam == NULL){ //if caputure was not successfull
//		printf("error : capture is null \n");//error message to standard out
//		getchar();//getChar() to pause for user see messags
//		return -1;//exit program
//
//	}
//
//	//declare two windows
//	cvNamedWindow("Original",CV_WINDOW_AUTOSIZE);//original image from web cam
//	cvNamedWindow("Processed",CV_WINDOW_AUTOSIZE);//the processed image will use for detecting circles
//
//	p_imgProcessed=cvCreateImage(size640x480,//640 x 480 pixels(Cvsize struct from earlier
//										IPL_DEPTH_8U,//8-bit colot depth
//										1);//1 channel (grayscale)if this was a color image use 3
//
//	while(1){//for each frame
//		p_imgOriginal=cvQueryFrame(p_capWebcam); //get frame from cam
//
//		if(p_imgOriginal ==NULL){ //if frame was not captures successfully
//			printf("Error ,Frame is null\n");
//			getchar();
//			break;
//		}
//
//
//		cvInRangeS(p_imgOriginal,  //function input
//						CV_RGB(175,0,0),
//							CV_RGB(256,100,100),//max filteritng valueif color is less than this
//							p_imgProcessed);//function input
//
//		p_strStorage=cvCreateMemStorage(0); //allocate neccesary memroy storage to pass into cvHoughCircles()
//
//
//		//smooth the processed image .this will make it easier for the next function t pick out the circles
//
//		cvSmooth(p_imgProcessed,//function input
//				p_imgProcessed,//function output
//				CV_GAUSSIAN,  //use gaussian filter (avearge nearby pixles ,with closest pixexls weighted more)
//				9,	//smoothig filter window width
//				9);//smoothig filter window height
//
//
//							//fill sequential with all circles in processed image
//		p_seqCircles =cvHoughCircles(p_imgProcessed, 			//input image ,note that this hass to be grayscale(no color)
//									p_strStorage,//provide function with memory storage ,makes function return a pointer to a CvSeq
//									CV_HOUGH_GRADIENT,//two-pass algorithm for detecting circles.this is the only choice availabel
//									2,	//size of image./ 2= "accuulator resolution".i.e accum=res=size of image/2
//									p_imgProcessed->height/4,//min distance in pixels between the centers of the detected ircles
//									100,			//high threshold of canny edge detector.called  by cvHoughCircles
//									50,				//low threshold of canny edge detector.called  by cvHoughCircles
//									10,				//min circle radius ,inpixels
//									400);			//max circle radius ,inpixels
//
//		for(i=0;i<p_seqCircles->total;i++){//for each element in sequential circles structre(i.e for each object detected)
//
//			p_fltXYRadius=(float*)cvGetSeqElem(p_seqCircles,i);//for the sequential structre ,read the ith value into a pointer to a float
//
//			printf("ball position x= %f, y =%f ,r =%f \n",p_fltXYRadius[0],	//x position of center point of circle
//															p_fltXYRadius[1],//y position of center point to circle
//															p_fltXYRadius[2]); //radius of circle
//
//
//															//draw a small green circle at center of detected object 
//		 cvCircle(p_imgOriginal,   //draw on the original image
//					cvPoint(cvRound(p_fltXYRadius[0]),cvRound(p_fltXYRadius[1])), //center point of circle
//					 3,	//3 pixel radius of circle
//					 CV_RGB(0,255,0),  //draw pure green
//					 CV_FILLED);  //thikness fill in the circle
//
//		 //draw red circle around the detected object  
//		 cvCircle(p_imgOriginal,
//			 cvPoint(cvRound(p_fltXYRadius[0]),cvRound(p_fltXYRadius[1])), //center point of circle
//			 cvRound(p_fltXYRadius[2]),
//			 CV_RGB(0,255,0),  //draw pure red
//			  3);  //thikness of circle in pixels
//
//		}//end for
//
//
//		cvShowImage("Original",p_imgOriginal);//original image with detected ball overlay
//		cvShowImage("Processed",p_imgProcessed);//image after processing
//
//
//		cvReleaseMemStorage(&p_strStorage);//deallocate necessary storage variable to pass into CVHoughCircles
//
//
//		charCheckForEscKey=cvWaitKey(10);
//
//		if(charCheckForEscKey ==27) break;
//
//	}	
//
//	cvReleaseCapture(&p_capWebcam);
//
//	cvDestroyWindow("Original");
//		cvDestroyWindow("Processed");
//		return(0);
//
//}