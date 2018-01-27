#include <iostream>
#include <string>
#include <time.h>  
#define N 4

using namespace std;

std::istream & arrayinput(std::istream & stream, int array[][N], int l) 
{
	char c;
	int massivstroki[N];
	int k;
	for (k=0;k<N;k++)
	{
		if (stream>>massivstroki[k])
		{
			array[l][k]=massivstroki[k];
		}
		else 
		{
			std::cout << "An error has occured while reading input data";
		}
	}

	
	return stream;

}

std::ostream & arrayoutput(std::ostream & stream, int  array[][N])
{
	int i,j;
	for (i=0;i<N;i++)
	{
		for (j=0;j<N;j++)
		{
			if (array[i][j] == 0)
			{
				cout.width(4);
				std::cout<<'*';
			}
			else
			{
				cout.width(4);
				std::cout<<array[i][j];
			}	
		}
		cout<<"\n";
	}
}


int main()
{
	srand(time(NULL));
	char question;
	cout<<"2048\nWould you like to input masM Y/N?\n";
	int i, j=0;
	int masM[N][N];
	string vvod;
	if ((question = getchar()) == 'Y' || question == 'y')
	{
		for (i = 0; i<N; i++)
		{
			arrayinput(cin,masM,i);
		}
	}
	else
	{ 
		int ran1, ran2;
		for (i = 0; i<N; i++)
		{
			for (j = 0; j<N; j++)
			{
				ran1 = rand() % 3;
				ran2 = rand() % 11;
				if (ran1 == 0)
				{
					if (ran2<10)
						masM[i][j] = 2;
					else
						masM[i][j] = 4;
				}
				else
					masM[i][j] = 0;
			}
		}
	}

	string c;
	while (getline(cin,c,'\n')&&(c[0]!='q'))
	{
		switch (c[0])
		{
		case 'j':
			for (j = 0; j < N; j++)
			{
				int elem[2] = { 0, N};
				for (i = N - 1; i >= 0; i--)
				{
					if (masM[i][j] != 0)
					{
						if (masM[i][j] == elem[0])
						{
							masM[elem[1]][j] += masM[i][j];
							elem[0] = masM[elem[1]][j];
							if (elem[1] != i)
								masM[i][j] = 0;														
						}
						else
						{
							elem[1]--;
							masM[elem[1]][j] = masM[i][j];
							elem[0] = masM[i][j];
							if (elem[1] != i)
								masM[i][j] = 0;
						}
					}
				}
				elem[0] = 0;				
				elem[1] = N;
			}
			break;


		case 'k':
			for (j = 0; j < N; j++)
			{
				int elem[2] = { 0, -1 };
				for (i = 0; i < N ; i++)
				{
					if (masM[i][j] != 0)
					{
						if (masM[i][j] == elem[0])
						{
							masM[elem[1]][j] += masM[i][j];
							elem[0] = masM[elem[1]][j];
							if (elem[1] != i)
								masM[i][j] = 0;
						}
						else
						{
							elem[1]++;
							masM[elem[1]][j] = masM[i][j];
							elem[0] = masM[i][j];
							if (elem[1] != i)
								masM[i][j] = 0;
						}
					}
				}
				elem[0] = 0;
				elem[1] = -1;
			}
			break;


		case 'h':
			for (i = 0; i < N; i++)
			{
				int elem[2] = { 0, -1 };
				for (j = 0; j < N; j++)
				{
					if (masM[i][j] != 0)
					{
						if (masM[i][j] == elem[0])
						{
							masM[i][elem[1]] += masM[i][j];
							elem[0] = masM[i][elem[1]];
							if (elem[1] != j)
								masM[i][j] = 0;
						}
						else
						{
							elem[1]++;
							masM[i][elem[1]] = masM[i][j];
							elem[0] = masM[i][j];
							if (elem[1] != j)
								masM[i][j] = 0;
						}
					}
				}
				elem[0] = 0;
				elem[1] = -1;
			}
			break;


		case 'l':
			for (i = 0; i < N; i++)
			{
				int elem[2] = { 0, N };
				for (j = N-1; j >= 0; j--)
				{
					if (masM[i][j] != 0)
					{
						if (masM[i][j] == elem[0])
						{
							masM[i][elem[1]] += masM[i][j];
							elem[0] = masM[i][elem[1]];
							if (elem[1] != j)
								masM[i][j] = 0;
						}
						else
						{
							elem[1]--;
							masM[i][elem[1]] = masM[i][j];
							elem[0] = masM[i][j];
							if (elem[1] != j)
								masM[i][j] = 0;
						}
					}
				}
				elem[0] = 0;
				elem[1] = N;
			}
			break;
		}
		
		arrayoutput(cout,masM);
	}
}
