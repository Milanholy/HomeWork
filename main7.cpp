#include <iostream>
#include <cstring>
#include <fstream>
#include <string>


class Adress 
{
private:
    std::string Name_City;
    std::string Name_Street;
    int Number_House = 0;
    int Number_Apartment = 0;
    std::string Full_Adress;

public:
    Adress(std::string NameCity, std::string NameStreet, int NumberHouse, int NumberApartment)
    {
        Name_City = NameCity;
        Name_Street = NameStreet;
        Number_House = NumberHouse;
        Number_Apartment = NumberApartment;
    }

    std::string createAdress2Out()
    {
        Full_Adress = Name_City + ", " + Name_Street + ", " + std::to_string(Number_House)
            + ", " + std::to_string(Number_Apartment);
        return Full_Adress;
    };
};

enum class codeCommit
{
    fileInOpenError, fileOutOpenError
};


int printArrayForClassObjects(std::string* arrayForClassObjects, const int quantityAdresses)
{
    std::ofstream fileOut("out.txt", std::ios_base::trunc);

    if (fileOut.is_open())
    {
        std::cout << "Файл out.txt успешно открыт." << std::endl;
    }
    else
    {
        std::cout << "Ошибка открытия файла" << std::endl;
        return static_cast<int>(codeCommit::fileOutOpenError);
    }

    fileOut << "Всего количество адресов: " << quantityAdresses << std::endl << std::endl;

    fileOut << "Адреса:" << std::endl;

    for (int i = 0; i < quantityAdresses - 1; i++)
    {
        fileOut << i + 1 << ". " << arrayForClassObjects[i] << std::endl;
    }
    fileOut.close();
};

void addressSort(std::string* arrayForClassObjects, const int quantityAdresses)
{
    bool swapped = false;
    do {
        swapped = false;
        std::string tmp;

        for (int i = quantityAdresses - 1; i > 0; --i)
        {
            if (arrayForClassObjects[i - 1] > arrayForClassObjects[i])
            {
                tmp = arrayForClassObjects[i];
                arrayForClassObjects[i] = arrayForClassObjects[i - 1];
                arrayForClassObjects[i - 1] = tmp;
                swapped = true;
            }
        }
    } while (swapped);
}

std::string* createTextArr(const int quantityAdresses)
{
    std::string* TextArr = new std::string[quantityAdresses]{};

    return TextArr;
}

void deleteTextArr(std::string* TextArr, const int quantityAdresses)
{
    delete[] TextArr;
    TextArr = nullptr;
}

int main()
{
    setlocale(LC_ALL, "Russian"); 
    std::ifstream fileIn("in.txt"); 
    if (!fileIn)
    {
        std::cout << "Ошибка открытия файла in.txt." << std::endl;
        return static_cast<int>(codeCommit::fileInOpenError);
    }
    else
    {
        std::cout << "Файл in.txt успешно открыт." << std::endl;
    }

    int quantityAdresses = 0;
    std::string NameCity = {};
    std::string NameStreet = {};
    int NumberHouse = 0;
    int NumberApartment = 0;

    fileIn >> quantityAdresses; 

    std::string* arrayForClassObjects = createTextArr(quantityAdresses); 

    for (int i = 0; i < quantityAdresses; i++) 
    {
        fileIn >> NameCity >> NameStreet >> NumberHouse >> NumberApartment;
        Adress adress(NameCity, NameStreet, NumberHouse, NumberApartment);
        arrayForClassObjects[i] = adress.createAdress2Out();

    };
    fileIn.close(); 

    addressSort(arrayForClassObjects, quantityAdresses); 
    printArrayForClassObjects(arrayForClassObjects, quantityAdresses); 
    deleteTextArr(arrayForClassObjects, quantityAdresses); 

    std::cout << "Результат работы программы смотри в файле out.txt" << std::endl;
}
