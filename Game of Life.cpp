//Final Project
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <windows.h>
using namespace std;
//Declaring the size of the grid globally
const int x = 50;
const int y = 50;
//Function for checking neighbors and declaring cells alive and dead
void check(int grid[x + 1][y + 1], int grid2[x + 1][y + 1])
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			int sum = 0;
			if (grid[i][j + 1] == 1)        //Checking neighbor on the bottom
			{
				sum++;
			}
			if (j > 0 && (grid[i][j - 1]))        //Checking neighbor on the top
			{
				sum++;
			}
			if (grid[i + 1][j])        //Checking the neighbor on the right
			{
				sum++;
			}
			if (i > 0 && (grid[i - 1][j]))        //Checking the neighbor on the left
			{
				sum++;
			}
			if (grid[i + 1][j + 1])        //Checking the neighbor on the bottom right diagnol
			{
				sum++;
			}
			if ((i > 0 && j > 0) && (grid[i - 1][j - 1]))        //Checking the neighbor on the top left diagnol
			{
				sum++;
			}
			if (j > 0 && (grid[i + 1][j - 1]))        //Checking the neighbor on the top right diagnol
			{
				sum++;
			}
			if (i > 0 && (grid[i - 1][j + 1]))        //Checking the neighbor on the bottom left diagnol
			{
				sum++;
			}
			//Declaring status of next cells
			if (grid[i][j] == 0 && sum == 3)
			{
				grid2[i][j] = 1;
			}
			if (grid[i][j] == 1 && (sum == 2 || sum == 3))
			{
				grid2[i][j] = 1;
			}
			if (grid[i][j] == 1 && (sum == 0 || sum == 1))
			{
				grid2[i][j] = 0;
			}
			if (grid[i][j] == 1 && sum > 3)
			{
				grid2[i][j] = 0;
			}
		}
	}
}
//Function for swapping alive cells between grid 2 and grid 3
void declare(int grid[x + 1][y + 1], int grid2[x + 1][y + 1])
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			grid[i][j] = grid2[i][j];
		}
	}
}
//Function for displaying initial grid
void display(int grid[x + 1][y + 1])
{
	fstream file("text.txt", ios::app);
	for (int i = 0; i < x; i++)
	{
		file << endl;        //Skipping a line in file
		cout << endl;
		for (int j = 0; j < y; j++)
		{

			if (grid[i][j] == 1)        //Condition for alive cells (Alive cells = 1)
			{
				cout << "<>";        //Printing live cells
				file << "*";        //Saving alive cells in a text file
			}
			if (grid[i][j] == 0)        //Condition for dead cells (Dead Cells = 0)
			{
				cout << "  ";        //Printing dead cells
				file << " ";        //Saving dead cells in a text file
			}
		}
	}
}
void user_input()
{
	cout << "Enter the name of the file you want to use? " << endl << endl;
	cout << "You can choose from the following text files" << endl << "1.  blinker.txt" << endl << "2.  block.txt" << endl << "3.  beehive.txt" << endl << "4.  toad.txt" << endl << endl;
}
int main()
{
	int grid[x + 1][y + 1] = { 0 };        //Declaring the extreme boundries 0 in the array to avoid dealing with junk values
	int grid2[x + 1][y + 1] = { 0 };        //Declaring the extreme boundries 0 in the array to avoid dealing with junk values
	int sum = 0;
	string file_name;        //Declaring the variable to take file name as input from the user

	user_input();        //Calling function to display a question and ask the user what file he wants to use

	cin >> file_name;        //Take the file name from the user
	fstream file;
	int iterations, number, x_axis, y_axis;
	file.open(file_name, ios::in);
	file >> iterations;        //Taking the first number from the text file as total number of iterations
	file >> number;        //Taking the second number from the text file as total number of intial alive cells

	for (int i = 0; i < number; i++)
	{
		file >> x_axis;        //Taking the X-coordintes of alive cells as input in the integer 'x_axis'
		file >> y_axis;        //Taking the Y-coordintes of alive cells as input in the integer 'y_axis'
		grid[x_axis][y_axis] = 1;
	}
	file.close();

	for (int X = 0; X < iterations; X++)
	{
		cout << endl;
		Sleep(250);        //Pausing for 250 milli seconds
		system("CLS");         //Clearing screen after displaying each grid

		display(grid);        //Calling the display function to display the intial alive cells
		check(grid, grid2);        //Calling the check functions to check for neigbors and set alive values of cells in grid 3
		declare(grid, grid2);        //Calling declare function to swap the values of alive cells between grid 2 and grid 3
	}
	return 0;
}
