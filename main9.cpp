#include <iostream>
#include <string>

class Figure
{
protected:
 std::string name_Of_Figure;
 bool have_Four_Sides = false; 
 int side_Length_A = 0;
 int side_Length_B = 0;
 int side_Length_C = 0;
 int side_Length_D = 0;
 int angle_A = 0;
 int angle_B = 0;
 int angle_C = 0;
 int angle_D = 0;

public:
 std::string getNameOfFigure() { return name_Of_Figure; }
 int getHaveFourSides() { return have_Four_Sides; }

 int getSideLengthA() { return side_Length_A; }
 int getSideLengthB() { return side_Length_B; }
 int getSideLengthC() { return side_Length_C; }
 int getSideLengthD() { return side_Length_D; }

 int getAngleA() { return angle_A; }
 int getAngleB() { return angle_B; }
 int getAngleC() { return angle_C; }
 int getAngleD() { return angle_D; }
};


class Triangle : public Figure
{
public:
 Triangle(int sideLengthA, int sideLengthB, int sideLengthC, int angleA, int angleB, int angleC)
 {
  name_Of_Figure = "Треугольник";
  side_Length_A = sideLengthA;
  side_Length_B = sideLengthB;
  side_Length_C = sideLengthC;
  angle_A = angleA;
  angle_B = angleB;
  angle_C = angleC;
 }
};

class rightTriangle : public Triangle
{
public:
 rightTriangle(int sideLengthA, int sideLengthB, int sideLengthC, int angleA, int angleB)
  : Triangle(sideLengthA, sideLengthB, sideLengthC, angleA, angleB, 90)
 {
  Triangle::name_Of_Figure = "Прямоугольный треугольник";
 };
};

class isoscelesTriangle : public Triangle
{
public:
 isoscelesTriangle(int sideLengthA, int sideLengthB, int angleA, int angleB)
  : Triangle(sideLengthA, sideLengthB, sideLengthA, angleA, angleB, angleA)
 {
  Triangle::name_Of_Figure = "Равнобедренный треугольник";
 };
};

class equilateralTriangle : public Triangle
{
public:
 equilateralTriangle(int sideLengthA)
  : Triangle(sideLengthA, sideLengthA, sideLengthA, 60, 60, 60)
 {
  Triangle::name_Of_Figure = "Равносторонний треугольник";
 };
};

class Quadrilateral : public Figure
{

public:
 Quadrilateral(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD)
 {
  name_Of_Figure = "Четырехугольник";

  have_Four_Sides = true;

  side_Length_A = sideLengthA;
  side_Length_B = sideLengthB;
  side_Length_C = sideLengthC;
  side_Length_D = sideLengthD;

  angle_A = angleA;
  angle_B = angleB;
  angle_C = angleC;
  angle_D = angleD;
 }
};

class Rectangle : public Quadrilateral
{
public: //int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD
 Rectangle(int sideLengthA, int sideLengthB)
  : Quadrilateral(sideLengthA, sideLengthB, sideLengthA, sideLengthB, 90, 90, 90, 90)
 {
  Quadrilateral::name_Of_Figure = "Прямоугольник";
 }
};

class Square : public Quadrilateral
{
public:
 Square(int sideLengthA)
  : Quadrilateral(sideLengthA, sideLengthA, sideLengthA, sideLengthA, 90, 90, 90, 90)
 {
  Quadrilateral::name_Of_Figure = "Квадрат";
 }
};

class Parallelogram : public Quadrilateral
{
public:
 Parallelogram(int sideLengthA, int sideLengthB, int angleA, int angleB)
  : Quadrilateral(sideLengthA, sideLengthB, sideLengthA, sideLengthB, angleA, angleB, angleA, angleB)
 {
  Quadrilateral::name_Of_Figure = "Параллелограмм";
 }
};

class Rhomb : public Quadrilateral
{
public:
 Rhomb(int sideLengthA, int angleA, int angleB)
  : Quadrilateral(sideLengthA, sideLengthA, sideLengthA, sideLengthA, angleA, angleB, angleA, angleB)
 {
  Quadrilateral::name_Of_Figure = "Ромб";
 }
};

void printFigure(Figure& figure)
{
 std::cout << std::endl;
 std::cout << figure.getNameOfFigure() << ":" << std::endl;

 std::cout << "Стороны:";
 std::cout << " a = " << figure.getSideLengthA() << ", b = " << figure.getSideLengthB() << ", с = " << figure.getSideLengthC();
 if (figure.getHaveFourSides())
 {
  std::cout << ", d = " << figure.getSideLengthD() << std::endl;
 }
 else { std::cout << std::endl; }

 std::cout << "Углы:";
 std::cout << " А = " << figure.getAngleA() << ", В = " << figure
