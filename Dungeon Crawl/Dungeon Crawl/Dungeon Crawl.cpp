// Dungeon Crawl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string input;
	char player = 'G', Trap = 'T', Goal = 'X';
	char grid[7][10];
	int i, j, posX = 1, posY = 1, skip = 0;
	for (i = 0; i < 7; ++i)
	{
		for (j = 0; j < 10; ++j)
			grid[i][j] = '.';
	}

	grid[1][1] = player;
	grid[3][7] = Trap;
	grid[5][2] = Trap;
	grid[2][5] = Trap;
	grid[6][9] = Goal;

	cout << "\n WELCOME TO DUNGEON CRAWL!! \n";
	cout << "\n ARRIVE SAFELY AT THE GOAL TO GET TREASURE!! \n";
	cout << "\n \n *INSTRUCTIONS* \n \n ";
	cout << "You are (G), and must make it to the end of the grid (X), \n";
	cout << " in order to win the game. \n";
	cout << " TIP.  Watch out for the Traps (T) along the way!! \n\n";

	for (i = 0; i < 7; ++i)
	{
		for (j = 0; j < 10; ++j)
			cout << grid[i][j];
		cout << endl;
	}
	while (grid[6][9] != player)
	{
		do {
			cout << "\n Type in a direction of your choice: \n";
			cout << "\n up, down, left, right OR quit\n";
			cin >> input;

			if (input != "up" && input != "down" && input != "left" && input != "right" && input != "quit")
				cout << "\nThat's not a valid input. Try again.\n";
		}

		while (input != "up" && input != "down" && input != "left" && input != "right" && input != "quit");

		if (input == "up")
		{
			for (j = 0; j < 10; ++j)
			{
				if (grid[0][j] == player)
				{
					cout << "You cannot move up from that position!\n\n";
					skip = 1;

				}
			}
			if (skip == 0)
				grid[posY][posX] = '.';
			grid[posY + 1][posX] = player;
		}
	}
	if (input == "down")
	{
		for (j = 0; j < 9; ++j)
		{
			if (grid[6][j] == player)
			{
				cout << "You cannot move up from that position!\n\n";
				skip = 1;
			}
		}
		if (skip == 0)
		{
			grid[posY][posX] = '.';
			grid[posY + 1][posX] = player;
		}
	}
	if (input == "Left")
	{
		for (i = 0; i < 7; ++i)
		{
			if (grid[i][0] == player)
			{
				cout << "You cannot move up from that position!\n\n";
				skip = 1;
			}
		}
		if (skip == 0)
		{
			grid[posY][posX] = '.';
			grid[posY + 1][posX] = player;
		}
	}
	if (input == "Right")
	{
		for (i = 0; i < 6; ++i)
		{
			if (grid[i][9] == player)
			{
				cout << "You cannot move up from that position!\n\n";
				skip = 1;
			}
		}
		if (skip == 0)
		{
			grid[posY][posX] = '.';
			grid[posY + 1][posX] = player;
		}
	}
	if (input == "quit")
		return 1; //exit program with status 1 to indicate a non normal exit

	if (grid[3][7] == player || grid[5][2] == player || grid[2][5] == player)
	{
		cout << "You hit a Trap!";
		return 1; //exit program with status 1 to indicate a non normal exit
	}
	for (i = 0; i < 7; ++i)
	{
		for (j = 0; j < 10; ++j)
			cout << grid[i][j];
		cout << endl;
	}

		if (grid[6][9] == 'G')
		cout << "CONGRATS!! YOU FOUND THE TREASURE!!\n ";

		cout << "\n Thanks for playing!!\n";

		return 0;
		}