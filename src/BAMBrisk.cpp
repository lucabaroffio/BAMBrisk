/* BAMBrisk - Binary AsyMmetric BRISK
 * BAMBrisk.cpp
 *
 *
 *      Author: lucabaroffio
 */

#include <opencv2/features2d/features2d.hpp>
#include <opencv2/core/core.hpp>
#include "BAMBrisk.h"
#include "brisk/brisk.h"

using namespace cv;

BAMBriskDescriptorExtractor::BAMBriskDescriptorExtractor(int dsize, bool rotationInvariant, bool scaleInvariant, float patternScale){

	assert((dsize == 512)||(dsize == 256)||(dsize == 128)||(dsize == 64));
	_scaleInvariance = scaleInvariant;
	_rotationInvariance = rotationInvariant;

	std::vector<int> pairs(_pairs, _pairs + dsize);

	_ext = new BriskDescriptorExtractor(pairs, rotationInvariant, scaleInvariant);

}


void BAMBriskDescriptorExtractor::computeImpl(const Mat& image,
		std::vector<KeyPoint>& keypoints, Mat& descriptors) const{

	_ext->compute(image, keypoints, descriptors);

}

int BAMBriskDescriptorExtractor::descriptorSize() const{
	return _ext->descriptorSize();
}

int BAMBriskDescriptorExtractor::descriptorType() const{
	return _ext->descriptorType();
}

BAMBriskDescriptorExtractor::~BAMBriskDescriptorExtractor(){
}


