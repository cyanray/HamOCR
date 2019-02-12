

#include "pch.h"
#include <iostream>
#include <CyImg/Pixels.h>
#include <CyImg/algorithm/t.hpp>
using namespace std;
int main()
{
	using Cyan::mm;
	Pixels img;
	img.LoadFromJpegFile("E:\\verify.jpg");
	mm(img);
	img.SaveAsJpeg("E:\\TestData\\pix.jpg");
	return 0;
}
