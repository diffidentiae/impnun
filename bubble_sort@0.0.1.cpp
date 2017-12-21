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
			for(j=1;j<a;j++)
			{
				if (mas[j-1]>mas[j])
				{
					std::swap(mas[j-1],mas[j]);
				}  
			}
		}
  	
	cout<<"massiv: ";
  	for (i=0;i<a;i++)
    		cout<<mas[i]<<" ";
  	delete [] mas;
}
