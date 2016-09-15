#include "explorer.h"

#include "Const.h"

#include <string>
#include <string.h>
#include <cstring>

using std::string;

explorer::explorer(string src, int limit, int spd, int size)
{
	source = src;
	steepnesslimit = limit;
	speed = spd;
	Size = size;
	startPos[X] = Size / 2 + 1;
	startPos[Y] = Size / 2 + 1;
}
struct move explorer::getMove(int * block)
{
	struct move nextmove;
	nextmove.facing = U;
	nextmove.position[X] = speed;
	nextmove.position[Y] = speed;
	nextmove.range = speed;
	return nextmove;
}
explorer::~explorer()
{

}