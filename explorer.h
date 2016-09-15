#ifndef EXPLORERCHAR_HPP
#define EXPLORERCHAR_HPP

#include <string>
#include <string.h>
#include <cstring>

#include "Const.h"

#define X 0
#define Y 1
#define U 0
#define D 1
#define L 2
#define R 3

using std::string;

struct move{
	int position[2];
	char facing;
	int range;
};

class explorer
{
public:
	explorer(string src, int limit, int spd, int size);
	struct move getMove(int * block);
	~explorer();
	string source;
	int Size;
private:
	int startPos[2];
	int steepnesslimit;
	int speed;
	int position[2];
	char facing;
};

#endif
