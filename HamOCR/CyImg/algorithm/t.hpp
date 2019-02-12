#pragma once
#include "../Pixels.h"
namespace Cyan
{
	void mm(Pixels & ps)
	{
		auto s = ps.GetPixels();
		for (auto &p : s)
		{
			if (p.R() >= 170 && p.G() >= 170 && p.B() >= 170)
			{
				p.R(255).G(255).B(255);
			}
			else
			{
				p.R(0).G(0).B(0);
			}
		}
		ps.SetPixels(s);
	}
}