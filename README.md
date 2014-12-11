BAMBrisk - Binary AsyMmetric Boosted BRISK


<a href="http://home.deib.polimi.it/tagliasa/publications/2014/2014_ICIP_Tagliasacchi_1.pdf">L. Baroffio, M. Cesana, A. Redondi, and M. Tagliasacchi, “BAMBOO: a fast descriptor based on asymmetric pairwise boosting,” in IEEE international conference on image processing (ICIP), 2014. </a>

```bibtex
@inproceedings{baroffio:2014:ICIP:BAMBOO,
	title={BAMBOO: A Fast Descriptor Based on Asymmetric Pairwise Boosting},
	author={Baroffio, Luca and Cesana, Matteo and Redondi, Alessandro and Tagliasacchi, Marco},
	booktitle={IEEE International Conference on Image Processing (ICIP)},
	year={2014},
	month = {October},
}
```

Dependencies: OpenCV >2.3

Demo application extracts BAMBrisk features from a couple of images, performs matching and geometric verification, showing the matching features.


Compilation instructions:

- include and link OpenCV
- include directory "src/thirdparty/agast/include/"
- include directory "include/"

How to run BRISK detector and extract BAMBrisk features:

```C
	
	    #include "BAMBrisk.h"
	    #include "brisk/brisk.h"
	    #include <opencv2/opencv.hpp>
	    #include <opencv2/core/core.hpp>
	    #include <opencv2/features2d/features2d.hpp>
	    #include <opencv2/imgproc/imgproc.hpp>

	using namespace cv;

	    int main() {

	        cv::BriskFeatureDetector det(60, 4);
	        cv::BAMBriskDescriptorExtractor ext(512);

	        Mat img = cv::imread( "scene.jpg", CV_LOAD_IMAGE_GRAYSCALE );

	        if( !img.data){
	            std::cout<< " --(!) Error reading image " << std::endl;
	            return -1;
	        }

	        std::vector<KeyPoint> keypoints;

	        det.detect( img, keypoints );

	        Mat descriptors;

	        ext.compute( img, keypoints, descriptors );

	        return 0;
		}
	
	
```
