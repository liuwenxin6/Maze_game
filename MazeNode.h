/*
 * MazeNode.h
 * Author:Wenxin Liu
 */

#include <iostream>
using namespace std;

#ifndef MAZENODE
#define MAZENODE

class MazeNode{
	private:
		int x, y;
	public:
		MazeNode(int xc=0, int yc=0); 
		void setALL(int x_val, int y_val); 
		int getX() const;
		int getY() const;
		void setX(int newX); // check for valid values
		void setY(int newY); // check for valid values
		bool operator==(const MazeNode & origList);
};
#endif  
