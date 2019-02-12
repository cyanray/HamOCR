#include "pch.h"
#include "Pixels.h"
#include "jpegHelper.h"
using std::exception;
Pixels::Pixels()
{
}

void Pixels::LoadFromJpegFile(const string & filename)
{
	unsigned char *imgBuff = nullptr;
	try
	{
		jpegHelper::read_JPEG_file(filename.data(), &imgBuff, width, height, components);
	}
	catch (exception &ex)
	{
		throw ex;
	}
	raw.reserve(width*height);
	size_t length = width * height * components;
	for (size_t i = 0; i < length; i += components)
	{
		raw.push_back(Pixel(imgBuff[i], imgBuff[i + 1], imgBuff[i + 2]));
	}
}

void Pixels::LoadFromJpegBytes(unsigned char bytes[], size_t length)
{
}

void Pixels::SaveAsJpeg(const string & filename)
{
}


Pixels::~Pixels()
{
}