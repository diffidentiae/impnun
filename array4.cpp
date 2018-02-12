#include <iostream>
#define N 10

using namespace std;

std::istream & arrayinput(std::istream & stream, int array1[])
{
	char c;
	for (unsigned int i = 0;i<N;i++)
	{
		if (stream >> array1[i])
		{
			c = getchar();
			if (c == '\n'&&i != N - 1)
			{
				cout << "An error has occurred while reading numbers";
				exit(0);
			}
		}
		else
		{
			cout << "An error has occurred while reading numbers";
		}
	}
	return stream;
}

int main()
{
	int array1[N], inverse = 0;
	if (arrayinput(cin, array1))
	{
		for (unsigned int i = 1;i < N;i++)
		{
			
			for (unsigned int j = 0;j < i;j++)
			{
				if (array1[j] > array1[i])
				{
					inverse++;
				}
			}
		}
	}
	cout << inverse;
}
