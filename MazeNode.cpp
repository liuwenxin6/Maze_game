/*
 * MazeNode.cpp
 * Author: Wenxin Liu
 */


#include "MazeNode.h"
#include <iostream>
#include <cassert>

using namespace std;

MazeNode::MazeNode(int xc, int yc)
{
	assert(xc >=0 && yc>=0);

	x= xc;
	y= yc;
}
int MazeNode::getX() const
{
	return x;
}
int MazeNode::getY() const
{
	return y;
}

void MazeNode::setX(int newX) // check for valid values
{
	assert(newX>=0);
	x = newX;
}
void MazeNode::setY(int newY) // check for valid values
{
	assert(newY>=0 );
	y =newY;
}
void MazeNode::setALL(int x_val, int y_val)
{
	assert(x_val >=0 && y_val>=0);
	x= x_val;
	y= y_val;
}
bool MazeNode::operator==(const MazeNode & origList)
{
	if(origList.getX() == x && origList.getY() == y)
		return true;
	return false;
}

