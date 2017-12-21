#include <iostream>

using namespace std;

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
  	cin>>a;
  	int *mas=new int[a];
	if (read(cin,a,mas))
		for(i=0;i<a;i++)
		{
			for(j=i;j<a;j++)
			{
				if (mas[j]<mas[point])
				point=j;
			}
			std::swap(mas[i],mas[point]);
			point=i+1;
		}
  	cout<<"massiv: ";
  	for (i=0;i<a;i++)
   		cout<<mas[i]<<" ";
	delete [] mas;
}
