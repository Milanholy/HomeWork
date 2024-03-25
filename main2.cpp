struct bank_account
{
 int bank_id = 123456789;
 std::string first_name{"Андрей"};
 double bank_value = 5000;
};

bool bank_account_overlay(bank_account& bank_acc) {
 std::cout << "Введите номер лицевого счёта: " << bank_acc.bank_id<<std::endl;
 std::cout << "Введите имя владельца: " << bank_acc.first_name<<std::endl;
 std::cout << "Введите баланс: " << bank_acc.bank_value<<std::endl;
 return true;
}
void bank_account_change(bank_account& bank_acc) {
 std::cout << "Введите новый баланс: ";
 std::cin >> bank_acc.bank_value;
}

int main() {
 setlocale(LC_ALL, "Rus");
 bank_account bank_acc;
 bank_account_overlay(bank_acc);
 bank_account_change(bank_acc);
 std::cout << "Ваш счёт: " << bank_acc.bank_id << ", " << bank_acc.first_name << ", " << bank_acc.bank_value;
 return 0;
}
