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
	HamOCR();
	void CreateDataFile(const string & folder,const string & output_file_path)
	{
		HDatHelper hh;
		hh.Create(output_file_path);
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
							string str = d.path().filename().string();//HDat.str�ֶ�
							for (auto& x : directory_iterator(d.path()))
							{
								path t = x.path();
								string suffix = t.extension().string();
								HDat tHDat;
								Pixels img;
								if (suffix == ".jpg" || suffix == ".jpeg")
								{
									img.LoadFromJpegFile(t.string());
								}
								else
								{
									continue;
								}
								tHDat.str = str;
								tHDat.length = img.height * img.width *img.components;
								//��ʹ��const_cast���GetRaw��ֵ��HDat
								//HDat���GetRaw��ָ���ͷ�
								//Pixels��Ҳ���ͷ�һ�θ�ָ��
								//����ֻ�ܰ����ݸ���һ��
								tHDat.data = new unsigned char[tHDat.length];
								memcpy(tHDat.data, img.GetRaw(), tHDat.length);
								hh.AppendOne(tHDat);
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

