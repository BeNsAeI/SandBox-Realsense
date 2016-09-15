#include <Element.h>
#include <iostream>

#include <Const.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.hpp>
#include <opencv/highgui.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

void Element::Fire(int * r, int * g, int * b, int depth, int minVal)
{
	//int depth = (int)depthValues[i * CAM_WIDTH + j];
	int val = minVal;

	int stp = (HMV - val) / NOC;
	int stpcounter = 0;
	*b = 0;
	*g = 0;
	*r = 0;

	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)//yellow
	{
		*b = 200;
		*g = 255;
		*r = 255;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 150;
		*g = 240;
		*r = 255;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 100;
		*g = 220;
		*r = 255;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 50;
		*g = 200;
		*r = 255;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 0;
		*g = 180;
		*r = 255;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 0;
		*g = 160;
		*r = 255;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)//orange
	{
		*b = 0;
		*g = 140;
		*r = 255;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 0;
		*g = 120;
		*r = 255;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 0;
		*g = 100;
		*r = 255;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 0;
		*g = 80;
		*r = 255;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)// red
	{
		*b = 0;
		*g = 60;
		*r = 255;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 0;
		*g = 40;
		*r = 255;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 00;
		*g = 20;
		*r = 250;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 0;
		*g = 0;
		*r = 200;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 0;
		*g = 0;
		*r = 150;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 0;
		*g = 0;
		*r = 100;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 0;
		*g = 0;
		*r = 50;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp)
	{
		*b = 0;
		*g = 0;
		*r = 0;
	}
	stpcounter++;
}
void Element::Air(int * r, int * g, int * b, int depth,int minVal)
{
	//int depth = (int)depthValues[i * CAM_WIDTH + j];
	int val = minVal;

	int stp = (HMV - val) / NOC;
	int stpcounter = 0;
	*b = 0;
	*g = 0;
	*r = 0;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 255;
		*g = 255;
		*r = 255;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 240;
		*g = 240;
		*r = 240;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 225;
		*g = 225;
		*r = 225;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 210;
		*g = 210;
		*r = 210;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 195;
		*g = 195;
		*r = 195;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 180;
		*g = 180;
		*r = 180;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 165;
		*g = 165;
		*r = 165;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 140;
		*g = 140;
		*r = 140;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 125;
		*g = 125;
		*r = 125;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 110;
		*g = 110;
		*r = 110;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 95;
		*g = 95;
		*r = 95;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 80;
		*g = 80;
		*r = 80;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 65;
		*g = 65;
		*r = 65;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 40;
		*g = 40;
		*r = 40;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 25;
		*g = 25;
		*r = 25;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 10;
		*g = 10;
		*r = 10;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 5;
		*g = 5;
		*r = 5;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp)
	{
		*b = 0;
		*g = 0;
		*r = 0;
	}
	stpcounter++;
}
void Element::Water(int * r, int * g, int * b, int depth, int minVal)
{
	//int depth = (int)depthValues[i * CAM_WIDTH + j];
	int val = minVal;

	int stp = (HMV - val) / NOC;
	int stpcounter = 0;
	*b = 0;
	*g = 0;
	*r = 0;

	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 255;
		*g = 255;
		*r = 200;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 255;
		*g = 240;
		*r = 150;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 255;
		*g = 220;
		*r = 100;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 255;
		*g = 200;
		*r = 50;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 255;
		*g = 180;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 255;
		*g = 160;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 255;
		*g = 140;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 255;
		*g = 120;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 255;
		*g = 100;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 255;
		*g = 80;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 255;
		*g = 60;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 255;
		*g = 40;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 250;
		*g = 20;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 200;
		*g = 0;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 150;
		*g = 0;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 100;
		*g = 0;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 50;
		*g = 0;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp)
	{
		*b = 0;
		*g = 0;
		*r = 0;
	}
	stpcounter++;
}
void Element::Earth(int * r, int * g, int * b, int depth, int minVal)
{
	//int depth = (int)depthValues[i * CAM_WIDTH + j];
	int val = minVal;

	int stp = (HMV - val) / NOC;
	int stpcounter = 0;
	*b = 0;
	*g = 0;
	*r = 0;

	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) 
	{
		*b = 132;
		*g = 149;
		*r = 171;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) 
	{
		*b = 130;
		*g = 145;
		*r = 170;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) 
	{
		*b = 125;
		*g = 140;
		*r = 165;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) 
	{
		*b = 120;
		*g = 135;
		*r = 160;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) 
	{
		*b = 115;
		*g = 130;
		*r = 155;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 110;
		*g = 125;
		*r = 150;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) 
	{
		*b = 105;
		*g = 120;
		*r = 150;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 100;
		*g = 120;
		*r = 145;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 95;
		*g = 115;
		*r = 140;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 90;
		*g = 110;
		*r = 135;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 85;
		*g = 105;
		*r = 130;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 80;
		*g = 100;
		*r = 125;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 76;
		*g = 96;
		*r = 121;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 65;
		*g = 85;
		*r = 115;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 60;
		*g = 77;
		*r = 100;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 50;
		*g = 70;
		*r = 90;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp)
	{
		*b = 47;
		*g = 65;
		*r = 87;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp)
	{
		*b = 0;
		*g = 0;
		*r = 0;
	}
	stpcounter++;
}
void Element::Leeloo(int * r, int * g, int * b, int depth, int minVal)
{
	//int depth = (int)depthValues[i * CAM_WIDTH + j];
	//depth = depth - (depth % 10);
	int val = minVal;

	int stp = (HMV - val) / (NOC+14);
	int stpcounter = 0;
	*r = 0;
	*g = 0;
	*b = 0;

	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //pink
	{
		*b = 255;
		*g = 150;
		*r = 255;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //pinkish purple
	{
		*b = 255;
		*g = 100;
		*r = 255;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //pinkish purple
	{
		*b = 255;
		*g = 50;
		*r = 255;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //purple
	{
		*b = 255;
		*g = 0;
		*r = 255;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //purple
	{
		*b = 200;
		*g = 0;
		*r = 255;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //purple
	{
		*b = 150;
		*g = 0;
		*r = 255;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //redish-purple
	{
		*b = 100;
		*g = 0;
		*r = 255;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //redish-purple
	{
		*b = 50;
		*g = 0;
		*r = 255;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //red
	{
		*b = 0;
		*g = 0;
		*r = 255;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //redish orange
	{
		*b = 0;
		*g = 50;
		*r = 255;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //redish orange
	{
		*b = 0;
		*g = 100;
		*r = 255;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //orange
	{
		*b = 0;
		*g = 150;
		*r = 255;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //orangeis yellow
	{
		*b = 0;
		*g = 200;
		*r = 255;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //yellow
	{
		*b = 0;
		*g = 255;
		*r = 255;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //yellow
	{
		*b = 50;
		*g = 255;
		*r = 200;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //yellow
	{
		*b = 100;
		*g = 255;
		*r = 200;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //yellow
	{
		*b = 150;
		*g = 255;
		*r = 200;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //dark green
	{
		*b = 150;
		*g = 255;
		*r = 150;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //light green
	{
		*b = 0;
		*g = 255;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //light green
	{
		*b = 50;
		*g = 255;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //light green
	{
		*b = 100;
		*g = 255;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //light greenish light blue
	{
		*b = 150;
		*g = 255;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //light greenish light blue
	{
		*b = 200;
		*g = 255;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //light blue
	{
		*b = 255;
		*g = 255;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //light blue
	{
		*b = 255;
		*g = 200;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //light blueis dark blue
	{
		*b = 255;
		*g = 150;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //light blueis dark blue
	{
		*b = 255;
		*g = 75;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //dark blue
	{
		*b = 255;
		*g = 0;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //dark blue
	{
		*b = 200;
		*g = 0;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //darker blue
	{
		*b = 150;
		*g = 0;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //darker blue
	{
		*b = 75;
		*g = 0;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp) //black
	{
		*b = 0;
		*g = 0;
		*r = 0;
	}
	stpcounter++;
}
void Element::Realistic(int * r, int * g, int * b, int depth, int minVal)
{

	//int depth = (int)depthValues[i * CAM_WIDTH + j];
	//depth = depth - (depth%10);
	int val = minVal;
	//val = 600;
	int stp = (HMV - val) / (NOC+14);
	int stpcounter = 0;
	*r = 0;
	*g = 0;
	*b = 50;
	int random = rand() % 5 + 1;
	if (depth == 100)
	{
		*b = 0;
		*g = 0;
		*r = 255;
	}
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //white
	{
		*b = 255;
		*g = 255;
		*r = 255;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //white
	{
		*b = 255;
		*g = 255;
		*r = 255;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //white
	{
		*b = 225;
		*g = 225;
		*r = 225;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //white
	{
		*b = 200;
		*g = 200;
		*r = 200;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //white
	{
		*b = 185;
		*g = 185;
		*r = 185;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //white
	{
		*b = 175;
		*g = 185;
		*r = 190;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //white
	{
		*b = 150;
		*g = 175;
		*r = 150;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //white
	{
		*b = 125;
		*g = 175;
		*r = 125;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //white
	{
		*b = 100;
		*g = 175;
		*r = 100;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //white
	{
		*b = 100;
		*g = 175;
		*r = 100;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //white
	{
		*b = 100;
		*g = 175;
		*r = 100;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //white
	{
		*b = 100;
		*g = 200;
		*r = 100;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //white
	{
		*b = 100;
		*g = 225;
		*r = 100;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //white
	{
		*b = 100;
		*g = 255;
		*r = 100;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //white
	{
		*b = 125;
		*g = 255;
		*r = 125;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //white
	{
		*b = 150;
		*g = 255;
		*r = 150;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //white
	{
		*b = 150;
		*g = 200;
		*r = 150;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //white
	{
		*b = 150;
		*g = 200;
		*r = 175;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //white
	{
		*b = 150;
		*g = 175;
		*r = 200;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //white
	{
		*b = 156;
		*g = 185;
		*r = 213;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //white
	{
		*b = 225;
		*g = 225;
		*r = 225;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //white
	{
		*b = 255;
		*g = 255;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //white
	{
		*b = 255;
		*g = 200;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //white
	{
		*b = 255;
		*g = 150;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //white
	{
		*b = 225;
		*g = 125;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //white
	{
		*b = 200;
		*g = 100;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //white
	{
		*b = 175;
		*g = 75;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //white
	{
		*b = 150;
		*g = 50;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //white
	{
		*b = 125;
		*g = 25;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //white
	{
		*b = 100;
		*g = 0;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp && depth <= val + (stpcounter + 1) * stp) //white
	{
		*b = 75;
		*g = 0;
		*r = 0;
	}
	stpcounter++;
	if (depth > val + stpcounter * stp) //dark blue
	{
		*b = 50;
		*g = 0;
		*r = 0;
	}
	stpcounter++;

}
