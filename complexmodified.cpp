#include <iostream>

using namespace std;

struct complex_t
{
	complex_t()
	{
		real=0.0f;
		imag=0.0f;
	}
	
	~complex_t()
	{
		
	}
	
	float real;
	float imag;
	
	complex_t add(complex_t other) const
	{
		complex_t result;
		result.real=/*this->*/real+other.real;
		result.imag=/*this->*/imag+other.imag;
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
		result.real=real*other.real;
		result.imag=imag*other.imag;
		return result;
	}
	
	complex_t div(complex_t other) const
	{
		complex_t result;
		result.real=real/other.real;
		result.imag=imag/other.imag;
		return result;
	}	
	
	std::istream & read(std::istream & stream)
	{
		return  stream >> real >> imag;
	}

	std::ostream & write(std::ostream & stream) const
	{
		return stream  << real << imag;
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
		}
	}
}
