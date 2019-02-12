#pragma once
#include "pixel/pixel.h"
#include <vector>
#include <string>
using std::string;
using std::vector;
class Pixels
{
public:
	Pixels() :tRaw(nullptr),components(3) {}
	Pixels(const Pixels &p)
	{
		this->raw = p.raw;
		this->tRaw = nullptr;
		this->width = p.width;
		this->height = p.height;
		this->components = p.components;
	}
	Pixels & operator=(const Pixels &p)
	{
		this->raw = p.raw;
		this->tRaw = nullptr;
		this->width = p.width;
		this->height = p.height;
		this->components = p.components;
	}
	unsigned int width;
	unsigned int height;
	unsigned int components;
	void LoadFromJpegFile(const string & filename);
	void LoadFromJpegBytes(unsigned char bytes[], size_t length);
	void SaveAsJpeg(const string & filename);
	vector<Pixel> & GetPixels() { return raw; }
	void SetPixels(vector<Pixel> p) { raw = p; }
	const unsigned char *GetRaw();
	~Pixels();
private:
	vector<Pixel> raw;
	unsigned char *tRaw;//����GetRawʱ�����ɵ�bytes�������ÿ�ε��ö���ɾ���ϴ����ɵ�tRaw
};

