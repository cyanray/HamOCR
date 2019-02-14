#pragma once
#include "HDat.h"
class HDatHelper
{
public:
	HDatHelper() :fp(nullptr) {}
	//打开一个HDat文件
	void Open(const string & filename);
	//读取一个HDat数据
	HDat ReadOne();
	//在末尾加入一个HDat数据
	void AppendOne(HDat &hdat);
	//删除所有名字为str的HDat数据
	void RemoveAll(const string & str);
	//删除所有HDat数据
	void RemoveAll();
	//不是必须的，可以不调用它
	void Close() 
	{
		if (fp != nullptr) fclose(fp);
		fp = nullptr;
	}
	~HDatHelper() { if (fp != nullptr) fclose(fp); }
private:
	FILE *fp;
};

