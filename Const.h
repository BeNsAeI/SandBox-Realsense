#ifndef CONST_H
#define CONST_H

#include <sstream>

#define DEBUG 0

#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x0500

#define AVERAGEVAL 10

#define HMV 1050
//#define LMV 600
#define LMV 750
#define CALR 50
#define FADERATE 10 // Fade rate for bad pixels

#define X 960
#define Y 600
#define SCREEN_WIDTH 1400
#define SCREEN_HEIGHT 900//1200

#define RAWOFFSETX 55
#define RAWOFFSETY 1

#define CAM_WIDTH 640
#define CAM_HEIGHT 480
#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
		( std::ostringstream() << std::dec << X)).str()

//#define AOIWU 110
//#define AOIWD 70
//#define AOIHU 140
//#define AOIHD 100

//#define AOIWU 70
//#define AOIWD 155
//#define AOIHU 125
//#define AOIHD 50

#define AOIWU 45
#define AOIWD 65
#define AOIHU 45
#define AOIHD 40


#define ADJST 2
#define DYNAMICRR 90

//Explorer
#define EXPLORERSPEED 1

#endif // !CONST_H
