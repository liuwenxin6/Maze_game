//Maze game main function
//The game lets the user to input operation to find a solution to the maze. 
//Author: Wenxin Liu

#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <cassert>
#include "MazeNode.h"
using namespace std;

//func declarations:
bool is_end(int intended_x, int intended_y, int SIZE);
string check_if_input_in_list(string operation);

int main()
{
 	ifstream inputFile; 		  // declare an input file stream
 	inputFile.open("myMaze.txt"); //open the input stream and position it 
	 							  // on the first line, first character in the file 							  
    int const SIZE = 10; 				  // size of the maze
    char maze2D[SIZE][SIZE];  // declare a 2 dimensional array where you store maze values

    for (int row = 0; row < SIZE; row++)
    {
     	for (int col = 0; col < SIZE; col++)  
     	 	inputFile >> maze2D[row][col]; // read the next '0' or '1' from myMaze.txt 
			  		  	 				   // inputFile >> xxx reads until next space 
    }
	//finish reading txt file to maze2D
	maze2D[0][0] = '#';
	cout<<"Welcome to the maze game! In this game, you will be responsible to find out a solution in this maze from upper left to lower right. Note: '#' stands for your current location";
	int intended_x =0, intended_y=0;
	int prev_x = 0, prev_y=0, cost =0;

	list<MazeNode *> visited; // use the list class in the c++ library
	MazeNode *current = new MazeNode(0,0);
	visited.push_front(current); //the last step is the first item in list visited
	
	while (!is_end(intended_x, intended_y, SIZE)) //when game is not over
	{
		maze2D[intended_x][intended_y] = '#'; //indicate current position

		// display maze on the screen
		cout<<endl;
		for (int row = 0; row < SIZE; row++)
		{
			for (int col =0; col < SIZE; col++)
				cout << maze2D[row][col];
				cout << endl; 
		}
		cout<<"The current maze is printed above. What would you wanna do?"<<endl;
		cout<<"Enter U for up, D for down, L for left, R for right. For diagonal step use UL for upper left, UR for upper right, DL for down left, or DR for down right :";
		string operation;
		cin>>operation;

		operation = check_if_input_in_list(operation);
		
		//process op to intended_x & intended_y;
		if (operation == "U") {intended_x-=1;}
		else if (operation == "D") {intended_x+=1;}
		else if (operation == "L") {intended_y -=1;}
		else if (operation == "R") {intended_y +=1;}
		else if (operation == "UL") {intended_x -=1; intended_y -= 1;}
		else if (operation == "UR") {intended_x -=1; intended_y += 1;}
		else if (operation == "DL") {intended_x +=1; intended_y -= 1;}
		else if (operation == "DR") {intended_x +=1; intended_y += 1;}
		while (maze2D[intended_x][intended_y] == '1' ||(intended_x >=10 || intended_y>=10) || (intended_x <0 || intended_y<0)) //check if the choice will hit the wall OR go out of the maze
		{
			cout<<"You have chosen an invalid step, where you would hit the wall OR go out of the maze if you intended to do so!!!"<<endl;
			cout<<"please enter a VALID INPUT SUCH THAT YOU WILL NOT HIT THE WALL OR GO OUT OF MY MAZE:";
			cin>>operation;
			operation = check_if_input_in_list(operation);
			//update intended x y
			intended_x = prev_x;
			intended_y = prev_y;
			if (operation == "U") {intended_x-=1;}
			else if (operation == "D") {intended_x+=1;}
			else if (operation == "L") {intended_y -=1;}
			else if (operation == "R") {intended_y +=1;}
			else if (operation == "UL") {intended_x -=1; intended_y -= 1;}
			else if (operation == "UR") {intended_x -=1; intended_y += 1;}
			else if (operation == "DL") {intended_x +=1; intended_y -= 1;}
			else if (operation == "DR") {intended_x +=1; intended_y += 1;}
		}
		bool ans = 0;
		while (maze2D[intended_x][intended_y] == '*' && ans ==0) //check if the choice is in visited
		{
			//display warnings if the choice is visited
			cout<<"You have chosen a previously visited step! Are you sure you want to this way?(1 for yes and 0 for no you wanna reenter)"<<endl;
			cin>>ans;
			if(ans == 1)
				break;
			cout<<"please enter a VALID INPUT SUCH THAT YOU WILL NOT HIT THE WALL:";
			cin>>operation;
			operation = check_if_input_in_list(operation);
			//update intended x y
			intended_x = prev_x;
			intended_y = prev_y;
			if (operation == "U") {intended_x-=1;}
			else if (operation == "D") {intended_x+=1;}
			else if (operation == "L") {intended_y -=1;}
			else if (operation == "R") {intended_y +=1;}
			else if (operation == "UL") {intended_x -=1; intended_y -= 1;}
			else if (operation == "UR") {intended_x -=1; intended_y += 1;}
			else if (operation == "DL") {intended_x +=1; intended_y -= 1;}
			else if (operation == "DR") {intended_x +=1; intended_y += 1;}
		}
		//END OF ALL CHECKING. NOW MAKE CURRENT NODE AND ADD TO LIST VISITED
		MazeNode*current = new MazeNode(intended_x, intended_y);
		visited.push_front(current);
	
		assert(maze2D[intended_x][intended_y] == '0' || maze2D[intended_x][intended_y] =='*');
		maze2D[prev_x][prev_y] = '*';
		//update prev x y cost
		prev_x = intended_x;
		prev_y = intended_y;
		cost+=1;
	}
	maze2D[intended_x][intended_y] = '*';
	//MEANING GAME ENDED ALREADY. display congrats, total steps, and player's solution
	cout<<"CONGRATULATIONS! YOU MADE IT TO THE END!"<<endl;
	cout<<"The total steps you have taken is "<<cost<<" steps!"<<endl;
	cout<<"The following is your solution to this maze:"<<endl;
	//display
	cout<<endl;
	for (int row = 0; row < SIZE; row++)
	{
		for (int col =0; col < SIZE; col++)
			cout << maze2D[row][col];
			cout << endl; 
	}
}

bool is_end(int intended_x, int intended_y, int SIZE)
{
	assert(intended_x >=0 && intended_y >=0);
	if (intended_x == SIZE-1&& intended_y == SIZE-1)
		return true;
	return false;
}

string check_if_input_in_list(string operation)
{
		string list_op [] = {"U", "D", "L", "R", "UL", "UR", "DL", "DR"};
		while ((find(begin(list_op), end(list_op), operation) == end(list_op)))
		{
			cout<<"Invalid operation!!"<<endl;
			cout<<"please enter a VALID INPUT WIHTIN THE GIVEN CHOICES:";
			cin>>operation;
		}
		return operation;
}

/*SAMPLE OUTPUT:
 * Welcome to the maze game! In this game, you will be responsible to find out a solution in this maze from upper left to lower right. Note: '#' stands for your current location
#100100100
0011100001
1010101010
0000101010
0001001010
1100001010
1111100010
0000010000
1111110100
0000000110
The current maze is printed above. What would you wanna do?
Enter U for up, D for down, L for left, R for right. For diagonal step use UL for upper left, UR for upper right, DL for down left, or DR for down right :DR

*100100100
0#11100001
1010101010
0000101010
0001001010
1100001010
1111100010
0000010000
1111110100
0000000110
The current maze is printed above. What would you wanna do?
Enter U for up, D for down, L for left, R for right. For diagonal step use UL for upper left, UR for upper right, DL for down left, or DR for down right :D

*100100100
0*11100001
1#10101010
0000101010
0001001010
1100001010
1111100010
0000010000
1111110100
0000000110
The current maze is printed above. What would you wanna do?
Enter U for up, D for down, L for left, R for right. For diagonal step use UL for upper left, UR for upper right, DL for down left, or DR for down right :DR

*100100100
0*11100001
1*10101010
00#0101010
0001001010
1100001010
1111100010
0000010000
1111110100
0000000110
The current maze is printed above. What would you wanna do?
Enter U for up, D for down, L for left, R for right. For diagonal step use UL for upper left, UR for upper right, DL for down left, or DR for down right :D

*100100100
0*11100001
1*10101010
00*0101010
00#1001010
1100001010
1111100010
0000010000
1111110100
0000000110
The current maze is printed above. What would you wanna do?
Enter U for up, D for down, L for left, R for right. For diagonal step use UL for upper left, UR for upper right, DL for down left, or DR for down right :DR

*100100100
0*11100001
1*10101010
00*0101010
00*1001010
110#001010
1111100010
0000010000
1111110100
0000000110
The current maze is printed above. What would you wanna do?
Enter U for up, D for down, L for left, R for right. For diagonal step use UL for upper left, UR for upper right, DL for down left, or DR for down right :R

*100100100
0*11100001
1*10101010
00*0101010
00*1001010
110*#01010
1111100010
0000010000
1111110100
0000000110
The current maze is printed above. What would you wanna do?
Enter U for up, D for down, L for left, R for right. For diagonal step use UL for upper left, UR for upper right, DL for down left, or DR for down right :D
You have chosen an invalid step, where you would hit the wall OR go out of the maze if you intended to do so!!!
please enter a VALID INPUT SUCH THAT YOU WILL NOT HIT THE WALL OR GO OUT OF MY MAZE:DR

*100100100
0*11100001
1*10101010
00*0101010
00*1001010
110**01010
11111#0010
0000010000
1111110100
0000000110
The current maze is printed above. What would you wanna do?
Enter U for up, D for down, L for left, R for right. For diagonal step use UL for upper left, UR for upper right, DL for down left, or DR for down right :DR

*100100100
0*11100001
1*10101010
00*0101010
00*1001010
110**01010
11111*0010
000001#000
1111110100
0000000110
The current maze is printed above. What would you wanna do?
Enter U for up, D for down, L for left, R for right. For diagonal step use UL for upper left, UR for upper right, DL for down left, or DR for down right :DR
You have chosen an invalid step, where you would hit the wall OR go out of the maze if you intended to do so!!!
please enter a VALID INPUT SUCH THAT YOU WILL NOT HIT THE WALL OR GO OUT OF MY MAZE:R

*100100100
0*11100001
1*10101010
00*0101010
00*1001010
110**01010
11111*0010
000001*#00
1111110100
0000000110
The current maze is printed above. What would you wanna do?
Enter U for up, D for down, L for left, R for right. For diagonal step use UL for upper left, UR for upper right, DL for down left, or DR for down right :DR

*100100100
0*11100001
1*10101010
00*0101010
00*1001010
110**01010
11111*0010
000001**00
11111101#0
0000000110
The current maze is printed above. What would you wanna do?
Enter U for up, D for down, L for left, R for right. For diagonal step use UL for upper left, UR for upper right, DL for down left, or DR for down right :DR
CONGRATULATIONS! YOU MADE IT TO THE END!
The total steps you have taken is 11 steps!
The following is your solution to this maze:

*100100100
0*11100001
1*10101010
00*0101010
00*1001010
110**01010
11111*0010
000001**00
11111101*0
000000011*
*/
