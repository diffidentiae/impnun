#include "stdafx.h"
#include <iostream>

using namespace std;

bool amountinput(std::istream & stream, unsigned int & size)
{
	return bool(stream >> size);
}

std::istream & arrayinput(std::istream & stream, unsigned int size, int * ptr)
{
	for (unsigned int i = 0; i < size; i++)
	{
		if (!(stream >> ptr[i]))
		{
			std::cout << "An error has occured while reading input data";
		}
	}
	return stream;
}

void heapsort(int elements[], int leftwall, int rightwall)
{
	int maxposition;
	bool check = false;
	while ((leftwall * 2 <= rightwall) && (check == false))
	{
		if (leftwall * 2 == rightwall)
		{
			maxposition = leftwall * 2;
		}
		else if (elements[leftwall * 2] > elements[leftwall * 2 + 1])
		{
			maxposition = leftwall * 2;
		}
		else
		{
			maxposition = leftwall * 2 + 1;
		}
		if (elements[leftwall] < elements[maxposition])
		{
			swap(elements[leftwall],elements[maxposition]);
			leftwall = maxposition;
		}
		else
		{
			check = true;
		}
	}
}

void heapsortalg(int elements[], unsigned int size)
{
	for (int i = (size / 2) - 1; i > -1; i--)
		heapsort(elements, i, size);
	for (int i = size - 1; i > 0; i--)
	{
		swap(elements[0],elements[i]);
		heapsort(elements, 0, i - 1);
	}
}

std::ostream & arrayoutput(std::ostream & stream, unsigned int size, int  * ptr)
{
	for (unsigned int i = 0; i < size; i++)
	{
		stream << ptr[i] << " ";
	}
	return stream;
}

int main()
{
	unsigned int size;
	if (amountinput(cin, size))
	{
		int *mas = new int[size];
		if (arrayinput(cin, size, mas))
		{
			heapsortalg(mas, size);
			arrayoutput(cout, size, mas);
			delete[] mas;
		}
	}
}

