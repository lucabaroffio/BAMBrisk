

#ifndef _BAMBRISK_H_
#define _BAMBRISK_H_

#include <opencv2/features2d/features2d.hpp>
#include <opencv2/core/core.hpp>

static const int _pairs[512] = {182, 201, 221, 641, 677, 714, 752, 311, 336, 77, 66, 65, 76, 39, 38, 30, 31, 32, 25, 19, 14, 13, 18, 24, 23, 17, 12, 51, 52, 53, 44, 43, 42, 41, 50, 8, 9, 108, 123, 139, 140, 157, 158, 176, 177, 159, 534, 502, 471, 441, 442, 472, 503, 535, 568, 602, 197, 196, 216, 217, 218, 638, 603, 569, 536, 504, 161, 144, 143, 160, 178, 179, 180, 162, 145, 34, 35, 36, 239, 238, 251, 252, 618, 653, 1508, 1563, 1619, 1634, 1691, 1710, 1711, 1769, 1770, 1694, 1752, 1753, 861, 902, 903, 945, 946, 989, 890, 932, 918, 961, 393, 366, 340, 104, 103, 93, 94, 381, 409, 410, 439, 124, 109, 10, 83, 71, 60, 59, 280, 49, 5, 6, 70, 329, 355, 382, 95, 110, 411, 440, 470, 501, 141, 125, 126, 127, 128, 113, 112, 111, 412, 97, 98, 151, 135, 120, 119, 134, 84, 72, 118, 367, 394, 395, 464, 435, 434, 420, 392, 960, 917, 875, 889, 848, 847, 833, 793, 792, 832, 846, 887, 888, 874, 338, 313, 754, 753, 1723, 1736, 805, 325, 350, 337, 363, 90, 290, 289, 266, 265, 300, 299, 243, 233, 242, 264, 255, 256, 279, 744, 303, 328, 354, 353, 327, 302, 743, 705, 278, 57, 58, 69, 81, 80, 89, 102, 48, 3, 78, 351, 377, 314, 339, 365, 364, 391, 405, 406, 974, 931, 930, 378, 91, 288, 715, 728, 1678, 1693, 1679, 1737, 806, 820, 1751, 1750, 1692, 1677, 1620, 1564, 690, 654, 275, 274, 261, 284, 285, 64, 712, 675, 240, 262, 263, 713, 751, 286, 287, 676, 640, 605, 200, 181, 163, 229, 230, 650, 651, 687, 688, 725, 740, 703, 702, 1469, 1523, 1578, 1579, 741, 779, 764, 726, 689, 727, 765, 324, 729, 780, 1636, 1635, 1652, 1596, 1595, 1540, 1539, 1485, 1484, 1431, 1430, 1378, 1377, 1326, 1325, 1275, 1274, 1225, 1224, 1176, 1175, 1128, 1127, 1081, 1080, 1035, 1034, 990, 1021, 1020, 1006, 422, 1051, 1097, 451, 481, 152, 169, 170, 153, 513, 545, 546, 514, 1243, 1194, 1146, 483, 484, 485, 516, 548, 1245, 1295, 1346, 581, 580, 579, 189, 188, 171, 454, 453, 424, 423, 1052, 1098, 1145, 482, 452, 1113, 1067, 1066, 1112, 1159, 1160, 1208, 1257, 1258, 1308, 1309, 1294, 1244, 1195, 515, 547, 614, 615, 210, 209, 208, 517, 549, 582, 1347, 1399, 1452, 616, 604, 570, 537, 199, 219, 639, 652, 1507, 1522, 1577, 1521, 666, 665, 583, 617, 1400, 1453, 1468, 1415, 1414, 1362, 1361, 1310, 1260, 1259, 1210, 1209, 1161, 528, 560, 561, 594, 595, 629, 630, 1466, 1467, 1413, 1360, 154, 172, 191, 211, 29, 22, 16, 11, 7, 4, 92, 106, 121, 137, 232, 37, 46, 1, 2, 79, 67, 56, 277, 254, 253, 220, 241, 40, 33, 26, 20, 15, 136, 465, 495, 496, 527, 450, 421, 1005, 1019, 1064, 1065, 1111, 975, 976, 356, 383, 96, 82, 105, 107, 212, 298, 276, 691, 766, 312, 807, 768, 767, 68, 54, 45, 47, 234, 55, 231, 190, 28, 27, 21, 142, 198, 1653};

namespace cv{

class CV_EXPORTS BAMBriskDescriptorExtractor : public cv::DescriptorExtractor{
	public:


		BAMBriskDescriptorExtractor(int dsize = 512, bool rotationInvariant = true, bool scaleInvariant = true, float patternScale = 1.0f);

		virtual ~BAMBriskDescriptorExtractor();

		int descriptorSize() const;
		int descriptorType() const;

		bool _rotationInvariance;
		bool _scaleInvariance;

		// this is the subclass keypoint computation implementation: (not meant to be public - hacked)
		virtual void computeImpl(const Mat& image, std::vector<KeyPoint>& keypoints,
				Mat& descriptors) const;

		//opencv 2.1{
		virtual void compute(const Mat& image, std::vector<KeyPoint>& keypoints, Mat& descriptors) const{
			computeImpl(image,keypoints,descriptors);
		}

	private:

		Ptr<DescriptorExtractor> _ext;

	};

}


#endif //_BAMBRISK_H_