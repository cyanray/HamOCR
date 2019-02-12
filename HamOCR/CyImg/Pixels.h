#pragma once
#include "pixel/pixel.h"
#include <vector>
#include <string>
using std::string;
using std::vector;
class Pixels
{
public:
	Pixels();
	void LoadFromJpegFile(const string & filename);
	void LoadFromJpegBytes(unsigned char bytes[], size_t length);
	void SaveAsJpeg(const string & filename);
	vector<Pixel> & GetPixels() { return raw; }
	unsigned char *GetRaw() { return raw_bytes; }
	~Pixels();
private:
	vector<Pixel> raw;
	unsigned int width;
	unsigned int height;
	unsigned int components;
	Pixels(const Pixels &);//��������
	Pixels & operator=(const Pixels &);//������ֵ
};

