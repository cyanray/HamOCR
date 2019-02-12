

#include "pch.h"
#include <iostream>
#include <CyImg/Pixels.h>
#include <CyImg/algorithm/t.hpp>
using namespace std;
int main()
{
	using Cyan::mm;
	using Cyan::sub;
	Pixels img;
	img.LoadFromJpegFile("E:\\verify.jpg");
	mm(img);
	auto a1 = sub(img, 10, 4, 26, 20);
	auto a2 = sub(img, 26, 4, 42, 20);
	auto a3 = sub(img, 42, 4, 58, 20);
	auto a4 = sub(img, 58, 4, 74, 20);
 	img.SaveAsJpeg("E:\\TestData\\pix.jpg");
	a1.SaveAsJpeg("E:\\TestData\\a1.jpg");
	a2.SaveAsJpeg("E:\\TestData\\a2.jpg");
	a3.SaveAsJpeg("E:\\TestData\\a3.jpg");
	a4.SaveAsJpeg("E:\\TestData\\a4.jpg");
	return 0;
}
