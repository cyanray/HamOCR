#include "HDatHelper.h"
#include <exception>
void HDatHelper::Open(const string & filename)
{
	fp = fopen(filename.data(), "rb+");
	if (fp == nullptr) throw std::exception("Open file failed.");
	char buff[8]{ 0 };
	char t = fread(buff, 8, 1, fp);
	if (strcmp(buff,"HamOCR\n"))
	{
		throw std::exception("Not a HDat file.");
	}
}

void HDatHelper::Create(const string & filename)
{
	fp = fopen(filename.data(), "wb+");
	if (fp == nullptr) throw std::exception("Open file failed.");
	char identifier[] = "HamOCR\n";
	fwrite(identifier, sizeof(identifier), 1, fp);
}

HDat HDatHelper::ReadOne()
{
	return HDat();
}

void HDatHelper::AppendOne(HDat & hdat)
{
}

void HDatHelper::RemoveAll(const string & str)
{
}

void HDatHelper::RemoveAll()
{
}
