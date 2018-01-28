
#include <iostream>

using namespace std;

std::istream & amountinput(std::istream & stream, int & h)
{
	if (stream>>h)
	{
  		;
	}
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
		stream << ptr[p] && stream << " ";
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
	int point;
	if (arrayinput(cin,a,mas))
	{
		for(i=1;i<a;i++)
		{
			point=i;
			for(j=i-1;j>=0;j--)
			{
				if (mas[point]<mas[j])
				{
					std::swap(mas[point],mas[j]);
					point=j;
				} 
			}
		}
	}
	arrayoutput(cout,a,mas);
	delete [] mas;
}
