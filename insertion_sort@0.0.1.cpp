
#include <iostream>

using namespace std;

std::istream & reada(std::istream & stream, int & h)
{
	if (stream>>h)
  	;
  else
  	std::cout << "An error has occured while reading input data";
	return stream;
}

std::istream & read(std::istream & stream, int & n, int  * ptr) 

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
int main() 
{
  	int a,i,j;
  	if (reada(cin,a))
		;
  	int *mas=new int[a];
	if (read(cin,a,mas))
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
  	cout<<"massiv: ";
  	for (i=0;i<a;i++)
    		cout<<mas[i]<<" ";
	delete [] mas;
}
