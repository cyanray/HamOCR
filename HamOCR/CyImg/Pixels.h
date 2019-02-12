#pragma once
#include "pixel/pixel.h"
#include <vector>
#include <string>
using std::string;
using std::vector;
class Pixels
{
public:
	Pixels() :tRaw(nullptr) {}
	void LoadFromJpegFile(const string & filename);
	void LoadFromJpegBytes(unsigned char bytes[], size_t length);
	void SaveAsJpeg(const string & filename);
	vector<Pixel> & GetPixels() { return raw; }
	const unsigned char *GetRaw();
	~Pixels();
private:
	vector<Pixel> raw;
	unsigned char *tRaw;//����GetRawʱ�����ɵ�bytes�������ÿ�ε��ö���ɾ���ϴ����ɵ�tRaw
	unsigned int width;
	unsigned int height;
	unsigned int components;
	Pixels(const Pixels &);//��������
	Pixels & operator=(const Pixels &);//������ֵ
};

