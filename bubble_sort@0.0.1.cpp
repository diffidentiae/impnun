#include <iostream>

using namespace std;

std::istream & amountinput(std::istream & stream, int & h)
{
	if (stream>>h)
  		;
  	else
	{
  		std::cout << "An error has occured while reading input data";
	}
	return stream;
}

std::istream & arrayinput(std::istream & stream, int & n, int  * ptr) 

{
	int c,l;
  	for (l=0;l<n;l++)
  	{
    		if(stream>>c)
    		{
     			ptr[l]=c;
    		}
    		else 
		{
			std::cout << "An error has occured while reading input data";
		}
  	}
	return stream;
}
std::ostream & arrayoutput(std::ostream & stream, int & n, int  * ptr)
{
	int p;
	for (p=0;p<n;p++)
	{
		if (stream << ptr[p] && stream << " ")
			;
	}
	return stream;
}
int main() 
{
  	int a;
  	if (amountinput(cin,a))
		;
  	int *mas=new int[a];
	int i,j;
  	if (arrayinput(cin,a,mas))
	{
		for(i=0;i<a;i++)
		{
			for(j=1;j<a;j++)
			{
				if (mas[j-1]>mas[j])
				{
					std::swap(mas[j-1],mas[j]);
				}  
			}
		}
	}
	if (arrayoutput(cout,a,mas))
		;
  	delete [] mas;
}
