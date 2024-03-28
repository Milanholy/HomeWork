#include <iostream>
#include <string>


class Counter
{
public:
    Counter(int counter) {
         this->counter = counter;
     };
    Counter() {};
    void set_count(int counter) { //Cеттер
        counter = counter;
    }
    int get_count() {
        return counter;       //Геттер
    }

    void incrim_count() {
        counter++;
    }
    void decrim_count() {
        counter--;
    }
    int show_count() {
        return counter;
    }
private:
    int counter;
};

int main()
{
    setlocale(0, "");
    int n;
    std::string swap;
    std::string yes{ "да" };
    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> swap;
    if (swap != yes) {
        n = 1;
    }
    else
    {
        std::cin >> n;
    }
    std::cout << "Введите начальные показания счетчика: ";
    std::cin >> n;
    Counter c(n);
    while (true)
    {
        char opt;
        std::cout << "Введите +, -, = или x для выхода: ";
        std::cin >> opt;

        switch (opt)
        {
        case '+':
            c.incrim_count();
            break;

        case '-':
            c.decrim_count();
            break;

        case '=':
            std::cout << "Показание счетчика " << c.show_count() << "\n";
            break;

        case 'x':
            return 0;

        default:
            std::cout << "Неправильный символ!\n";
        }
    }

    return 0;
}
