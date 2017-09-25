#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	int a, b;
	int mda;
	char sgn;
	printf("Для завершения нажмите p");
	do while (getchar() != 'p') 
	{
		printf("Введите пример\n");
		cin >> a >> sgn >> b;
		switch (sgn)
		{
		case '-':mda = a - b;
			cout«"= "«mda«endl;break;
		case '+':mda = a + b;
			cout«"= "«mda«endl;break;
		case '/':mda = a / b;
			cout«"= "«mda«endl;break;
		case '%':mda = a % b;
			cout«"= "«mda«endl;break;
		case '^':mda = a ^ b;
			cout«"= "«mda«endl;break;
		case '&':mda = a & b;
			cout«"= "«mda«endl;break;
		case '|':mda = a | b;
			cout«"= "«mda«endl;break;
		case '<':mda = a « b;
			cout«"= "«mda«endl;break;
		case '>':mda = a » b;
			cout«"= "«mda«endl;break;

		}
	}

	return 0;
}
