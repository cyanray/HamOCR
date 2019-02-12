#include "Pixels.h"
#include "jpegHelper/jpegHelper.h"
using std::exception;
Pixels::Pixels()
{
}

void Pixels::LoadFromJpegFile(const string & filename)
{
	unsigned char *imgBuff = nullptr;
	try
	{
		jpegHelper::ReadFromFile(filename.data(), &imgBuff, width, height, components);
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
	raw_bytes = imgBuff;
}

void Pixels::LoadFromJpegBytes(unsigned char bytes[], size_t length)
{
	unsigned char *imgBuff = nullptr;
	try
	{
		jpegHelper::ReadFromBytes(bytes,length, &imgBuff, width, height, components);
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
	raw_bytes = imgBuff;
}

void Pixels::SaveAsJpeg(const string & filename)
{
	try
	{
		jpegHelper::SaveTo(filename.data(), raw_bytes, width, height, 100);
	}
	catch (exception &ex)
	{
		throw ex;
	}
}


Pixels::~Pixels()
{
	delete[] raw_bytes;
}