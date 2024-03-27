class Calculator {
public:
	double num1, num2;


	bool set_num1(double num1) {
		if (num1 > 0) {
			this->num1 = num1;
			return true;
    }
		else
		{
			std::cout << " Неверный ввод!" << std::endl;
      return false;
		}
    	}
	bool set_num2(double num2) {
		if (num2 > 0) {
			this->num2 = num2;
			return true;
		}
		else
		{
			std::cout << " Неверный ввод!" << std::endl;
			return false;
		}
	}

	double add(double num1, double num2) {
		double result = num1 + num2;
		std::cout << "num1 + num2 = " << result << std::endl;
		return result;
	}
	double multiply(double num1, double num2) {
		double result = num1 * num2;
		std::cout << "num1 * num2 = " << result << std::endl;
		return result;
	}
	double subtract_1_2(double num1, double num2) {
		double result = num1 - num2;
		std::cout << "num1 - num2 = " << result << std::endl;
		return result;
	}
	double subtract_2_1(double num1, double num2) {
		double result = num2 - num1;
		std::cout << "num2 - num1 = " << result << std::endl;
		return result;
	}
	double divide_1_2(double num1, double num2) {
		double result = num1 / num2;
		std::cout << "num1 / num2 = " << result << std::endl;
		return result;
	}
	double divide_2_1(double num1, double num2) {
		double result = num2 / num1;
		std::cout << "num2 / num1 = " << result << std::endl;
		return result;
	}
};

int main() {
	setlocale(LC_ALL, "Rus");
	double x, y;
	Calculator p;
	do {
		std::cout << " Введите num1: ";
		std::cin >> x;
		std::cout << " Введите num2: ";
		std::cin >> y;
		if (x > 0 && y > 0) {
			p.add(x, y);
			p.multiply(x, y);
			p.subtract_1_2(x, y);
			p.subtract_2_1(x, y);
			p.divide_1_2(x, y);
			p.divide_2_1(x, y);
		}
		else {
			p.set_num1(x);
			p.set_num2(y);
		};
	} while (true);
	return 0;
}
