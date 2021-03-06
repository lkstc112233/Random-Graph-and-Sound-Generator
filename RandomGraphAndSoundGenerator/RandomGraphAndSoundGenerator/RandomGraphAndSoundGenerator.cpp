// RandomGraphAndSoundGenerator.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
}

using std::cout;
using std::endl;

int main(int argc, char** argv)
{
	av_register_all();

	if (argc < 2) return 0;

	AVFormatContext *pFormatCtx = NULL;
	if (avformat_open_input(&pFormatCtx, argv[1], NULL, NULL) != 0)
		return -1;

	if (avformat_find_stream_info(pFormatCtx, NULL)<0)
		return -1; // Couldn't find stream information

	// av_dump_format(pFormatCtx, 0, argv[1], 0);
	cout << pFormatCtx->nb_streams << endl;

	cout << "Success" << endl;

    return 0;
}

