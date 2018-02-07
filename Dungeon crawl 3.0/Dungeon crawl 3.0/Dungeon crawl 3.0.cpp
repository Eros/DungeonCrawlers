// Dungeon crawl 3.0.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

//Grid drawing function declaration
void gridIt(char myGrid[][10], int rows, int columns);

//Grid Drawing function description
void gridIt(char myGrid[][10], int rows, int columns)
{
	for (rows = 0; rows < 7; ++rows)
	{
		for (columns = 0; columns < 10; ++columns)
			cout << myGrid[rows][columns];
		cout << endl;
	}
}


int main()
{
	string input;
	char player = 'G', trap = 'T', goal = 'X';
	char grid[7][10];
	int i, j, posX = 0, posY = 0, skip = 0;
	for (i = 0; i < 7; ++i)
	{
		for (j = 0; j < 10; ++j)
			grid[i][j] = '.';
	}

	grid[posX][posY] = player;
	grid[3][7] = trap;
	grid[5][2] = trap;
	grid[2][5] = trap;
	grid[6][9] = goal;


	cout << "\n WELCOME TO DUNGEON CRAWL!! \n";
	cout << "\n ARRIVE SAFELY AT THE GOAL TO GET TREASURE!! \n";
	cout << "\n \n *INSTRUCTIONS* \n \n ";
	cout << "You are (G), and must make it to the end of the grid (X), \n";
	cout << " in order to win the game. \n";
	cout << " TIP.  Watch out for the Traps (T) along the way!! \n\n";
	
	gridIt(grid, 0, 0);

	while (input != "Q")
	{
		cout << "\n Type in a direction of your choice: \n";
		cout << "\n Up(W), Down(S), Left(A), Right(D) OR Quit(Q) \n\n";
		cin >> input;
		cout << endl;

		// if input is invalid
		if (input != "W" && input != "S" && input != "A" && input != "D" && input != "Q")
		{
			cout << "\nThat's not a valid input. Try again.\n";
		}
		//if input is up
		if (input == "W")
		{
			if (posX == 0)
				//Check if it is possible to go up and if not post warning
				cout << " You can't go up anymore.\n";
			else
			{
				//Set old position of player to '.'
				grid[posX][posY] = '.';
				// decrease vertical co-ordinate by 1
				posX--;
				//check for trap
				if (grid[posX][posY] == trap)
				{
					cout << "You hit a trap. Sorry!\n";
					gridIt(grid, 0, 0);
					break;
				}
				//check for goal
				if (grid[posX][posY] == goal)
				{
					cout << "You reached your goal. Congrats !!\n";
					grid[posX][posY] = player;
					gridIt(grid, 0, 0);
					break;
				}
				else
				{
					// put the player in the new position
					grid[posX][posY] = player;
					//Display map again
					gridIt(grid, 0, 0);
				}

			}
		}
		//if input is down
		if (input == "S")
		{
			//Check if it is possible to go down and if not post warning
			if (posX == 6)
				cout << " You can't go down anymore.\n";
			else
			{
				//Set old position of player to '.'
				grid[posX][posY] = '.';
				// increase vetical co-ordinate by 1
				posX++;
				//check for trap
				if (grid[posX][posY] == trap)
				{
					cout << "You hit a trap. Sorry!\n";
					gridIt(grid, 0, 0);
					break;
				}
				//check for goal
				if (grid[posX][posY] == goal)
				{
					cout << "You reached your goal. Congrats !!\n";
					grid[posX][posY] = player;
					gridIt(grid, 0, 0);
					break;
				}
				else
				{
					// put the player in the new position
					grid[posX][posY] = player;
					//Display map again
					gridIt(grid, 0, 0);
				}
			}
		}
		//if input is left
		if (input == "A")
		{
			//Check if it is possible to go left and if not post warning
			if (posY == 0)
				cout << " You can't go left anymore.\n";
			else
			{
				//Set old position of player to '.'
				grid[posX][posY] = '.';
				// decrease horizontal co-ordinate by 1
				posY--;
				//check for trap
				if (grid[posX][posY] == trap)
				{
					cout << "You hit a trap. Sorry!\n";
					gridIt(grid, 0, 0);
					break;
				}
				//check for goal
				if (grid[posX][posY] == goal)
				{
					cout << "You reached your goal. Congrats !!\n";
					grid[posX][posY] = player;
					gridIt(grid, 0, 0);
					break;
				}
				else
				{
					// put the player in the new position
					grid[posX][posY] = player;
					//Display map again
					gridIt(grid, 0, 0);
				}
			}
		}
		//if input is right
		if (input == "D")
		{
			//Check if it is possible to go right and if not post warning
			if (posY == 9)
				cout << " You can't go right anymore.\n";
			else
			{
				//Set old position of player to '.'
				grid[posX][posY] = '.';
				// increase horizontal co-ordinate by 1
				posY++;
				//check for trap
				if (grid[posX][posY] == trap)
				{
					cout << "You hit a trap. Sorry!\n";
					gridIt(grid, 0, 0);
					break;
				}
				//check for goal
				if (grid[posX][posY] == goal)
				{
					cout << "You have reached your goal. Congrats !!\n";
					grid[posX][posY] = player;
					gridIt(grid, 0, 0);
					break;
				}
				else
				{
					// put the player in the new position
					grid[posX][posY] = player;
					//Display map again
					gridIt(grid, 0, 0);
				}
			}
		}

	}
	//if input is quit then your above loop is broken so quit message
	if (input == "Q")
	{
		cout << "Quitting already?\n";
	}

	cout << "Thanks for playing!\n";

	char exit;
	cout << "Press any key and Press Enter\n";
	cin >> exit;

	return 0;
}
