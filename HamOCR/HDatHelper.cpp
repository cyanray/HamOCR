#include "HDatHelper.h"
#include <exception>
void HDatHelper::Open(const string & filename)
{
	fp = fopen(filename.data(), "rb+");
	if (fp == nullptr) throw std::exception("Open file failed.");
	char buff[8]{ 0 };
	char t = fread(buff, 8, 1, fp);
	if (strcmp(buff, "HamOCR\n"))
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
	HDat t;
	char str_buff[33];//规定str最多32个字符
	for (size_t i = 0; true; ++i)
	{
		if (feof(fp)) throw std::exception("HDat file format is incorrect.");
		fread(str_buff + i, sizeof(char), 1, fp);
		if (str_buff[i] == '\0') break;
	}
	t.str = string(str_buff);
	//接下来读取"图片标识"的长度
	unsigned int len_buf = 0;
	fread(&len_buf, sizeof(unsigned int), 1, fp);
	t.length = len_buf;
	//接下来读取“图片标识”
	unsigned char *data_buff = new unsigned char[len_buf];
	fread(data_buff, len_buf, 1, fp);
	t.data = data_buff;
	return t;
}

void HDatHelper::AppendOne(HDat & hdat)
{
	fseek(fp, 0, SEEK_END);
	fwrite(hdat.str.data(), hdat.str.length() + 1, 1, fp);
	fwrite(&hdat.length, sizeof(hdat.length), 1, fp);
	fwrite(hdat.data, hdat.length, 1, fp);
}

void HDatHelper::RemoveAll(const string & str)
{
}

void HDatHelper::RemoveAll()
{
}
