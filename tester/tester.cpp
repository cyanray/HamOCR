

#include "pch.h"
#include <iostream>
#include <CyImg/Pixels.h>
using namespace std;
int main()
{
	Pixels img;
	img.LoadFromJpegFile("E:\\verify.jpg");
	img.SaveAsJpeg("E:\\TestData\\pix.jpg");
	return 0;
}
