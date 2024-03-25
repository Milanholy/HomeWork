struct Address
{
 std::string City;
 std::string Street;
 int number_house;
 int number_flat;
 int index;
};

void input_address(Address& address) {
 std::cout << "Введите город: ";
 std::cin >> address.City;
 std::cout << "Введите улицу: ";
 std::cin >> address.Street;
 std::cout << "Введите номер дома: ";
 std::cin >> address.number_house;
 std::cout << "Введите номер квартиры: ";
 std::cin >> address.number_flat;
 std::cout << "Введите индекс: ";
 std::cin >> address.index;
}


int main() {
 setlocale(LC_ALL, "Rus");
 SetConsoleCP(1251);
 SetConsoleOutputCP(1251);
 Address address;
 input_address(address);
 std::cout << "Город: " << address.City<< std::endl;
 std::cout << "Улица: " << address.Street << std::endl;
 std::cout << "Номер дома: " << address.number_house << std::endl;
 std::cout << "Номер квартиры: " << address.number_flat << std::endl;
 std::cout << "Индекс: " << address.index << std::endl; 
 return 0;
}
