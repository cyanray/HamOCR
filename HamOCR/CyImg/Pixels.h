#pragma once
#include "Pixel.h"
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
	~Pixels();
private:
	vector<Pixel> raw;
	unsigned int width;
	unsigned int height;
	unsigned int components;
	Pixels(const Pixels &);//不允许复制
	Pixels & operator=(const Pixels &);//不允许赋值
};

