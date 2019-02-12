#pragma once
#include "../Pixels.h"
namespace Cyan
{
	//¶þÖµ»¯
	void mm(Pixels & ps)
	{
		auto s = ps.GetPixels();
		for (auto &p : s)
		{
			if (p.R() >= 170 && p.G() >= 170 && p.B() >= 170)
			{
				p.RGB(255, 255, 255);
			}
			else
			{
				p.RGB(0, 0, 0);
			}
		}
		ps.SetPixels(s);
	}
	Pixels sub(Pixels &ps, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2)
	{
		Pixels t;
		vector<Pixel> tvp,ovp = ps.GetPixels();
		t.width = x2 - x1, t.height = y2 - y1;
		unsigned int start = (y1 - 1)*ps.width + x1;
		for (size_t h = 0; h < t.height; ++h)
		{
			for (size_t w = 0; w < t.width; ++w)
			{
				tvp.push_back(ovp[start + w]);
			}
			start += ps.width;
		}
		t.SetPixels(tvp);
		return t;
	}
}