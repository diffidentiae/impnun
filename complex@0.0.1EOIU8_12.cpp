#include "stdafx.h"
#include <iostream>
#include <complex>

using namespace std;

struct complex_t 
{
	float real;
	float imag;
};
std::istream & read(std::istream & stream, complex_t & complex) 
{
	char c;
	float real;
	float imag;
	if (stream >> c && c == '(' && 
		stream >> real && 
		stream >> c && c == ',' &&
		stream >> imag &&
		stream >> c && c == ')') 
	{
		complex.real = real;
		complex.imag = imag;
	}

	else 
	{
		std::cout << "An error has occured while reading input data";
	}
	return stream;

}
int main()
{
	complex_t compl1;
	complex_t compl2;
	char zn;
	if(read(cin,compl1)&&(cin>>zn)&&read(cin,compl2))
		switch (zn)
		{
			case '+':
				compl1.real = compl1.real + compl2.real;
				compl1.imag = compl1.imag + compl2.imag;
				break;
			case '-':
				compl1.real = compl1.real - compl2.real;
				compl1.imag = compl1.imag - compl2.imag;
				break;
			case '*':
				compl1.real = compl1.real*compl2.real - compl1.imag*compl2.imag;
				compl1.imag = compl1.real*compl2.imag + compl1.imag*compl2.real;
				break;
			case '/`':
				compl1.real = (compl1.real*compl2.real - compl1.imag*compl2.imag*(-1)) / (compl2.real*compl2.real - compl2.imag*compl2.imag);
				compl1.real = (compl1.imag*compl2.real - compl1.real*compl2.imag*(-1)) / (compl2.real*compl2.real - compl2.imag*compl2.imag);
				break;
			default:
				std::cout << "An error has occured while reading input data";
				break;
		}
	
	cout <<"resultat:  " <<"( "<<compl1.real<<", "<<compl1.imag<<")";

}
