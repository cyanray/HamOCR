

#include "pch.h"
#include <iostream>
#include <CyImg/Pixels.h>
#include <CyImg/algorithm/Hamming/Hamming.hpp>
#include <CyImg/algorithm/Binarize.hpp>
#include <CyImg/algorithm/Split.hpp>
using namespace std;
int main()
{
	using Cyan::RGB_Binarize;
	using Cyan::Point;
	using Cyan::Split;
	Pixels img;
	img.LoadFromJpegFile("E:\\verify.jpg");
	Pixels img2;
	img2.LoadFromJpegFile("E:\\TestData\\8.jpg");
	RGB_Binarize(img, 170);
	RGB_Binarize(img2, 170);
	auto a1 = Split(img, 10, 4, 26, 20);
	auto a2 = Split(img2, 26, 4, 42, 20);
	auto a3 = Split(img2, 42, 4, 58, 20);
	auto a4 = Split(img, 58, 4, 74, 20);
	img2.SaveAsJpeg("E:\\TestData\\pix.jpg");
	a1.SaveAsJpeg("E:\\TestData\\a1.jpg");
	a2.SaveAsJpeg("E:\\TestData\\a2.jpg");
	a3.SaveAsJpeg("E:\\TestData\\a3.jpg");
	a4.SaveAsJpeg("E:\\TestData\\a4.jpg");
	auto ham1 = Cyan::CalcHamming(a1, a2);
	auto ham2 = Cyan::CalcHamming(a2, a3);
	auto ham3 = Cyan::CalcHamming(a1, a4);
	cout << ham1 << " " << ham2 << " " << ham3 << endl;
	cin.get();
	return 0;
}
