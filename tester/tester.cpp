

#include "pch.h"
#include <iostream>
//#include <CyImg/Pixels.h>
//#include <CyImg/algorithm/Hamming/Hamming.hpp>
//#include <CyImg/algorithm/Binarize.hpp>
//#include <CyImg/algorithm/Split.hpp>
#include <boost/filesystem.hpp>
#include <HamOCR.h>
#include <HDatHelper.h>
using namespace std;
using namespace boost::filesystem;
//void process(const path & p_)
//{
//	using namespace Cyan;
//	string tFileName = p_.stem().string();
//	path pa("E:\\TestData\\splited" / (tFileName + "_a.jpg"));
//	path pb("E:\\TestData\\splited" / (tFileName + "_b.jpg"));
//	path pc("E:\\TestData\\splited" / (tFileName + "_c.jpg"));
//	path pd("E:\\TestData\\splited" / (tFileName + "_d.jpg"));
//	Pixels img;
//	img.LoadFromJpegFile(p_.string());
//	RGB_Binarize(img, 170);
//	auto a = Split(img, 10, 4, 26, 20);
//	auto b = Split(img, 26, 4, 42, 20);
//	auto c = Split(img, 42, 4, 58, 20);
//	auto d = Split(img, 58, 4, 74, 20);
//	a.SaveAsJpeg(pa.string());
//	b.SaveAsJpeg(pb.string());
//	c.SaveAsJpeg(pc.string());
//	d.SaveAsJpeg(pd.string());
//}
int main()
{
	//RGB_Binarize(img2, 170);
	//auto a1 = Split(img, 10, 4, 26, 20);
	//auto a2 = Split(img2, 26, 4, 42, 20);
	//auto a3 = Split(img2, 42, 4, 58, 20);
	//auto a4 = Split(img, 58, 4, 74, 20);

	//path p("E:\\TestData\\splited");
	//char start = 'A';
	//for (size_t i = 0; i < 10; i++)
	//{
	//	try
	//	{
	//		string t(1, char('0' + i));
	//		cout << t << endl;
	//		path tP = p / t;
	//		if (!exists(tP))
	//		{
	//			create_directory(tP);
	//		}
	//		else
	//			cout << tP << " already existed\n";
	//	}
	//	catch (const filesystem_error& ex)
	//	{
	//		cout << ex.what() << '\n';
	//	}
	//}

	//HamOCR ocr;
	//ocr.CreateDataFile("E:\\TestData\\splited", "E:\\TestData\\splited\\A.hdat");
	HDatHelper hdh;
	try
	{
		hdh.Open("E:\\TestData\\splited\\A.hdat");
		auto a = hdh.ReadOne();
		cout << a.str << endl;
	}
	catch (const exception&ex)
	{
		cout << ex.what() << endl;
	}
	cin.get();
	return 0;
}
