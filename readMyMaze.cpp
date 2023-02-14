//read data from a text file into a 2D array

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
 	ifstream inputFile; 		  // declare an input file stream
 	inputFile.open("myMaze.txt"); //open the input stream and position it 
	 							  // on the first line, first character in the file 							  
    int SIZE = 10; 				  // size of the maze
    int maze2D[SIZE][SIZE];  // declare a 2 dimensional array where you store maze values

    for (int row = 0; row < SIZE; row++)
    {
     	for (int col = 0; col < SIZE; col++)  
     	 	inputFile >> maze2D[row][col]; // read the next '0' or '1' from myMaze.txt 
			  		  	 				   // inputFile >> xxx reads until next space 
    }
	
	// display maze on the screen
	for (int row = 0; row < SIZE; row++)
	{
	 	for (int col =0; col < SIZE; col++)
	 		cout << maze2D[row][col];
	 	cout << endl; 
	 }	
	 
	 char c;
	 cin >> c; 							  
}
