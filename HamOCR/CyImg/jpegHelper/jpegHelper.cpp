#include "jpegHelper.h"
#include <exception>
using std::exception;
jpegHelper::jpegHelper()
{
}


jpegHelper::~jpegHelper()
{
}


void jpegHelper::read_JPEG_file(
	const char * filename,
	unsigned char **img_buff,
	unsigned int &output_width,
	unsigned int &output_height,
	unsigned int &output_components)
{
	struct jpeg_decompress_struct cinfo;
	struct my_error_mgr jerr;
	FILE * infile;
	JSAMPARRAY buffer;
	int row_stride;
	if ((infile = fopen(filename, "rb")) == NULL)
	{
		throw exception("Can't open file.");
	}
	cinfo.err = jpeg_std_error(&jerr.pub);
	jerr.pub.error_exit = my_error_exit;
	if (setjmp(jerr.setjmp_buffer))
	{
		jpeg_destroy_decompress(&cinfo);
		fclose(infile);
		throw exception("An error occurrence.");
	}
	jpeg_create_decompress(&cinfo);
	jpeg_stdio_src(&cinfo, infile);
	(void)jpeg_read_header(&cinfo, TRUE);
	(void)jpeg_start_decompress(&cinfo);
	row_stride = cinfo.output_width * cinfo.output_components;

	output_width = cinfo.output_width;
	output_height = cinfo.output_height;
	output_components = cinfo.output_components;

	buffer = (*cinfo.mem->alloc_sarray)
		((j_common_ptr)&cinfo, JPOOL_IMAGE, row_stride, 1);

	*img_buff = new unsigned char[cinfo.output_width * cinfo.output_height * cinfo.output_components]{ 0 };
	unsigned char *p = *img_buff;
	while (cinfo.output_scanline < cinfo.output_height)
	{
		(void)jpeg_read_scanlines(&cinfo, buffer, 1);
		memcpy(p, *buffer, row_stride);
		p += row_stride;
	}
	(void)jpeg_finish_decompress(&cinfo);
	jpeg_destroy_decompress(&cinfo);
	fclose(infile);
}
