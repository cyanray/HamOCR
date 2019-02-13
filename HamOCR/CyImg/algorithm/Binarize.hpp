#pragma once
#include "../Pixels.h"
namespace Cyan
{
	void RGB_Binarize(Pixels & img,unsigned char value)
	{
		auto s = img.GetPixels();
		for (auto &p : s)
		{
			if (p.R() >= value && p.G() >= value && p.B() >= value)
			{
				p.RGB(255, 255, 255);
			}
			else
			{
				p.RGB(0, 0, 0);
			}
		}
		img.SetPixels(s);
	}
}