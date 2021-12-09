#include <iostream>

class vector1 {
	int * vectorData; //указатель на массив данных
	int length; //число элементов
	public:
	vector1();
	vector1(int N);
	~vector1();
	int lengthPush();
	void input();
	void output();
	int findMax();
};

int main() {
	int length1, length2;
	std::cout << "Введите длину вектора: ";
	std::cin >> length1;
	vector1 a(length1);
	a.input();
	a.output();
	std::cout << "Максимум: " << a.findMax();
	return 0;
}

vector1::vector1(){
	length = 0;
	vectorData = nullptr;
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
		std::cout << "Введите " << length << " элементов через enter: \n";
		for (int i = 0; i < length; i++) {
			
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
		for (int i = 0; i < lengthPush(); i++) {
			if (max < vectorData[i])
				max = vectorData[i];
		}
		return max;
	}
	return 0;
}

int vector1::lengthPush() {
	return this->length;
}
