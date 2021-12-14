#include <iostream>
#include <string>

int main() {
	std::string inputString;
	long long resultSum = 0;
	while (std::cin >> inputString) {
		int Temp = 0;
		bool isNegative = false;
		for (int i = 0; i < inputString.length(); i++) {
			if (inputString[i] > 47 && inputString[i] < 58) {
				Temp = Temp * 10 + int(inputString[i]) - 48;
			}
			else {
				if (Temp != 0) {
					if (isNegative == true) {
						resultSum -= Temp;
						isNegative = false;
					}
					else
						resultSum += Temp;
				}
				Temp = 0;
			}
			if (i == inputString.length() - 1) {
				if (isNegative == true) {
					resultSum -= Temp;
					isNegative = false;
				}
				else
					resultSum += Temp;
			}
			if (inputString[i] == 45)
				isNegative = true;
		}
	}
	std::cout << resultSum;
}
