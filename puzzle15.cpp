#include "stdafx.h"
#include <iostream>
#include <string>
#define N 4

using namespace std;

std::ostream & output(std::ostream & stream,int array1[][N])
{
	for (unsigned int i = 0;i < N;i++)
	{
		stream << "+----+----+----+----+\n";
		for (unsigned int j = 0;j < N;j++)
		{
			if (array1[i][j] != 16)
			{
				if (array1[i][j] < 10)
				{
					stream << "| " << "0" << array1[i][j] << " ";
				}
				else
				{
					stream << "| " << array1[i][j] << " ";
				}
			}
			else
			{
				stream << "|" << "    ";
			}
		}
		stream << "|\n";
	}
	stream << "+----+----+----+----+\n";
	return stream;
}

int main()
{
	int array1[N][N] = { {13,14,15,16},{12,11,10,9},{5,6,7,8},{4,3,2,1} };
	int x = 3;
	int y = 0;
	output(cout,array1);
	string op;
	while (getline(cin, op) && (op.size() != 0) && (op[0] != 'q'))
	{
		switch (op[0])
		{
		case'h':
			if (x < N-1)
			{
				array1[y][x] = array1[y][x + 1];
				x++;
				array1[y][x] = 16;
				output(cout, array1);
			}
			break;

		case'j':
			if (y > 0)
			{
				array1[y][x] = array1[y - 1][x];
				y--;
				array1[y][x] = 16;
				output(cout, array1);
			}
			break;

		case'k':
			if (y < N-1)
			{
				array1[y][x] = array1[y + 1][x];
				y++;
				array1[y][x] = 16;
				output(cout, array1);
			}
			break;

		case'l':
			if (x > 0)
			{
				array1[y][x] = array1[y][x - 1];
				x--;
				array1[y][x] = 16;
				output(cout, array1);
			}
			break;

		default:
			cout << "An error has occured while reading input data.";
		}
	}
}

