// Chapter7.13.cpp
//

#include "stdafx.h"
#include <iostream>
using namespace std;

const int WIDTH = 20, HEIGHT = 20;

void copy_board(int board1[HEIGHT + 2][WIDTH + 2], int board2[HEIGHT + 2][WIDTH + 2]); //function to copy board1 onto board2
void new_generation(int board[HEIGHT+2][WIDTH+2]); //calculates what the next generation should look like
void display_board(int board[HEIGHT+2][WIDTH+2]); //output board to the screen

int main()
{

	char repeat;
	//using a board with a border for ease of calculation, but only displaying the inner shell
	//live and dead cells stored as 1s and 0s

	cout << "This is Conway's Game of Life. Keep pressing Enter to see the next generation: ";

	int board[HEIGHT + 2][WIDTH + 2] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
	};

	do
	{
		display_board(board);
		cin.get(repeat);
		new_generation(board);

	}while (repeat == '\n');
		
	return 0;
}

void copy_board(int board1[HEIGHT + 2][WIDTH + 2], int board2[HEIGHT + 2][WIDTH + 2])
{
	for (int i = 0; i < HEIGHT + 2; i++)
	{
		for (int j = 0; j < WIDTH + 2; j++)
		{
			board2[i][j] = board1[i][j];
		}
	}
}

void new_generation(int board[HEIGHT + 2][WIDTH + 2])
{
	int temp_board[HEIGHT+2][WIDTH+2];
	int neighbours;
	
	for (int i = 0; i < HEIGHT+2; i++)
	{
		for (int j = 0; j < WIDTH + 2; j++)
		{
			if (i == 0 || j == 0 || i == HEIGHT + 2 || j == WIDTH + 2)
				temp_board[i][j] = 0;
			else
			{
				//counting alive neighbouring cells
				neighbours = board[i - 1][j - 1] + board[i - 1][j] + board[i - 1][j + 1] + board[i][j - 1] + board[i][j + 1] + board[i + 1][j - 1] + board[i + 1][j] + board[i + 1][j + 1];
				if (board[i][j] == 1)
				{
					if (neighbours < 2 || neighbours > 3)
						temp_board[i][j] = 0; //cell dies due to loneliness or overcrowding
					else
						temp_board[i][j] = 1;
				}

				else
				{
					if (neighbours == 3)
						temp_board[i][j] = 1; //birth of a new cell
					else
						temp_board[i][j] = 0;
				}
			}
		}
	}

	copy_board(temp_board, board);


}

void display_board(int board[HEIGHT+2][WIDTH+2]) 
{
	for (int i = 1; i < HEIGHT+1; i++) //only displaying inner shell
	{
		for (int j = 1; j < WIDTH+1; j++)
		{
			if (board[i][j] == 1)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
}