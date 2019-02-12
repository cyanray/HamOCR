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
	unsigned char *tRaw;//调用GetRaw时，生成的bytes存入这里，每次调用都会删掉上次生成的tRaw
	unsigned int width;
	unsigned int height;
	unsigned int components;
	Pixels(const Pixels &);//不允许复制
	Pixels & operator=(const Pixels &);//不允许赋值
};

