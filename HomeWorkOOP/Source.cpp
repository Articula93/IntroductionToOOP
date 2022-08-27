#include<iostream>
using namespace std;
//#define TWO_POINT
//#define ONE_POINT
#define FRACTION
#if defined TWO_POINT
class Point {

	double x;
	double y;
public:
	double get_x() const
	{
		return x;
	}
	double get_y() const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
};
double FindDistance(Point& A, Point& B);
void Print(double distance);


void main()
{
	setlocale(LC_ALL, "Russian");

	Point A;
	A.set_x(10);
	A.set_y(7);
	cout << "Координаты точки А: " << A.get_x() << "\t" << A.get_y() << endl;
	Point B;
	B.set_x(8);
	B.set_y(12);
	cout << "Координаты точки В: " << B.get_x() << "\t" << B.get_y() << endl;

	//Найдем расстояние между точками по теореме Пифагора, где sqrt - возведение в корень,
	// pow - это возведение в степень.

	double distance =  FindDistance(A, B);
	Print(distance);
}
double FindDistance(Point& A, Point& B)
{
  double distance = sqrt(pow(A.get_x() - B.get_x(), 2)) + (pow(A.get_y() - B.get_y(), 2));
  return distance;
}
void Print(double distance)
{
	cout << "Расстояние между точками = " << distance << endl;
}
#endif
#if defined ONE_POINT
class Point {

	double x;
	double y;
public:
	double get_x() const
	{
		return x;
	}
	double get_y() const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	double distance(Point& A)
	{
		// В качесте рещения взял формулу нахождения расстояния от точки до начала координат.
		double distance = sqrt(pow(A.get_x() + A.get_y(), 2));
		cout << "Расстояние до точки А = " << distance << endl;
		return distance;
	}
};
void main()
{
	setlocale(LC_ALL, "Russian");
	Point A;
	A.set_x(8);
	A.set_y(13);
	A.distance(A);
}
#endif
#if defined FRACTION
class Fraction
{
	int numerator;
	int denominator;
public:

	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int den)
	{
		if (den != 0)
			denominator = den;
		else
			cout << "Знаменатель не может быть равен нулю: " << endl;
	}
	int get_numerator()
	{
		return numerator;
	}
	int get_denominator()
	{
		return denominator;
	}
	Fraction(int num = 0, int den = 1)
	{
		numerator = num;
		set_denominator(den);
	}
	Fraction(const Fraction& other)
	{
		//Fraction f1;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
	}
	Fraction Add(Fraction f1, Fraction f2)
	{
		Fraction f3;
		f3.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
		f3.denominator = f1.denominator * f2.denominator;
		return f3;
	}
	Fraction Sub(Fraction f1, Fraction f2)
	{
		Fraction f3;
		f3.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
		f3.denominator = f1.denominator * f2.denominator;
		return f3;
	}
	Fraction Mult(Fraction f1, Fraction f2)
	{
		Fraction f3;
		f3.numerator = f1.numerator * f2.numerator;
		f3.denominator = f2.denominator * f1.denominator;
		return f3;

	}
	Fraction Div(Fraction f1, Fraction f2)
	{
		Fraction f3;
		f3.numerator = f1.numerator * f2.denominator;
		f3.denominator = f1.denominator * f2.numerator;
		return f3;
	}
	Fraction Pow(Fraction f, int n)
	{
		Fraction f2(f.numerator, f.denominator);
		for (int i = 1; i < n; i++)
		{
			f2.numerator *= f.numerator;
			f2.denominator *= f.denominator;
		}
		return f2;
	}

	bool Equals(Fraction f1, Fraction f2)
	{
		f1.numerator *= f2.denominator;
		f1.denominator *= f2.denominator;
		f2.numerator *= f1.denominator;
		f2.denominator *= f1.denominator;
		return f1.numerator == f2.numerator;
	}
	bool NotEquals(Fraction f1, Fraction f2)
	{
		return!Equals(f1, f2);
	}
	bool Less(Fraction f1, Fraction f2)
	{
		f1.numerator *= f2.denominator;
		f2.numerator *= f1.denominator;
		return f1.numerator < f2.numerator;
	}
	bool More(Fraction f1, Fraction f2)
	{
		f1.numerator *= f2.denominator;
		f2.numerator *= f1.denominator;
		return f1.numerator > f2.numerator;
	}
	bool LessOr(Fraction f1, Fraction f2)
	{
		f1.numerator *= f2.denominator;
		f2.numerator *= f1.denominator;
		return f1.numerator <= f2.numerator;
	}
	bool MoreOr(Fraction f1, Fraction f2)
	{
		f1.numerator *= f2.denominator;
		f2.numerator *= f1.denominator;
		return f1.numerator >= f2.numerator;
	}
	Fraction Square(Fraction& f)
	{
		f.numerator = sqrt(f.numerator);
		f.denominator = sqrt(f.denominator);
		return f;
	}
	double Decimal(Fraction f)
	{
		return (double)f.numerator / f.denominator;
	}
	void NOD(Fraction& f)
	{
		int i;
		i = f.numerator;
		while (!(f.numerator % i == 0 && f.denominator % i == 0))
		{
			i--;
		}
		cout << "Наибольший общий делитель дроби " << i << endl;
		f.numerator /= i;
		f.denominator /= i;
	}
	void Con(Fraction& f)
	{
		double d = (double)f.numerator / f.denominator;
		cout << "Преобразованая обычная дробь в десятичную = " << d << endl;
	}
	void modf(Fraction& f)
	{
		int x;
		x = f.numerator / f.denominator;
		f.numerator = f.numerator - x * f.denominator;
		cout << "целая часть = " << x << endl;
	}
	void Print()
	{
		cout << numerator << "/" << denominator;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	Fraction f(1, 2), f1(4, 9);
	f.Print();
	cout << "\t";
	f1.Print();
	Fraction f2;
	f2 = f.Add(f, f1);
	cout << "\t";
	f2.Print();
	f2 = f.Sub(f, f1);
	cout << "\t";
	f2.Print();
	cout << "\t";
	f2 = f.Mult(f, f1);
	f2.Print();
	cout << "\t";
	f2 = f.Div(f, f1);
	cout << "\t";
	f2.Print();
	f2 = f.Pow(f, 2);
	cout << "\t";
	f2.Print();
	f2 = f.Square(f1);
	cout << "\t";
	f2.Print();
	f2 = f.Equals(f, f1);
	cout << "\t";
	f2.Print();
	cout << "\t";
	bool temp;
	temp = f.More(f1, f);
	cout << temp << endl;
	temp = f.Less(f1, f);
	cout << temp << "\t";
	temp = f.Equals(f1, f);
	cout << temp << "\t";
	temp = f.NotEquals(f1, f);
	cout << temp << "\t";
	double t = f.Decimal(f);
	cout << t;
	cout << endl;
	Fraction f(18,8);
	f.NOD(f);
	f.Print();
	f.Con(f);
	f.modf(f);
	f.Print();
	Fraction f(1, 2), f1(1, 2);
	f.Print();
	cout << "\t";
	f1.Print();
	bool temp;
	temp = f.More(f1, f);
	cout << endl;
	cout << temp << endl;
	return 0;
}
#endif