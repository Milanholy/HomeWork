#include <iostream>


enum months  {
	январь = 1,
	февраль = 2,
	март = 3,
	апрель,
	май,
	июнь,
	июль,
	август,
	сентябрь,
	октябрь,
	ноябрь,
	декабрь
};



int main() {
	setlocale(LC_ALL, "Rus");
	int count;
	std::cout << "Введите номер месяца: ";
	std::cin >> count;
	switch (count) {
	case 0:
		std::cout << "До свидания"<<std::endl;
		break;
	case 1:
		std::cout << "январь" << std::endl;
		break;
	case 2:
		std::cout << "февраль" << std::endl;
		break;
	case 3:
		std::cout << "март" << std::endl;
		break;
	case 4:
		std::cout << "апрель" << std::endl;
		break;
	case 5:
		std::cout << "май" << std::endl;
		break;
	case 6:
		std::cout << "июнь" << std::endl;
		break;
	case 7:
		std::cout << "июль" << std::endl;
		break;
	case 8:
		std::cout << "август" << std::endl;
		break;
	case 9:
		std::cout << "сентябрь" << std::endl;
		break;
	case 10:
		std::cout << "октябрь" << std::endl;
		break;
	case 11:
		std::cout << "ноябрь" << std::endl;
		break;
	case 12:
		std::cout << "декабрь" << std::endl;
		break;

	default:
		std::cout << "Неправильный номер!" << std::endl;
	}
	return 0;
}
