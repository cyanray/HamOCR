#pragma once
#include "HDat.h"
class HDatHelper
{
public:
	HDatHelper() :fp(nullptr) {}
	//��һ��HDat�ļ�
	void Open(const string & filename);
	//��ȡһ��HDat����
	HDat ReadOne();
	//��ĩβ����һ��HDat����
	void AppendOne(HDat &hdat);
	//ɾ����������Ϊstr��HDat����
	void RemoveAll(const string & str);
	//ɾ������HDat����
	void RemoveAll();
	//���Ǳ���ģ����Բ�������
	void Close() 
	{
		if (fp != nullptr) fclose(fp);
		fp = nullptr;
	}
	~HDatHelper() { if (fp != nullptr) fclose(fp); }
private:
	FILE *fp;
};

