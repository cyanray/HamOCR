#pragma once
#include <fstream>
#include "HDat.h"
using std::fstream;
class HDatHelper
{
public:
	HDatHelper() {}
	//��һ��HDat�ļ�
	void Open(const string & filename);
	//����һ��HDat�ļ�(���ļ��Ѵ����򸲸�)
	void Create(const string & filename);
	bool AtEOF() { return (hdFile.peek() == EOF) || hdFile.eof(); }
	//��ȡһ��HDat����
	HDat ReadOne();
	//��ĩβ����һ��HDat����
	void AppendOne(HDat &hdat);
	~HDatHelper() { hdFile.close(); }
private:
	fstream hdFile;
};

