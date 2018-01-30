#include <iostream>

using namespace std;

std::istream & amountinput(std::istream & stream, int & length)
{
	if (stream>>length)
  		;
  	else
	{
  		std::cout << "An error has occured while reading input data";
	}
	return stream;
}

std::istream & arrayinput(std::istream & stream, int length, int  * array) 

{
	int c,l;
  	for (l=0;l<length;l++)
  	{
    		if(stream>>c)
    		{
     			array[l]=c;
    		}
    		else 
		{
			std::cout << "An error has occured while reading input data";
		}
  	}
	return stream;
}

void mergealg(int * array, int leftwall, int rightwall, int middle)
{
	int leftside = leftwall,rightside = middle+1;
	int currentpos = 0, mergearray[rightwall - leftwall + 1];
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

std::ostream & arrayoutput(std::ostream & stream, int & length, int  * ptr)
{
	int p;
	for (p=0;p<length;p++)
	{
		stream << ptr[p];
		stream << " ";
	}
	return stream;
}
int main() 
{
  	int a;
  	amountinput(cin,a);
  	int *mas=new int[a];
  	arrayinput(cin,a,mas);
	mergesortalg(mas,0,a-1);
	arrayoutput(cout,a,mas);
  	delete [] mas;
}
