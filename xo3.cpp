#include <iostream>
#define N 3

using namespace std;

std::ostream & output(std::ostream & stream, char array1[][N])
{
	for (unsigned int i = 0;i < N;i++)
	{
		stream << "+---+---+---+\n";
		for (unsigned int j = 0;j < N;j++)
		{
			stream << "| " << array1[i][j] << " ";
		}
		stream << "|\n";
	}
	stream << "+---+---+---+\n";
	return stream;
}

void optionsoutput(char array1[][N],int & last,char currentchar)
{
	char ypos;
	for (unsigned int i = 0;i < N;i++)
	{
		for (unsigned int j = 0;j < N;j++)
		{
			if (array1[i][j] == ' ')
			{
				last++;
				ypos = 97 + i;
				cout << last << ". mark cell " << ypos << j << " as " << currentchar << endl;
			}
		}
	}
	last++;
	cout << last << ". quit\n";
}

void input(char array1[][N], int last, char currentchar)
{
	unsigned int option;
	if (cin >> option && option < last)
	{
		unsigned int position = 0;
		for (unsigned int i = 0;i < N;i++)
		{
			for (unsigned int j = 0;j < N;j++)
			{
				if (array1[i][j] == ' ')
				{
					position++;
					if (position == option)
					{
						array1[i][j] = currentchar;
					}
				}
			}
		}
	}
	else if (option == last)
	{
		exit(0);
	}
	else
	{
		cout << "An error has occured while reading input data.";
	}
}

void check(char array1[][N],char & currentchar)
{
	for (unsigned int i = 0; i < N;i++)
	{
		if (array1[i][0] != ' ' && array1[i][0] == array1[i][1] && array1[i][1] == array1[i][2])
		{
			output(cout,array1);
			cout << "player " << currentchar << " wonn.";
			exit(0);
		}
		if (array1[0][i] != ' ' && array1[0][i] == array1[1][i] && array1[1][i] == array1[2][i])
		{
			output(cout, array1);
			cout << "player " << currentchar << " wonn.";
			exit(0);
		}
	}
	if (array1[0][0] != ' ' && array1[0][0] == array1[1][1] && array1[1][1] == array1[2][2])
	{
		output(cout, array1);
		cout << "player " << currentchar << " wonn.";
		exit(0);
	}
	if (array1[2][0] != ' ' && array1[2][0] == array1[1][1] && array1[1][1] == array1[0][2])
	{
		output(cout, array1);
		cout << "player " << currentchar << " wonn.";
		exit(0);
	}
	if (currentchar == 'X')
	{
		currentchar = 'Y';
	}
	else
	{
		currentchar = 'X';
	}
}

int main()
{
	char array1[N][N];
	for (unsigned int i = 0;i < N;i++)
	{
		for (unsigned int j = 0;j < N;j++)
		{
			array1[i][j] = ' ';
		}
	}
	char currentch = 'X';
	for (unsigned int i = 0;i < N*N;i++)
	{
		int last = 0;
		output(cout, array1);
		optionsoutput(array1, last, currentch);
		input(array1, last, currentch);
		check(array1,currentch);
	}
}
