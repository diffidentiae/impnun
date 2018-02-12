#include <iostream>

using namespace std;

bool amountinput(std::istream & stream, unsigned int & size)
{
	return bool(stream >> size);
}

std::istream & arrayinput(std::istream & stream, unsigned int size, int * ptr)
{
	for(unsigned int i = 0; i < size; i++)
	{
		if( !(stream >> ptr[i]) )
		{
			std::cout << "An error has occured while reading input data";
		}
	}
	return stream;
}

void mergealg(int * array, int leftwall, int rightwall, int middle)
{
	int leftside = leftwall,rightside = middle+1;
	int currentpos = 0;
	int * mergearray = new int[rightwall - leftwall + 1];
	while (leftside <= middle && rightside <=rightwall)
	{
		if (array[leftside] < array[rightside])
		{
			mergearray[currentpos] = array[leftside];
			leftside++;
			currentpos++;
		}
		else
		{
			mergearray[currentpos] = array[rightside];
			rightside++;
			currentpos++;
		}
	}
	while (leftside <= middle)
	{
		mergearray[currentpos]=array[leftside];
		leftside++;
		currentpos++;
	}
	while (rightside <= rightwall)
	{
		mergearray[currentpos]=array[rightside];
		rightside++;
		currentpos++;
	}
	int i;
	for (i=leftwall;i<=rightwall;i++)
	{
		array[i]=mergearray[i-leftwall];
	}
	delete [] mergearray;	
}

void mergesortalg(int * array, int leftwall, int rightwall)
{
	int middle;
	if (leftwall<rightwall)
	{
		middle = (leftwall+rightwall)/2;
		mergesortalg(array,leftwall,middle);
		mergesortalg(array,middle+1,rightwall);
		mergealg(array,leftwall,rightwall,middle);
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
  	if (amountinput(cin,size))
	{
		int *mas=new int[size];
		if (arrayinput(cin,size,mas))
		{
			mergesortalg(mas,0,size-1);
			arrayoutput(cout,size,mas);
			delete [] mas;
		}
	}
}
