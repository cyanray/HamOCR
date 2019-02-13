#pragma once
#include "../Pixels.h"
namespace Cyan
{
	struct Point
	{
		Point() {}
		Point(unsigned int x, unsigned int y) :X(x), Y(y) {}
		unsigned int X;
		unsigned int Y;
	};
	Pixels Split(Pixels & img,Point & a, Point & b)
	{
		Pixels t;
		vector<Pixel> tvp, ovp = img.GetPixels();
		t.width = b.X - a.X, t.height = b.Y - a.Y;
		unsigned int start = (a.Y - 1)*img.width + a.X;
		for (size_t h = 0; h < t.height; ++h)
		{
			for (size_t w = 0; w < t.width; ++w)
			{
				tvp.push_back(ovp[start + w]);
			}
			start += img.width;
		}
		t.SetPixels(tvp);
		return t;
	}
	Pixels Split(Pixels & img, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2)
	{
		Pixels t;
		vector<Pixel> tvp, ovp = img.GetPixels();
		t.width = x2 - x1, t.height = y2 - y1;
		unsigned int start = (y1 - 1)*img.width + x1;
		for (size_t h = 0; h < t.height; ++h)
		{
			for (size_t w = 0; w < t.width; ++w)
			{
				tvp.push_back(ovp[start + w]);
			}
			start += img.width;
		}
		t.SetPixels(tvp);
		return t;
	}
}