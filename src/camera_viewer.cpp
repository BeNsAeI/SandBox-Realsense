
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <iostream>
#include "pxcsensemanager.h"
#include "util_cmdline.h"
#include "util_render.h"
#include <conio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.hpp>
#include <opencv/highgui.h>
#include <Element.h>

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "Const.h"
#include "explorer.h"

using namespace cv;

void putCharacter(int x, int y ,Mat characterSource, Mat * out,int frame)
{
	Mat character;
	int charlenw = 34;
	int charlenh = 50;
	Rect movedirdown[4] = { Rect(14, 11, charlenw, charlenh),
		Rect(79, 11, charlenw, charlenh),
		Rect(142, 11, charlenw, charlenh),
		Rect(205, 11, charlenw, charlenh) };

	Rect movedirup[4] = { Rect(14, 201, charlenw, charlenh),
		Rect(78, 201, charlenw, charlenh),
		Rect(143, 201, charlenw, charlenh),
		Rect(207, 201, charlenw, charlenh) };

	Rect movedirright[4] = { Rect(11, 137, charlenw, charlenh),
		Rect(81, 137, charlenw, charlenh),
		Rect(142, 137, charlenw, charlenh),
		Rect(206, 137, charlenw, charlenh) };

	Rect movedirleft[4] = { Rect(15, 75, charlenw, charlenh),
		Rect(81, 75, charlenw, charlenh),
		Rect(144, 75, charlenw, charlenh),
		Rect(206, 75, charlenw, charlenh) };
	Mat image = characterSource(movedirdown[(frame % 4)]);
	image.copyTo(character);
	namedWindow("char",CV_WINDOW_AUTOSIZE);
	/*while (1)
	{
		imshow("char", character);
		if (waitKey('q'))
			break;
	}*/
//	cv::resize(character, character, Size(200, 200));
	for (int i = 0; i < character.cols; i++)
	{
		for (int j = 0; j < character.rows; j++)
		{
			if (character.at<cv::Vec3b>(j, i)[0] != character.at<cv::Vec3b>(j, 0)[0] ||
				character.at<cv::Vec3b>(j, i)[1] != character.at<cv::Vec3b>(j, 0)[0] ||
				character.at<cv::Vec3b>(j, i)[2] != character.at<cv::Vec3b>(j, 0)[0] )
			{				
				out->at<cv::Vec3b>(j + y, i + x)[0] = character.at<cv::Vec3b>(j, i)[0];
				out->at<cv::Vec3b>(j + y, i + x)[1] = character.at<cv::Vec3b>(j, i)[1];
				out->at<cv::Vec3b>(j + y, i + x)[2] = character.at<cv::Vec3b>(j, i)[2];
			}
			
		}
	}


}

int wmain(int argc, WCHAR* argv[]) 
{

	int r;
	int g;
	int b;
	int val;
	int leeloo;
	int stp;
	int stpcounter;
	srand(time(NULL));
	Element myColor;			//Setting up color scheme
	myColor.NOC = 18;
	Mat out;
	Mat resized;
	Mat cropedImage;
	Mat characterSource;
	unsigned short backupdepth[CAM_WIDTH * CAM_HEIGHT] = { 0 };
	unsigned short average[CAM_WIDTH * CAM_HEIGHT][AVERAGEVAL] = { 0 };
	unsigned short averageeight;
	int colorMode = 1;
	
	// Character building:
	explorer * myExplorer = new explorer("sprite2.png", 5,1,5);
	struct move nextMove;
	characterSource = imread(myExplorer->source, CV_LOAD_IMAGE_UNCHANGED);
	// character directions:
	

	/* Creates an instance of the PXCSenseManager */
	PXCSenseManager *pp = PXCSenseManager::CreateInstance();
	if (!pp)
	{
		wprintf_s(L"Unable to create the SenseManager\n");
		return 3;
	}
	/* Collects command line arguments */
	UtilCmdLine cmdl(pp->QuerySession());
	if (!cmdl.Parse(L"-listio-nframes-sdname-csize-dsize-isize-file-record-noRender-mirror", argc, argv)) return 3;

	/* Sets file recording or playback */
	PXCCaptureManager *cm = pp->QueryCaptureManager();
	cm->SetFileName(cmdl.m_recordedFile, cmdl.m_bRecord);
	if (cmdl.m_sdname) cm->FilterByDeviceInfo(cmdl.m_sdname, 0, 0);

	// Create stream renders
	UtilRender renderd(L"Depth");
	pxcStatus sts;
	pp->EnableStream(PXCCapture::STREAM_TYPE_DEPTH, CAM_WIDTH, CAM_HEIGHT, 30);

	out = imread("black2.jpg", CV_LOAD_IMAGE_UNCHANGED);

	/* Apply command line arguments */
	if (cmdl.m_dsize.size()>0)
	{
		pp->EnableStream(PXCCapture::STREAM_TYPE_DEPTH, cmdl.m_dsize.front().first.width, cmdl.m_dsize.front().first.height, (pxcF32)cmdl.m_dsize.front().second);
	}
	if (cmdl.m_csize.size() == 0 && cmdl.m_dsize.size() == 0 && cmdl.m_isize.size() == 0)
	{
		wprintf_s(L"no command\n");
		PXCVideoModule::DataDesc desc = {};
		if (cm->QueryCapture())
		{
			cm->QueryCapture()->QueryDeviceInfo(0, &desc.deviceInfo);
		}
		else
		{
			desc.deviceInfo.streams = PXCCapture::STREAM_TYPE_DEPTH;
		}
		pp->EnableStreams(&desc);
	}
		/* Initializes the pipeline */
	sts = pp->Init();
	if (sts<PXC_STATUS_NO_ERROR)
	{
		wprintf_s(L"Failed to locate any video stream(s)\n");
		return 1;
	}
	if (cmdl.m_bMirror)
	{
		pp->QueryCaptureManager()->QueryDevice()->SetMirrorMode(PXCCapture::Device::MirrorMode::MIRROR_MODE_HORIZONTAL);
	}
	else
	{
		pp->QueryCaptureManager()->QueryDevice()->SetMirrorMode(PXCCapture::Device::MirrorMode::MIRROR_MODE_DISABLED);
	}
	/* Stream Data */ // PHASE 1: **STARTING CALIBRATION
	unsigned short depthValues[CAM_WIDTH * CAM_HEIGHT] = {};
	int depth;
	int minVal = 900;

	//Begginning of the loop
	for (long nframes = 0;; nframes++) {
		/* Waits until new frame is available and locks it for application processing */
		sts = pp->AcquireFrame(false);
		if (sts<PXC_STATUS_NO_ERROR) 
		{
			if (sts == PXC_STATUS_STREAM_CONFIG_CHANGED) 
			{
				wprintf_s(L"Stream configuration was changed, re-initilizing\n");
				pp->Close();
			}
			break;
		}
		/* Render streams, unless -noRender is selected */
		PXCImage::ImageData *myImage = new PXCImage::ImageData();
		if (cmdl.m_bNoRender == false)
		{
			const PXCCapture::Sample *sample = pp->QuerySample();
			if (!sample || sample->depth && !renderd.RenderFrame(sample->depth)) break;
			try
			{
				if (sample->depth != NULL)
				{
					sample->depth->AcquireAccess(PXCImage::Access::ACCESS_READ_WRITE, PXCImage::PixelFormat::PIXEL_FORMAT_DEPTH, PXCImage::OPTION_ANY, myImage);
					memcpy(depthValues, myImage->planes[0], sizeof(unsigned short) * CAM_WIDTH * CAM_HEIGHT);
					minVal = LMV;

					r = 0;
					g = 0;
					b = 0;
					val = minVal;
					leeloo = 18;
					stp = (813 - val) / leeloo;
					stpcounter = 0;
					for (int i = AOIHU; i < (CAM_HEIGHT - AOIHD); ++i)
					{
						for (int j = AOIWU; j < (CAM_WIDTH - AOIWD); ++j)
						{		
							if (((int)depthValues[(i)* CAM_WIDTH + (j)] != 0))
							{
								backupdepth[(i)* CAM_WIDTH + (j)] = (2 * backupdepth[(i)* CAM_WIDTH + (j)] + depthValues[(i)* CAM_WIDTH + (j)])/3;
								average[(i)* CAM_WIDTH + (j)][nframes % AVERAGEVAL] = (average[(i)* CAM_WIDTH + (j)][nframes % AVERAGEVAL] + depthValues[(i)* CAM_WIDTH + (j)])/2;
								//depth = (int)depthValues[(i)* CAM_WIDTH + (j)];
								depth = 0;
								for (int k = 0; k < AVERAGEVAL; k++)
								{
									depth = depth + (int)average[(i)* CAM_WIDTH + (j)][k];
								}
								depth = depth / AVERAGEVAL;
								if (((int)depthValues[(i)* CAM_WIDTH + (j)] < depthValues[(i)* CAM_WIDTH + (j + 1)] - 20 ||
									(int)depthValues[(i)* CAM_WIDTH + (j)] < depthValues[(i)* CAM_WIDTH + (j - 1)] - 20 ||
									(int)depthValues[(i)* CAM_WIDTH + (j)] < depthValues[(i + 1)* CAM_WIDTH + (j + 1)] - 20 ||
									(int)depthValues[(i)* CAM_WIDTH + (j)] < depthValues[(i - 1)* CAM_WIDTH + (j + 1)] - 20))
								{
									if ((depthValues[(i)* CAM_WIDTH + (j + 1)] != 0 &&
										depthValues[(i)* CAM_WIDTH + (j - 1)] != 0 &&
										depthValues[(i + 1)* CAM_WIDTH + (j)] != 0 &&
										depthValues[(i - 1)* CAM_WIDTH + (j)] != 0
										)){
										averageeight =
											(depthValues[(i - 1)* CAM_WIDTH + (j + 1)] + depthValues[(i - 1)* CAM_WIDTH + (j)] + depthValues[(i - 1)* CAM_WIDTH + (j - 1)]
											+ depthValues[(i + 1)* CAM_WIDTH + (j + 1)] + depthValues[(i + 1)* CAM_WIDTH + (j)] + depthValues[(i + 1)* CAM_WIDTH + (j - 1)]
											+ depthValues[(i)* CAM_WIDTH + (j + 1)] + depthValues[(i)* CAM_WIDTH + (j - 1)]) / 8 + 20;
									}
									else{ averageeight = 0; }
									average[(i)* CAM_WIDTH + (j)][nframes % AVERAGEVAL] = averageeight;
									depth = 0;
									for (int k = 0; k < AVERAGEVAL; k++)
									{
										depth = depth + (int)average[(i)* CAM_WIDTH + (j)][k];
									}
									depth = depth / AVERAGEVAL;
									average[(i)* CAM_WIDTH + (j)][nframes % AVERAGEVAL] = (unsigned short)depth;
								}
							}
							else 
							{
								average[(i)* CAM_WIDTH + (j)][nframes % AVERAGEVAL] = (
									backupdepth[(i)* CAM_WIDTH + (j)] +
									backupdepth[(i)* CAM_WIDTH + (j + 1)] + 
									backupdepth[(i)* CAM_WIDTH + (j - 1)] +
									backupdepth[(i - 1)* CAM_WIDTH + (j)] +
									backupdepth[(i - 1)* CAM_WIDTH + (j + 1)] +
									backupdepth[(i - 1)* CAM_WIDTH + (j - 1)] +
									backupdepth[(i + 1)* CAM_WIDTH + (j)] +
									backupdepth[(i + 1)* CAM_WIDTH + (j + 1)] +
									backupdepth[(i + 1)* CAM_WIDTH + (j - 1)] ) / 9;

								if (backupdepth[(i)* CAM_WIDTH + (j)] < HMV)
									backupdepth[(i)* CAM_WIDTH + (j)] = backupdepth[(i)* CAM_WIDTH + (j)] + (FADERATE)*(HMV / (backupdepth[(i)* CAM_WIDTH + (j)]+1));
								depth = 0;
								for (int k = 0; k < AVERAGEVAL; k++)
								{
									depth = depth + (int)average[(i)* CAM_WIDTH + (j)][k];
								}
								depth = depth / AVERAGEVAL;
							}
							val = minVal;
							leeloo = 18;
							stp = (813-val)/leeloo;
							stpcounter = 0;
							r = 0;
							g = 0;
							b = 0;
							switch (colorMode)
							{
							case 1:
								myColor.Leeloo(&r, &g, &b, depth, minVal);
								break;
							case 2:
								myColor.Realistic(&r, &g, &b, depth, minVal);
								break;
							case 3:
								myColor.Earth(&r, &g, &b, depth, minVal);
								break;
							case 4:
								myColor.Water(&r, &g, &b, depth, minVal);
								break;
							case 5:
								myColor.Fire(&r, &g, &b, depth, minVal);
								break;
							case 6:
								myColor.Air(&r, &g, &b, depth, minVal);
								break;
							}
							if (r != 256 && g != 256 && b != 256)
							{
								out.at<cv::Vec3b>(i + RAWOFFSETY, j + RAWOFFSETX)[0] = b;
								out.at<cv::Vec3b>(i + RAWOFFSETY, j + RAWOFFSETX)[1] = g;
								out.at<cv::Vec3b>(i + RAWOFFSETY, j + RAWOFFSETX)[2] = r;
							}							
						}
					}
					sample->depth->ReleaseAccess(myImage);
				}
			}
			catch (char e){ std::cout << e << std::endl; };

		}
		/*Releases CV Mat*/

				
		
		//Copying character to image
		//putCharacter(200, 200, characterSource, &out, nframes);

		cropedImage = out(Rect(AOIWU, AOIHU, (CAM_WIDTH - AOIWU - AOIWD + 2*RAWOFFSETX), (CAM_HEIGHT - AOIHU - AOIHD + 2*RAWOFFSETY)));
		cv::resize(cropedImage, resized, Size(SCREEN_WIDTH, SCREEN_HEIGHT));
		cv::namedWindow("SandBox", 0);
		cv::setWindowProperty("SandBox", CV_WND_PROP_FULLSCREEN, CV_WINDOW_FULLSCREEN);
		cv::namedWindow("View", CV_WINDOW_AUTOSIZE);
	
		cv::imshow("SandBox", resized);
		cv::imshow("View", out);
		/* Releases lock so pipeline can process next frame */
		pp->ReleaseFrame();
		resized.release();
		cropedImage.release();
		char key = cvWaitKey(1);     //Capture Keyboard stroke
		if (char(key) == 27){
			break;      //If you hit ESC key loop will break.
		}
		switch (char(key))
		{
		case '1':
			colorMode = 1;
			break;
		case '2':
			colorMode = 2;
			break;
		case '3':
			colorMode = 3;
			break;
		case '4':
			colorMode = 4;
			break;
		case '5':
			colorMode = 5;
			break;
		case '6':
			colorMode = 6;
			break;
		}
		if (_kbhit()) { // Break loop
			int c = _getch() & 255;
			if (c == 27 || c == 'q' || c == 'Q') break; // ESC|q|Q for Exit
		}
	}

	// Clean Up
	out.release();
	pp->Release();
	// killing the explorer
	delete myExplorer;
	return 0;
}
