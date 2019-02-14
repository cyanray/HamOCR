/*
*该文件定义HDat包含的数据
*/
#pragma once
#include <string>
using std::string;
struct HDat
{
	string str = "";
	unsigned int length;
	unsigned char *data;
};