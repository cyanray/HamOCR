#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <list>
#include <boost/filesystem.hpp>
#include "HDatHelper.h"
#include "CyImg/Pixels.h"
using namespace boost::filesystem;
using std::string;
using std::exception;
using std::list;
class HamOCR
{
public:
	HamOCR() {}
	void CreateDataFile(const string & folder, const string & output_file_path);
	void LoadDataFile(const string & filename);
	//��ȫ�������ݿ⣬�ҵ�����������С������
	string OCR(Pixels &img);
	//����OCR������������С�ڵ��ڿɽ��ܵ�ֵʱ���˳�����
	//minHamming:�ɽ��ܵĺ�������
	string OCR_fast(Pixels &img,unsigned int minHamming = 20);
	~HamOCR() {}
private:
	list<HDat> HDats;
};

