#include "Pixels.h"
#include "jpegHelper/jpegHelper.h"
using std::exception;


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
	delete[] imgBuff;
}

void Pixels::LoadFromJpegBytes(unsigned char bytes[], size_t length_)
{
	unsigned char *imgBuff = nullptr;
	try
	{
		jpegHelper::ReadFromBytes(bytes,length_, &imgBuff, width, height, components);
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
	delete[] imgBuff;
}

void Pixels::SaveAsJpeg(const string & filename)
{
	try
	{
		jpegHelper::SaveTo(filename.data(), GetRaw(), width, height, 100);
	}
	catch (exception &ex)
	{
		throw ex;
	}
}


const unsigned char * Pixels::GetRaw()
{
	delete[] tRaw;//ɾ���ϴε�tRaw
	tRaw = new unsigned char[width * height * components]{ 0 };
	unsigned int i = 0;
	for (auto p : raw)
	{
		(tRaw)[i] = p.R();
		(tRaw)[i + 1] = p.G();
		(tRaw)[i + 2] = p.B();
		i += components;//��������ì�ܰ���components�ѵ����Ǳ�Ȼ��3��?
	}
	return tRaw;
}

Pixels::~Pixels()
{
	delete[] tRaw;//ɾ���ϴε�tRaw
}