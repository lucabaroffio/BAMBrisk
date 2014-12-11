//============================================================================
// Name        : Test.cpp
// Author      : Luca Baroffio
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include "BAMBrisk.h"
#include "brisk/brisk.h"

#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;


using namespace cv;

// descriptor size, should be equal to {512, 256, 192, 128, 96, 64}
const int DSIZE = 512;

int main() {

	cv::BriskFeatureDetector det(60, 4);
	cv::BAMBriskDescriptorExtractor ext(DSIZE);

	Mat img_object = cv::imread( "db.jpg", CV_LOAD_IMAGE_GRAYSCALE );
	Mat img_scene = cv::imread( "scene.jpg", CV_LOAD_IMAGE_GRAYSCALE );

	if( !img_object.data || !img_scene.data )
	{ std::cout<< " --(!) Error reading images " << std::endl; return -1; }


	std::vector<KeyPoint> keypoints_object, keypoints_scene;

	det.detect( img_object, keypoints_object );
	det.detect( img_scene, keypoints_scene );

	Mat descriptors_object, descriptors_scene;

	ext.compute( img_object, keypoints_object, descriptors_object );
	ext.compute( img_scene, keypoints_scene, descriptors_scene );

	//-- Step 3: Matching descriptor vectors using FLANN matcher
	Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create("BruteForce-Hamming");
	std::vector< DMatch > matches;
	matcher->match( descriptors_object, descriptors_scene, matches );

	double max_dist = 0; double min_dist = 100;

	std::vector< DMatch > good_matches = matches;


	//-- Localize the object
	std::vector<Point2f> obj;
	std::vector<Point2f> scene;

	for( int i = 0; i < good_matches.size(); i++ )
	{
		//-- Get the keypoints from the good matches
		obj.push_back( keypoints_object[ good_matches[i].queryIdx ].pt );
		scene.push_back( keypoints_scene[ good_matches[i].trainIdx ].pt );
	}


	Mat mask;
	Mat H = findHomography( obj, scene, CV_RANSAC, 8, mask);

	std::vector< DMatch > matches_post_RANSAC;

	int cur_n_matches = 0;
	for (int i = 0; i < mask.rows; i++){
		if ((int)mask.at<uchar>(i, 0) == 1){
			cur_n_matches++;
			matches_post_RANSAC.push_back(good_matches[i]);
		}
	}

	std::cout << cur_n_matches << " matches found!" << std::endl;

	Mat img_matches;
	drawMatches( img_object, keypoints_object, img_scene, keypoints_scene,
			matches_post_RANSAC, img_matches, Scalar::all(-1), Scalar::all(-1),
			vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS );


//	Mat H = cv::findHomography( obj, scene, CV_RANSAC );
//
//	//-- Get the corners from the image_1 ( the object to be "detected" )
//	std::vector<Point2f> obj_corners(4);
//	obj_corners[0] = cvPoint(0,0); obj_corners[1] = cvPoint( img_object.cols, 0 );
//	obj_corners[2] = cvPoint( img_object.cols, img_object.rows ); obj_corners[3] = cvPoint( 0, img_object.rows );
//	std::vector<Point2f> scene_corners(4);
//
//	perspectiveTransform( obj_corners, scene_corners, H);
//
//	//-- Draw lines between the corners (the mapped object in the scene - image_2 )
//	line( img_matches, scene_corners[0] + Point2f( img_object.cols, 0), scene_corners[1] + Point2f( img_object.cols, 0), Scalar(0, 255, 0), 4 );
//	line( img_matches, scene_corners[1] + Point2f( img_object.cols, 0), scene_corners[2] + Point2f( img_object.cols, 0), Scalar( 0, 255, 0), 4 );
//	line( img_matches, scene_corners[2] + Point2f( img_object.cols, 0), scene_corners[3] + Point2f( img_object.cols, 0), Scalar( 0, 255, 0), 4 );
//	line( img_matches, scene_corners[3] + Point2f( img_object.cols, 0), scene_corners[0] + Point2f( img_object.cols, 0), Scalar( 0, 255, 0), 4 );

	//-- Show detected matches
	imshow( "Good Matches", img_matches );

	waitKey(0);

	return 0;

}
