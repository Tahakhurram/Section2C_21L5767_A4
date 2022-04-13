#include <string>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <cstring>
#include <string>
using namespace std;

void filereader(string arr[]);
int longest(string arr[]);
void gamefunction(int len, string arr[]);

int main()
{
	int len = 0;
	string arr[7];
	filereader(arr);
	len = longest(arr);
	if (len < 10)
	{
		len = 10;
	}
	system ("cls");
	gamefunction(len, arr);
	return 0;
}




int longest(string arr[])
{
	int occurence, newmax;
	for (int i = 0; i < 6; i++)
	{
		occurence = arr[0].length();
		if (arr[i].length() < arr[i + 1].length())
		{
			newmax = arr[i + 1].length();
		}
		if (newmax > occurence)
		{
			occurence = newmax;
		}
	}
	return occurence;
}

void filereader(string arr[])
{
	ifstream fin;
	fin.open("input_Q1.txt");
	string line;
	int i = 0;
	while (getline(fin, line) && !fin.eof())
	{

		arr[i] = line;
		fin >> arr[i];
		i++;
	}
	fin.close();
}

void gamefunction(int len, string arr[])
{
	char grid[len][len];
	int r;
	char c;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			r = rand() % 26;
			c = 'a' + r;
			grid[i][j] = c;
		}
	}
	for (int index = 0; index < 7; index++)
	{
		if (arr[index].length() == len)
		{ 
			int row = 0;
			int col = 0;
			for (int i = 0; arr[index][i] != '\0'; i++, row++, col++)
			{
				grid[row][col] = arr[index][i];
			}
		}
		
		else if (arr[index].length() % 2 == 0)
		{ 
			int row = rand() % len;
			int col = rand() % 3;
			for (int i = 0; arr[index][i] != '\0'; i++, col++)
			{
				grid[row][col] = arr[index][i];
			}
		}
		
		else if (arr[index].length() % 2 != 0)
		{ 
			int row = rand() % 5;
			int col = rand() % len;
			for (int i = 0; arr[index][i] != '\0'; i++, row++)
			{
				grid[row][col] = arr[index][i];
			}
		}
	}
ofstream fout("output_Q1.txt");
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			fout << grid[i][j] << " ";
		}
		fout << endl;
	}
	fout.close();
}
