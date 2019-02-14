#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <boost/filesystem.hpp>
#include "HDatHelper.h"
#include "CyImg/Pixels.h"
using namespace boost::filesystem;
using std::string;
using std::exception;
class HamOCR
{
public:
	HamOCR() {}
	void CreateDataFile(const string & folder, const string & output_file_path);
	~HamOCR() {}
};

