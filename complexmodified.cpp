#include <iostream>

using namespace std;

struct complex_t
{
	complex_t()
	{
		real=0.0f;
		imag=0.0f;
	}
	
	float real;
	float imag;
	
	complex_t add(complex_t other) const
	{
		complex_t result;
		result.real=real+other.real;
		result.imag=imag+other.imag;
		return result;
	}

	complex_t sub(complex_t other) const
	{
		complex_t result;
		result.real=real-other.real;
		result.imag=imag-other.imag;
		return result;
	}
	
	complex_t multi(complex_t other) const
	{
		complex_t result;
		result.real=real*other.real - imag*other.imag;
		result.imag=real*other.imag + imag*other.real;
		return result;
	}
	
	complex_t div(complex_t other) const
	{
		complex_t result;
		result.real=(real*other.real - imag*other.imag*(-1)) / (other.real*other.real - other.imag*other.imag);
		result.imag=(imag*other.real - real*other.imag*(-1)) / (other.real*other.real - other.imag*other.imag);
		return result;
	}	
	
	std::istream & read(std::istream & stream)
	{
		char op;
		return  stream >> op >> real>> op >> imag >> op;
	}

	std::ostream & write(std::ostream & stream) const
	{
		return stream  << "(" << real << ", " << imag << ")";
	}

};

int main()
{
	complex_t a,b,result;
	char op;
	if (a.read(cin)&& std::cin>>op && b.read(cin))
	{
		switch(op)
		{
			case '+':
				result=a.add(b);
				result.write(cout);
				break;
				
			case '-':
				result=a.sub(b);
				result.write(cout);
				break;	
				
			case '*':
				result=a.multi(b);
				result.write(cout);
				break;	
			
			case '/':
				result=a.div(b);
				result.write(cout);
				break;
			
			default :
				cout << "An error has occured while reading input data";
		}
	}
}
