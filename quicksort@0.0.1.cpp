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

void sortalg(int * array,int length)
{
	int leftside = 0,rightside = length;
	int pivot = array[length/2];
	int amount = length;
	do
	{
		while (array[leftside]<pivot)
		{
			leftside++;
		}
		while (array[rightside]>pivot)
		{
			rightside--;
		}
		if (leftside <= rightside)
		{
			swap(array[leftside],array[rightside]);
			leftside++;
			rightside--;
		}
	} while (leftside <= rightside); 
	if (rightside > 0)
	{
		sortalg(array,rightside);
	}
	if ((amount-leftside) > 0)
	{
		sortalg(array + leftside,amount-leftside);
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
  	int wall=0;
	  sortalg(mas,a-1);
	  arrayoutput(cout,a,mas);
  	delete [] mas;
}
