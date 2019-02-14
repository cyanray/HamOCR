#include "HDatHelper.h"
#include <exception>
void HDatHelper::Open(const string & filename)
{
	hdFile.open(filename, fstream::in | fstream::out | fstream::binary);
	if (!hdFile.is_open()) throw std::exception("Open file failed.");
	char buff[8]{ 0 };
	hdFile.read(buff, 8);
	if (strcmp(buff, "HamOCR\n"))
	{
		throw std::exception("Not a HDat file.");
	}
}

void HDatHelper::Create(const string & filename)
{
	hdFile.open(filename, fstream::in | fstream::out | fstream::binary | fstream::trunc);
	if (!hdFile.is_open()) throw std::exception("Open file failed.");
	char identifier[] = "HamOCR\n";
	hdFile.write(identifier, sizeof(identifier));
}

HDat HDatHelper::ReadOne()
{
	HDat t;
	char str_buff[33];//�涨str���32���ַ�
	for (size_t i = 0; true; ++i)
	{
		if (AtEOF()) throw std::exception("HDat file format is incorrect.");
		hdFile.read(str_buff + i, 1);
		if (str_buff[i] == '\0') break;
	}
	t.str = string(str_buff);
	//��������ȡ"ͼƬ��ʶ"�ĳ���

	unsigned int len_buff = 0;
	hdFile.read((char *)&len_buff, sizeof(len_buff));
	t.length = len_buff;
	//��������ȡ��ͼƬ��ʶ��
	unsigned char *data_buff = new unsigned char[len_buff];
	hdFile.read((char *)data_buff, len_buff);
	t.data = data_buff;
	return t;
}

void HDatHelper::AppendOne(HDat & hdat)
{
	hdFile.seekg(0, hdFile.end);
	hdFile.write(hdat.str.data(), hdat.str.length() + 1);
	hdFile.write((char *)&hdat.length, sizeof(hdat.length));
	hdFile.write((char *)hdat.data, hdat.length);
}

