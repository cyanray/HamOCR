

#include "pch.h"
#include <iostream>
#include <CyImg/Pixels.h>
//#include <CyImg/algorithm/Hamming/Hamming.hpp>
#include <CyImg/algorithm/Binarize.hpp>
#include <CyImg/algorithm/Split.hpp>
#include <boost/filesystem.hpp>
#include <HamOCR.h>
#include <HDatHelper.h>
using namespace std;
using namespace boost::filesystem;
//void process(const path & p_)
//{
//	using namespace Cyan;
//	string tFileName = p_.stem().string();
//	path pa("E:\\TestData\\splited" / (tFileName + "_a.jpg"));
//	path pb("E:\\TestData\\splited" / (tFileName + "_b.jpg"));
//	path pc("E:\\TestData\\splited" / (tFileName + "_c.jpg"));
//	path pd("E:\\TestData\\splited" / (tFileName + "_d.jpg"));
//	Pixels img;
//	img.LoadFromJpegFile(p_.string());
//	RGB_Binarize(img, 170);
//	auto a = Split(img, 10, 4, 26, 20);
//	auto b = Split(img, 26, 4, 42, 20);
//	auto c = Split(img, 42, 4, 58, 20);
//	auto d = Split(img, 58, 4, 74, 20);
//	a.SaveAsJpeg(pa.string());
//	b.SaveAsJpeg(pb.string());
//	c.SaveAsJpeg(pc.string());
//	d.SaveAsJpeg(pd.string());
//}
int main()
{
	//RGB_Binarize(img2, 170);
	//auto a1 = Split(img, 10, 4, 26, 20);
	//auto a2 = Split(img2, 26, 4, 42, 20);
	//auto a3 = Split(img2, 42, 4, 58, 20);
	//auto a4 = Split(img, 58, 4, 74, 20);
	using namespace Cyan;
	Pixels img;
	img.LoadFromJpegFile("E:\\TestData\\verifyPic\\46.jpg");
	RGB_Binarize(img, 170);
	auto a = Split(img, Point(10, 4), Point(26, 20));
	auto b = Split(img, Point(26, 4), Point(42, 20));
	auto c = Split(img, Point(42, 4), Point(58, 20));
	auto d = Split(img, Point(58, 4), Point(74, 20));

	HamOCR ocr;
	ocr.LoadDataFile("E:\\TestData\\splited\\B.hdat");
	cout << ocr.OCR(a) << ocr.OCR(b) << ocr.OCR(c) << ocr.OCR(d) << endl;
	cin.get();
	return 0;
}
