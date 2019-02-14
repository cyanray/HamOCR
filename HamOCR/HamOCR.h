#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <boost/filesystem.hpp>
using namespace boost::filesystem;
using std::string;
using std::exception;
class HamOCR
{
public:
	HamOCR();
	void CreateDataFile(const string & folder,const string & ouput_file_path)
	{
		using namespace std;
		try
		{
			path p_folder(folder);
			if (exists(p_folder))
			{
				if (is_directory(p_folder))
				{
					for (auto& d:directory_iterator(p_folder))
					{
						if (is_directory(d.path()))
						{
							for (auto& x : directory_iterator(d.path()))
							{
								cout << x << endl;
							}
						}
					}
				}
				else
				{
					throw exception((folder + " is not a directory.").data());
				}
			}
		}
		catch (const std::exception&)
		{

		}
	}
	~HamOCR();
};

