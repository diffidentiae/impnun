#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <time.h>  
#define N 4

using namespace std;
int main()
{
	int i, j, ran1, ran2;
	int masM[N][N]; /* = { {2,0,0,0},{2,2,0,0},{2,0,4,0},{2,2,0,0} }; */
	char c;
	srand(time(NULL));
	printf("2048\nWould you like to input masM Y/N?\n");
	if ((c = getchar()) == 'Y' || c == 'y')
	{
		for (i = 0; i<N; i++)
		{
			for (j = 0; j<N; j++)
				scanf_s("%d",masM[i][j]);
			printf("\n");
		}
	}
	else
	{
		for (i = 0; i<N; i++)
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
	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N; j++)
			if (masM[i][j] == 0)
			{
				cout.width(4);
				std::cout<<'*';
			}
			else
			{
				cout.width(4);
				std::cout<<masM[i][j];
			}
		printf("\n");
	} 
	while (std::cin >> c && c != 'q')
	{
		switch (c)
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
				for (j = N - 1; j >= 0; j--)
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
		int c = 1,ran;
		do
		{
			i = rand() % N;
			j = rand() % N;
			if (masM[i][j] == 0)
			{
				ran = rand() % 11;
				if (ran < 10)
					masM[i][j] = 2;
				else
					masM[i][j] = 4;
				break;
			}
		} while (masM[i][j] != 0);

	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N; j++)
			if (masM[i][j] == 0)
			{
				cout.width(4);
				std::cout<<'*';
			}
			else
			{
				cout.width(4);
				std::cout<<masM[i][j];
			}
		printf("\n");
	}
	}
}
