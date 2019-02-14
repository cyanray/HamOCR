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
	string OCR(Pixels &img);
	~HamOCR() {}
private:
	list<HDat> HDats;
};

