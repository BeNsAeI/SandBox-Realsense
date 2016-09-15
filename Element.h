#ifndef LEELOO_H
#define LEELOO_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.hpp>
#include <opencv/highgui.h>

class Element{
public:
	int NOC;
	int limit;
	void Leeloo(int * r, int * g, int * b, int depth, int minVal);
	void Earth(int * r, int * g, int * b, int depth, int minVal);
	void Water(int * r, int * g, int * b, int depth, int minVal);
	void Air(int * r, int * g, int * b, int depth, int minVal);
	void Fire(int * r, int * g, int * b, int depth, int minVal);
	void Realistic(int * r, int * g, int * b, int depth, int minVal);
};

#endif