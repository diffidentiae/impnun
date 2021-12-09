#include <iostream>

class vector1 {
	int * vectorData; //указатель на массив данных
	int length; //число элементов
	public:
	vector1();
	vector1(int N);
	vector1(vector1 Copy);
	~vector1();
	void input();
	void output();
	int findMax();
	vector1 operator + (vector1 rightVec);
	vector1 operator - (vector1 rightVec);
};

int main() {
	int length1, length2;
	std::cout << "Введите длину первого вектора: ";
	std::cin >> length1;
	vector1 a(length1);
	std::cout << "Введите длину второго вектора: ";
	std::cin >> length2;
	vector1 b(length2);


	
	return 0;
}

vector1::vector1(int N) {
	length  = N;
	vectorData = new int[length];
}

vector1::~vector1() {
	if (vectorData != nullptr)
		delete(vectorData);
}

void vector1::input() {
	if (length <= 0 || vectorData == nullptr) {
		std::cout << "ошибка инициализации массива";
	}
	else {
		for (int i = 0; i < length; i++) {
			std::cout << "Введите " << length << " элементов через enter: \n";
			std::cin >> vectorData[i]; 
		}

	}
}

void vector1::output(){
	if (length <= 0 || vectorData == nullptr) {
		std::cout << "ошибка инициализации массива";
	}
	else {
		for (int i = 0; i < length; i++) {
			std::cout << i+1 << ". " << vectorData[i] << "\n"; 
		}

	}
}

int vector1::findMax() {
	if (length <= 0 || vectorData == nullptr) {
		std::cout << "ошибка инициализации массива";
	}
	else {
		int max = vectorData[0];
		for (int i = 0; i < length; i++) {
			if (max < vectorData[i])
				max = vectorData[i];
		}
		return max;
	}
	return 0;
}

vector1 vector1::operator + (vector1 rightVec) {
	if ()
	vector1 result();
	return ;
}

vector1 vector1::operator - (vector1 rightVec) {

 }
