#include <iostream>
#include <string>

class Figure
{
protected:
	std::string name_Of_Figure = "Фигура";
	bool check_Figure = false;
	int quantity_Of_Sides = 0;
	int side_Length_A = 0;
	int side_Length_B = 0;
	int side_Length_C = 0;
	int side_Length_D = 0;
	int angle_A = 0;
	int angle_B = 0;
	int angle_C = 0;
	int angle_D = 0;

	virtual bool metodCheckFigure() 
	{
		if (quantity_Of_Sides == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

public:
	//Геттеры
	std::string getNameOfFigure() { return name_Of_Figure; }

	int getSideLengthA() { return side_Length_A; }
	int getSideLengthB() { return side_Length_B; }
	int getSideLengthC() { return side_Length_C; }
	int getSideLengthD() { return side_Length_D; }

	int getAngleA() { return angle_A; }
	int getAngleB() { return angle_B; }
	int getAngleC() { return angle_C; }
	int getAngleD() { return angle_D; }

	virtual void printFigure() 
	{
		std::cout << std::endl;
		std::cout << name_Of_Figure << ":" << std::endl;
		if (metodCheckFigure())
		{
			std::cout << "Правильная" << std::endl;
		}
		else { std::cout << "Неправильная" << std::endl; }

		std::cout << "Количество сторон: " << quantity_Of_Sides << std::endl;
	}
};

class Triangle : public Figure
{
protected:
	bool metodCheckFigure() override 
	{
		if ((angle_A + angle_B + angle_C) == 180)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

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
		quantity_Of_Sides = 3;
		check_Figure = metodCheckFigure();
	}

	void printFigure() override 
	{
		Figure::printFigure();

		std::cout << "Стороны:";
		std::cout << " a = " << getSideLengthA() << ", b = " << getSideLengthB() << ", с = " << getSideLengthC();
		std::cout << std::endl;

		std::cout << "Углы:";
		std::cout << " А = " << getAngleA() << ", В = " << getAngleB() << ", С = " << getAngleC();
		std::cout << std::endl;
	}

};

class rightTriangle : public Triangle
{
protected:
	bool metodCheckFigure() override
	{
		if (Triangle::metodCheckFigure() && (angle_C == 90))
		{
			return true;
		}
		else
		{
			return false;
		};
	};

public:
	rightTriangle(int sideLengthA, int sideLengthB, int sideLengthC, int angleA, int angleB, int angleC)
		: Triangle(sideLengthA, sideLengthB, sideLengthC, angleA, angleB, angleC)
	{
		Triangle::name_Of_Figure = "Прямоугольный треугольник";
	};
};

class isoscelesTriangle : public Triangle
{
protected:
	bool metodCheckFigure() override
	{
		if (Triangle::metodCheckFigure() && (side_Length_A == side_Length_C && angle_A == angle_C))
		{
			return true;
		}
		else
		{
			return false;
		};
	};

public:
	isoscelesTriangle(int sideLengthA, int sideLengthB, int sideLengthC, int angleA, int angleB, int angleC)
		: Triangle(sideLengthA, sideLengthB, sideLengthC, angleA, angleB, angleC)
	{
		Triangle::name_Of_Figure = "Равнобедренный треугольник";
	};
};

class equilateralTriangle : public Triangle
{
private:
	bool CheckEquilateralTriangle()
	{
		if ((side_Length_A == side_Length_B && side_Length_B == side_Length_C) && ((angle_A == 60) && (angle_A = 60) && (angle_C = 60)))
		{
			return true;
		}
		else
		{
			return false;
		};
	}

public:
	equilateralTriangle(int sideLengthA, int sideLengthB, int sideLengthC, int angleA, int angleB, int angleC)
		: Triangle(sideLengthA, sideLengthB, sideLengthC, angleA, angleB, angleC)
	{
		Triangle::name_Of_Figure = "Равносторонний треугольник";
	};
protected:
	bool metodCheckFigure() override
	{
		if (Triangle::metodCheckFigure() && (CheckEquilateralTriangle()))
		{
			return true;
		}
		else
		{
			return false;
		};
	};



};

class Quadrilateral : public Figure
{
protected:
	virtual bool metodCheckFigure()
	{
		if ((angle_A + angle_B + angle_C + angle_D) == 360)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

	bool metodCheckSideLengthACiBD()
	{
		if (side_Length_A == side_Length_C && side_Length_B == side_Length_D)
		{
			return true;
		}
		else
		{
			return false;
		}
	};
	bool metodCheckSideLengthACBD()
	{
		if (side_Length_A == side_Length_B && side_Length_B == side_Length_C && side_Length_C == side_Length_D)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

	bool metodCheckAngleabcd90()
	{
		if (angle_A == 90 && angle_B == 90 && angle_C == 90 && angle_D == 90)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

	bool metodCheckAngleACiBD()
	{
		if (angle_A == angle_C && angle_B == angle_D)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

public:
	Quadrilateral(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD)
	{
		name_Of_Figure = "Четырехугольник";

		quantity_Of_Sides = 4;
		side_Length_A = sideLengthA;
		side_Length_B = sideLengthB;
		side_Length_C = sideLengthC;
		side_Length_D = sideLengthD;

		angle_A = angleA;
		angle_B = angleB;
		angle_C = angleC;
		angle_D = angleD;
	}

	void printFigure() override
	{
		Figure::printFigure();

		std::cout << "Стороны:";
		std::cout << " a = " << getSideLengthA() << ", b = " << getSideLengthB() << ", с = " << getSideLengthC();
		std::cout << ", d = " << getSideLengthD() << std::endl;

		std::cout << "Углы:";
		std::cout << " А = " << getAngleA() << ", В = " << getAngleB() << ", С = " << getAngleC();
		std::cout << ", D = " << getAngleD() << std::endl;
	}

};

class Rectangle : public Quadrilateral
{
protected:
	bool metodCheckFigure() override
	{
		if (Quadrilateral::metodCheckFigure() && Quadrilateral::metodCheckSideLengthACiBD() && Quadrilateral::metodCheckAngleabcd90())
		{
			return true;
		}
		else
		{
			return false;
		}
	};

public:
	Rectangle(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD)
		: Quadrilateral(sideLengthA, sideLengthB, sideLengthC, sideLengthD, angleA, angleB, angleC, angleD)
	{
		Quadrilateral::name_Of_Figure = "Прямоугольник";
	}
};

class Square : public Quadrilateral
{
protected:
	bool metodCheckFigure() override
	{
		if (Quadrilateral::metodCheckFigure() && Quadrilateral::metodCheckSideLengthACBD() && Quadrilateral::metodCheckAngleabcd90())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
public:
	Square(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD)
		: Quadrilateral(sideLengthA, sideLengthB, sideLengthC, sideLengthD, angleA, angleB, angleC, angleD)
	{
		Quadrilateral::name_Of_Figure = "Квадрат";
	}
};

class Parallelogram : public Quadrilateral
{
protected:
	bool metodCheckFigure() override
	{
		if (Quadrilateral::metodCheckFigure() && Quadrilateral::metodCheckSideLengthACiBD() && Quadrilateral::metodCheckAngleACiBD())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

public:
	Parallelogram(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD)
		: Quadrilateral(sideLengthA, sideLengthB, sideLengthC, sideLengthD, angleA, angleB, angleC, angleD)
	{
		Quadrilateral::name_Of_Figure = "Параллелограмм";
	}
};

class Rhomb : public Quadrilateral
{
protected:
	bool metodCheckFigure() override
	{
		if (Quadrilateral::metodCheckFigure() && Quadrilateral::metodCheckSideLengthACBD() && Quadrilateral::metodCheckAngleACiBD())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

public:
	Rhomb(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD)
		: Quadrilateral(sideLengthA, sideLengthB, sideLengthC, sideLengthD, angleA, angleB, angleC, angleD)
	{
		Quadrilateral::name_Of_Figure = "Ромб";
	}
};

int main()
{
	setlocale(LC_ALL, "Russian"); 
	Figure Figure1;
	Figure1.printFigure();
	Triangle Triangle1(10, 20, 30, 50, 60, 70);
	Triangle1.printFigure();
	rightTriangle rightTriangle1(10, 20, 30, 50, 60, 90);
	rightTriangle1.printFigure();
	rightTriangle rightTriangle2(10, 20, 30, 50, 40, 90);
	rightTriangle2.printFigure();
	isoscelesTriangle isoscelesTriangle1(10, 20, 10, 50, 60, 90);
	isoscelesTriangle1.printFigure();
	equilateralTriangle equilateralTriangle1(30, 30, 30, 60, 60, 60);
	equilateralTriangle1.printFigure();
	Quadrilateral Quadrilateral1(10, 20, 30, 40, 50, 60, 70, 80);
	Quadrilateral1.printFigure();
	Rectangle Rectangle1(10, 20, 10, 20, 90, 90, 90, 90);
	Rectangle1.printFigure();
	Square Square1(20, 20, 20, 20, 90, 90, 90, 90);
	Square1.printFigure();
	Parallelogram Parallelogram1(20, 30, 20, 30, 30, 40, 30, 40);
	Parallelogram1.printFigure();
	Rhomb Rhomb1(30, 30, 30, 30, 30, 40, 30, 40);
	Rhomb1.printFigure();
}
