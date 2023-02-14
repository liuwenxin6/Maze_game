# Maze_game
Final project for csc16 (intro to c++) from Spring 2019

This maze game displays the maze in a 2d fashion based off the base given by the professor. The maze is presented with 1 & 0 to indicate walls 
and possible path; * represents path the user came from, and # represents the user's current position (a sample is attached below). The user can choose to 
go up, down, left, right, and diagonal steps. The game will congrats the user when the exit of the maze is reached.

SAMPLE OUTPUT:
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
