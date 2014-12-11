BAMBrisk - Binary AsyMmetric Boosted BRISK

Dependencies: OpenCV >2.3

Demo application extracts BAMBrisk features from a couple of images, performs matching and geometric verification, showing the matching features.


Compilation instructions:

- include and link OpenCV
- include directory "src/thirdparty/agast/include/"
- include directory "include/"

How to run BRISK detector and extract BAMBrisk features:

```
	
	#include "BAMBrisk.h"
	#include "brisk/brisk.h"
	#include <opencv2/opencv.hpp>
	#include <opencv2/core/core.hpp>
	#include <opencv2/features2d/features2d.hpp>
	#include <opencv2/imgproc/imgproc.hpp>
	
	int main() {

		cv::BriskFeatureDetector det(60, 4);
		cv::BAMBriskDescriptorExtractor ext();

		Mat img = cv::imread( "image.jpg", CV_LOAD_IMAGE_GRAYSCALE );

		if( !img.data){ 
			std::cout<< " --(!) Error reading image " << std::endl; 
			return -1; 
		}

		std::vector<KeyPoint> keypoints;

		det.detect( img, keypoints );

		Mat descriptors;

		ext.compute( img, keypoints, descriptors );
	
	}
	
```
