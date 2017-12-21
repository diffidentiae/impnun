
#include <iostream>

using namespace std;

std::istream & read(std::istream & stream, int & b) 
{
  	int c;
 	if(stream>>c)
  	{
    		b=c;
  	}
 	else 
	{
		std::cout << "An error has occured while reading input data";
	}
	return stream;
}
  
int main() 
{
  	int a,i,j,point=0;
  	cin>>a;
  	int *mas=new int[a];
  	for (i=0;i<a;i++)
    		if (read(cin,mas[i]))
      			;
  
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
