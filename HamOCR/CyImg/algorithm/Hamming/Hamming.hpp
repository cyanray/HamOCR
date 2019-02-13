#pragma once
namespace Cyan
{
	struct Identity
	{
		Identity() {}
		Identity(unsigned char* r) : raw(r) {}
		unsigned char *raw;
		unsigned int length;
		~Identity()
		{
			delete[] raw;
		}
	};
}