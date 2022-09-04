#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
class Fraction
{
	int numerator;
	int denominator;
public:
	void set_numerator(int numerator);
	void set_denominator(int den);
	int get_numerator() const;
	int get_denominator() const;
	Fraction(int num = 0, int den = 1);
	Fraction(const Fraction& other);
	Fraction Add(Fraction&, Fraction&);
	Fraction Sub(Fraction&, Fraction&);
	Fraction Mult(Fraction&, Fraction&);
	Fraction Div(Fraction&, Fraction&);
	Fraction Pow(Fraction&, int n);
	bool Equals(Fraction&, Fraction&);
	bool NotEquals(Fraction&, Fraction&);
	bool Less(Fraction&, Fraction&);
	bool More(Fraction&, Fraction&);
	bool LessOr(Fraction&, Fraction&);
	bool MoreOr(Fraction&, Fraction&);
	Fraction Square(Fraction&);
	double Decimal(Fraction&);
	void NOD(Fraction&);
	void Con(Fraction&);
	void modf(Fraction&);
	void Print() const;
};

void Fraction :: set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction :: set_denominator(int den)
{
	if (den != 0)
		denominator = den;
	else
		cout << "Знаменатель не может быть равен нулю: " << endl;
}
int Fraction :: get_numerator() const
{
	return numerator;
}
int Fraction :: get_denominator() const
{
	return denominator;
}
Fraction::Fraction(int num = 0, int den = 
	1)
{
	numerator = num;
	set_denominator(den);
}
Fraction:: Fraction(const Fraction& other)
{
	//Fraction f1;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
}
Fraction Fraction::Add(Fraction& f1, Fraction& f2)
{
	Fraction f3;
	f3.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
	f3.denominator = f1.denominator * f2.denominator;
	return f3;
}
Fraction Fraction :: Sub(Fraction& f1, Fraction& f2)
{
	Fraction f3;
	f3.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
	f3.denominator = f1.denominator * f2.denominator;
	return f3;
}
Fraction Fraction::Mult(Fraction& f1, Fraction& f2)
{
	Fraction f3;
	f3.numerator = f1.numerator * f2.numerator;
	f3.denominator = f2.denominator * f1.denominator;
	return f3;
}
Fraction Fraction::Div(Fraction& f1, Fraction& f2)
{
	Fraction f3;
	f3.numerator = f1.numerator * f2.denominator;
	f3.denominator = f1.denominator * f2.numerator;
	return f3;
}
Fraction Fraction :: Pow(Fraction& f, int n)
{
	Fraction f2(f.numerator, f.denominator);
	for (int i = 1; i < n; i++)
	{
		f2.numerator *= f.numerator;
		f2.denominator *= f.denominator;
	}
	return f2;
}
bool Fraction:: Equals(Fraction& f1, Fraction& f2)
{
	f1.numerator *= f2.denominator;
	f1.denominator *= f2.denominator;
	f2.numerator *= f1.denominator;
	f2.denominator *= f1.denominator;
	return f1.numerator == f2.numerator;
}
bool Fraction:: NotEquals(Fraction& f1, Fraction& f2)
{
	return!Equals(f1, f2);
}
bool Fraction :: Less(Fraction& f1, Fraction& f2)
{
	f1.numerator *= f2.denominator;
	f2.numerator *= f1.denominator;
	return f1.numerator < f2.numerator;
}
bool Fraction ::  More(Fraction& f1, Fraction& f2)
{
	f1.numerator *= f2.denominator;
	f2.numerator *= f1.denominator;
	return f1.numerator > f2.numerator;
}
bool Fraction :: LessOr(Fraction& f1, Fraction& f2)
{
	f1.numerator *= f2.denominator;
	f2.numerator *= f1.denominator;
	return f1.numerator <= f2.numerator;
}
bool Fraction :: MoreOr(Fraction& f1, Fraction& f2)
{
	f1.numerator *= f2.denominator;
	f2.numerator *= f1.denominator;
	return f1.numerator >= f2.numerator;
}
Fraction Fraction :: Square(Fraction& f)
{
	f.numerator = sqrt(f.numerator);
	f.denominator = sqrt(f.denominator);
	return f;
}
double Fraction::Decimal(Fraction& f)
{
	return (double)f.numerator / f.denominator;
}
void Fraction :: NOD(Fraction& f)
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
void Fraction :: Con(Fraction& f)
{
	double d = (double)f.numerator / f.denominator;
	cout << "Преобразованая обычная дробь в десятичную = " << d << endl;
}
void Fraction ::modf(Fraction& f)
{
	int x;
	x = f.numerator / f.denominator;
	f.numerator = f.numerator - x * f.denominator;
	cout << "целая часть = " << x << endl;
}
void Fraction :: Print() const
{
	cout << numerator << "/" << denominator;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	return 0;
}
