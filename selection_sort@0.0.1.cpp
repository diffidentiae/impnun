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
}
