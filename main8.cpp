#include <iostream>
#include <string>


class Figure
{
protected:
 int number_Of_Sides = 0;
 std::string name_Of_Figure;

public:
 Figure() : Figure(0, "Фигура") {};
 Figure(int numberOfSides, std::string nameOfFigure)
 {
  number_Of_Sides = numberOfSides;
  name_Of_Figure = nameOfFigure;
 };

 int getNumberOfSides() const { return number_Of_Sides; } //Метод геттер числа сторон

 std::string getNameOfFigure() const { return name_Of_Figure; } //Метод геттер названия фигуры
};

class Triangle : public Figure
{
public:

 Triangle() : Figure(3, "Треугольник") {};

};

class Quadrilateral : public Figure
{
public:

 Quadrilateral() : Figure(4, "Четырехугольник") {};
};

void print(Figure& xFig)
{
 std::cout << xFig.getNameOfFigure() << ": " << xFig.getNumberOfSides() << std::endl;
}

int main()
{
 setlocale(LC_ALL, "Russian"); 
 std::cout << std::endl << "Количество сторон: " << std::endl;
 Figure Figure1;
 print(Figure1);
 Triangle Triangle1;
 print(Triangle1);
 Quadrilateral Quadrilateral1;
 print(Quadrilateral1);
};
