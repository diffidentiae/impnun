#include <iostream>
#define N 10

using namespace std;

std::istream & arrayinput(std::istream & stream,int array1[])
{
	char c;
	for(unsigned int i = 0;i<N;i++)
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
	int array1[N], array2[N];
	if (arrayinput(cin, array1) && arrayinput(cin, array2))
	{
		;
	}
	else
	{
		cout << "An error has occurred while reading numbers";
	}

	int max = array1[0]+array2[0];
	for (int i = 0;i < N;i++)
	{
		for (int j = i;j > -1;j--)
		{
			if ((array1[j]+array2[i]) > max)
			{
				max = array1[j] + array2[i];
			}
		}
	}

	
	cout << max;
}
