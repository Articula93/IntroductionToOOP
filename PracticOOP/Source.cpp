#include<iostream>
#include<string>
#include <windows.h>
#include <cmath>
#include<conio.h>
#include<stdio.h>
using namespace std;

//#define CARS
//#define MY_CLASS
//#define VEHICLE
//#define FRACTION
//#define IN_LINE
//#define ARRAY_CLASS
//#define POINTER_OBJECT
//#define POINTER_OBJECT_TWO
//#define	TRIANGLE

//#define OVERLOAD_OPERATORS
//#define ASSIGNMENT_OBJECT
//#define TASK_1
//#define TASK_2
//#define COUNTER
//#define ENGLCON
//#define FRACTION_2
//#define FRACTION_3
//#define DATA
#if defined CARS
class Cars
{
	int passengers;
	int fuelcap;
	int mpg;
public:
	int get_passengers() const
	{
		return passengers;
	}
	int get_fuelcap() const
	{
		return fuelcap;
	}
	int get_mpg() const
	{
		return mpg;
	}
	void set_passengers(int passengers)
	{
		this->passengers = passengers;
	}
	void set_fuelcap(int fuelcap)
	{
		this->fuelcap = fuelcap;
	}
	void set_mpg(int mpg)
	{
		this->mpg = mpg;
	}
	int range()
	{
		int range = get_fuelcap() * get_mpg();
		return range;
	}
	
};



void main()
{
	setlocale(LC_ALL, "Russian");
	Cars minivan;
	minivan.set_passengers(8);
	minivan.set_fuelcap(40);
	minivan.set_mpg(12);
	cout << "Машина с " << minivan.get_passengers() << " пассажирами может проехать " << minivan.range() << "km" << endl;
	Cars sportcar;
	sportcar.set_passengers(2);
	sportcar.set_fuelcap(25);
	sportcar.set_mpg(7);
	cout << "Машина с " << sportcar.get_passengers() << " пассажирами может проехать " << sportcar.range() << " km " << endl;

}
#endif
#if defined MY_CLASS

class MyClass
{
	int x;
public:
	int getX() const
	{
		return x;
	}
	void setX(int x)
	{
		this->x = x;
	}
	MyClass(int i)
	{
		x = i;
	}
	~MyClass()
	{
		cout << "Уничтожение объекта, у которого значение Х равно " << x << endl;
	}
};


void main()
{
	setlocale(LC_ALL, "Russian");
	MyClass t1(5);
	MyClass t2(19);
	cout << t1.getX() << "\t" << t2.getX() << endl;

	
}
#endif
#if defined VEHICLE

class Vehicle
{
	int passengers;
	int fuelcap;
	int mpg;
public:
	int get_passengers() const
	{
		return passengers;
	}
	int get_fuelcap() const
	{
		return fuelcap;
	}
	int get_mpg() const
	{
		return mpg;
	}
	void set_passengers(int passengers)
	{
		this->passengers = passengers;
	}
	void set_fuelcap(int fuelcap)
	{
		this->fuelcap = fuelcap;
	}
	void set_mpg(int mpg)
	{
		this->mpg = mpg;
	}
	Vehicle(int p, int f, int m)
	{
		passengers = p;
		fuelcap = f;
		mpg = m;
	}
	int range()
	{
		int range = get_fuelcap() * get_mpg();
		return range;
	}
};


void main()
{
	setlocale(LC_ALL, "Russian");
	Vehicle minivan(7, 16, 21);
	Vehicle sportcar(2, 14, 12);
	int range1, range2;
	range1 = minivan.range();
	range2 = sportcar.range();
	cout << "Фургон может везти " << minivan.get_passengers() << " пассажиров на расстоянии " << minivan.range() << endl;
	cout << "Фургон может везти " << sportcar.get_passengers() << " пассажиров на расстоянии " << sportcar.range();
}
#endif
#if defined FRACTION
class fraction {
	int numerator, denominator;
	void reduce();
	static int N;
public:
	fraction(int n = 0, int d = 1);
	fraction(fraction& a);
	~fraction();
	int getDenom();

	int getNumer();

	static int getN() { return N; }
	void setFraction(int n, int m);
	float real();
	void add(fraction& a);
	void obrat();
	fraction& operator =(const fraction& a);
	fraction operator ++();

	fraction operator ++(int);
	friend  fraction operator +(fraction b, fraction a);

	friend  fraction operator *(fraction b, fraction a);

	friend  ostream& operator <<(ostream& out, fraction a);
};
int fraction::N = 0;
fraction::fraction(int n, int d)
{
	denominator = d; numerator = n; reduce(); N++;
}
fraction::fraction(fraction& a)

{
	numerator = a.numerator; denominator = a.denominator; N++;
}
fraction::~fraction() { N--; }
int fraction::getNumer() { return numerator; }

int fraction::getDenom() { return denominator; }
void fraction::setFraction(int n, int m)

{
	if (m) { denominator = m; numerator = n; reduce(); }
}
float fraction::real() { return numerator / ((float)(denominator)); }
void fraction::add(fraction& a)

{
	numerator = numerator * a.denominator + a.numerator * denominator;

	denominator *= a.denominator;

	reduce();
}
void fraction::obrat() { setFraction(getDenom(), getNumer()); }
void fraction::reduce()

{
	if ((!numerator) || (!denominator))  return;

	int a = abs(numerator), b = abs(denominator);

	while (a != b)     if (a > b) a -= b;  else b -= a;

	numerator /= a;  denominator /= b;
}
fraction& fraction::operator =(const fraction& a)

{
	if (&a == this)return *this;

	numerator = a.numerator;

	denominator = a.denominator;

	return *this;
}
fraction fraction::operator ++()

{
	fraction e(1), temp = *this; add(e); return temp;
}

fraction fraction::operator ++(int)

{
	fraction e(1); add(e); return *this;
}
ostream& operator <<(ostream& out, fraction a)

{
	return out << a.numerator << "/" << a.denominator;
}
fraction operator +(fraction b, fraction a)

{
	fraction S(b.numerator * a.denominator + a.numerator * b.denominator,

		b.denominator * a.denominator); return S;
}



fraction operator *(fraction b, fraction a)

{
	fraction S(b.numerator * a.numerator,

		b.denominator * a.denominator); return S;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	fraction A(5), B(5, 3), * C, D(1, 3), E;
	C = &A;
	cout << "\nA=" << A << "\nB=" << B << "\n*C=" << (*C) << "\nD=" << D << "\nE=" << E << endl;

		


}
#endif
#if defined IN_LINE

class cl
{
	int i;
public:
	int get_i() const
	{
		return i;
	}
	void set_i(int i)
	{
		this->i = i;
	}
	inline int get_i()
	{
		return i;
	}
	void put_i(int j);
};
inline void cl::put_i(int j)
{
	i = j;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	cl s;
	s.put_i(10);
	cout << s.get_i();
}
#endif 
#if defined ARRAY_CLASS

class MyClass
{
	int x;
public:
	int get_x() const
	{
		return x;
	}
	void set_x(int i)
	{
		this->x = i;
	}
};

void main()
{
	MyClass obs[10];

	for (int i = 0; i < 10; i++)
	{
		obs[i].set_x(i);
	}
	for (int i = 0; i < 10; i++)
	{
		cout << "obs[" << i << "].get_x() : " << obs[i].get_x() << endl;
	}
}
#endif
#if defined POINTER_OBJECT

class Example
{
	int num;
public:
	int get_num() const
	{
		return num;
	}
	void set_num(int num)
	{
		this->num = num;
	}
	void print()
	{
		cout << num << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	
	Example ob, * p;
	ob.set_num(5);
	ob.print();
	p = &ob;
	p->set_num(50);
	p->print();
}
#endif
#if defined POINTER_OBJECT_TWO

class Example
{
	int num;
public:
	int get_num() const
	{
		return num;
	}
	void set_num(int num)
	{
		this->num = num;
	}
	void print()
	{
		cout << num << endl;
	}
};


void main()
{
	setlocale(LC_ALL, "Russian");
	Example ob[2], * p;
	ob[0].set_num(10);
	ob[1].set_num(20);
	p = &ob[0];
	p->print();
	p++;
	p->print();
	p--;
	p->print();
}

#endif
#if defined TRIANGLE

class Triangle
{
	double base;
	double height;
public:
	double get_base() const
	{
		return base;
	}
	double get_height() const
	{
		return height;
	}
	void set_base(double base)
	{
		this->base = base;
	}
	void set_height(double height)
	{
		this->height = height;
	}
	Triangle(double a, double b)
	{
		base = a;
		height = b;
	}
	double hupot()
	{
		double hupot = (pow(base, 2)) + (pow(height, 2));
		return hupot;
	}
	double area()
	{
		double area = 0.5 * (base + height);
		return area;
	}
 };

void main()
{
	setlocale(LC_ALL, "Russian");

	Triangle obs(7, 10);
	double hupot1, area1;
	hupot1 = obs.hupot();
	area1 = obs.area();
	cout << "длина гепотенузы прямоугольного треугольника = " << hupot1 << endl;
	cout << "Площадь прямоугольного треугольника = " << area1 << endl;
}
#endif
#if defined OVERLOAD_OPERATORS

class Simple
{
	int x;
	int y;
public:
	int get_x() const
	{
		return x;
	}
	int get_y() const
	{
		return y;
	}
	void set_x(int x)
	{
		this->x = x;
	}
	void set_y(int y)
	{
		this->y = y;
	}

	Simple()
	{
		x = y = 0;
	}
	Simple(int i)
	{
		x = y = i;
	}
	Simple(int i, int j)
	{
		x = i;
		y = j;
	}
};
void main()
{
	setlocale(LC_ALL, "Russian");
	Simple t(7);
	Simple t1(5);
	Simple t2(9, 10);
	cout << "t.x: " << t.get_x() << " t.y: " << t.get_y() << endl;
	cout << "t1.x: " << t1.get_x() << " t1.y: " << t1.get_y() << endl;
	cout << "t2.x: " << t2.get_x() << " t2.y: " << t2.get_y() << endl;
}
#endif
#if defined ASSIGNMENT_OBJECT

class Test
{
	int a;
	int b;
public:
	int get_a() const
	{
		return a;
	}
	int get_b() const
	{
		return b;
	}
	void set_a(int a)
	{
		this->a = a;
	}
	void set_b(int b)
	{
		this->b = b;
	}
	void setab(int i, int j)
	{
		a = i;
		b = j;
	}
	void print()
	{
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");

	Test obs1, obs2;
	obs1.setab(10, 20);
	obs2.setab(0, 0);
	cout << "obs1 перед присвоением: " << endl;
	obs1.print();
	cout << "obs2 перед присвоением: " << endl;
	obs2.print();
	obs2 = obs1;
	cout << "obs1 перед присвоением: " << endl;
	obs1.print();
	cout << "obs2 перед присвоением: " << endl;
	obs2.print();
	obs1.setab(1, -1);
	cout << "obs1 после изменения: " << endl;
	obs1.print();
	cout << "obs2 после изменения: " << endl;
	obs2.print();
}
#endif
#if defined TASK_1
class part
{
	int modelnumber;
	int partnumber;
	float cost;
public:
	int get_modelnumber() const
	{
		return modelnumber;
	}
	int get_partnumber() const
	{
		return partnumber;
	}
	float get_cost() const
	{
		return cost;
	}
	void set_modelnumber(int modelnumber)
	{
		this->modelnumber = modelnumber;
	}
	void set_partnumber(int partnumber)
	{
		this->partnumber = partnumber;
	}
	void set_cost(float cost)
	{
		this->cost = cost;
	}
	void setpart(int mn, int pn, float c)
	{
		modelnumber = mn;
		partnumber = pn;
		cost = c;
	}
	void print()
	{
		cout << "модель " << modelnumber << endl;
		cout << "деталь " << partnumber << endl;
		cout << "цена $ " << cost << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");

	part part1;
	part1.setpart(456, 76512, 45.5);
	part1.print();
}
#endif
#if defined TASK_2
class Distance
{
	int feet;
	float inches;
public:
	int get_feet() const
	{
		return feet;
	}
	float get_inches() const
	{
		return inches;
	}
	void set_feet(int feet)
	{
		this->feet = feet;
	}
	void set_inches(float inches)
	{
		this->inches = inches;
	}
	void setdist(int ft, int in)
	{
		feet = ft;
		inches = in;
	}
	void getdist()
	{
		cout << "Введите количество футов: "; cin >> feet;
		cout << "Введите количество дюймов: "; cin >> inches;
	}
	void print()
	{
		cout << feet << "\' - " << inches << '\"';
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	Distance dist1, dist2;
	dist1.setdist(65, 11.5);
	cout << "dist1 = "; dist1.print();
	cout << endl;
	dist2.getdist();
	cout << "dist2 = "; dist2.print();


}
#endif
#if defined COUNTER

class Counter
{
	unsigned int count;
public:
	int get_count() const
	{
		return count;
	}
	void set_count(int count)
	{
		this->count = count;
	}
	Counter()
	{
		count = 5;
	}
	void inc_count()
	{
		count++;
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	Counter c1, c2;
	cout << "cn1 = " << c1.get_count() << endl;
	cout << "cn2 = " << c2.get_count() << endl;
	c1.inc_count();
	c2.inc_count();
	c2.inc_count();
	cout << "cn1 = " << c1.get_count() << endl;
	cout << "cn2 = " << c2.get_count() << endl;
}
#endif
#if defined ENGLCON

class Distance
{
	int feet;
	double inches;
public:
	int get_feet() const
	{
		return feet;
	}
	double get_inches() const
	{
		return inches;
	}
	void set_feet(int feet)
	{
		this->feet = feet;
	}
	void set_inches(double inches)
	{
		this->inches = inches;
	}
	Distance() : feet(0), inches(0)
	{}
	Distance(int ft, int in) : feet(ft), inches(in)
	{}
	void getdist()
	{
		cout << "Введите футы: "; cin >> feet;
		cout << "введите дюймы: "; cin >> inches;
	}
	void print()
	{
		cout << feet << "\'- " << inches << '\"';
	}
	void add_dist(Distance, Distance);
};
void Distance::add_dist(Distance dd1, Distance dd2)
{
	inches = dd1.inches + dd2.inches;
	feet = 0;
	if (feet >= 12)
	{
		inches = inches - 12;
		feet++;
	}
	feet += dd1.feet + dd2.feet;
}
void main()
{
	setlocale(LC_ALL, "Russian");
	Distance dist1, dist3;
	Distance dist2(11, 6.25);
	dist1.getdist();
	dist3.add_dist(dist1, dist2);
	cout << " dist1 = "; dist1.print();
	cout << " dist2 = "; dist2.print();
	cout << " dist3 = "; dist3.print();
}
#endif
#if defined FRACTION_2
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
			cout << "знаменатель не может быть равен нулю. " << endl;
	}
	int get_numerator() const
	{
		return numerator;
	}
	int get_denominator() const
	{
		return denominator;
	}
	Fraction(int num= 0, int den = 1)
	{
		numerator = num;
		set_denominator(den);
	}
	Fraction(const Fraction &other)
	{
		//Fraction f1;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
	}
	Fraction Add(Fraction f1, Fraction f2)
	{
		Fraction f3;
		f3.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
		f3 = f1.denominator * f2.denominator;
		return f3;
	}
	Fraction Sub(Fraction f1, Fraction f2)
	{
		Fraction f3;
		f3.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
		f3 = f1.denominator * f2.denominator;
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
	bool Compare(Fraction f1, Fraction f2)
	{
		f1.numerator *= f2.denominator;
		f1.denominator *= f2.denominator;
		f2.numerator *= f1.denominator;
		f2.denominator *= f1.denominator;
	}
	bool Equals(Fraction f1, Fraction f2)
	{
		f1.numerator *= f2.denominator;
		f1.denominator *= f2.denominator;
		f2.numerator *= f1.denominator;
		f2.denominator *= f1.denominator;
		return f1.numerator == f2.numerator;
	}
	bool NoEquals(Fraction f1, Fraction f2)
	{
		return!Equals(f1, f2);
	}
	bool Less(Fraction f1, Fraction f2)
	{
		f1.numerator *= f2.denominator;
		f1.denominator *= f2.denominator;
		f2.numerator *= f1.denominator;
		f2.denominator *= f1.denominator;
		return f1.numerator < f2.numerator;
	}
	bool More(Fraction f1, Fraction f2)
	{
		f1.numerator *= f2.denominator;
		f1.denominator *= f2.denominator;
		f2.numerator *= f1.denominator;
		f2.denominator *= f1.denominator;
		return f1.numerator > f2.numerator;
	}
	Fraction Square(Fraction f)
	{
		f.numerator = sqrt(f.numerator);
		f.denominator = sqrt(f.denominator);
		return f;
	}
	double Decimal(Fraction f)
	{
		return f.numerator / f.denominator;
	}
	void Print()
	{
		cout << numerator << "/ " <<denominator;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	Fraction f(1.2), f1(3.4);
	f.Print();
	cout << endl;
	f1.Print();

	return 0;
}
#endif
#if defined FRACTION_3

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
	Fraction(const Fraction &other)
	{
		//Fraction f1;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
	}
	Fraction Add(Fraction f1, Fraction f2)
	{
		Fraction f3;
		f3.numerator= f1.numerator * f2.denominator + f2.numerator * f1.denominator;
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
	Fraction Square(Fraction &f)
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
		double d = (double)f.numerator/ f.denominator;
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

	/*Fraction f(1, 2), f1(4, 9);
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
	cout << endl;*/
	/*Fraction f(18,8);
	f.NOD(f);
	f.Print();
	f.Con(f);
	f.modf(f);
	f.Print();*/
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
#if defined DATA

//class Date
//{
//	int day;
//	int month;
//	int year;
//public:
//	void setDay(int value)
//	{
//		day = value;
//	}
//	int getDay() const
//	{
//		return day;
//	}
//};

//class Date
//{
//	const int baseYear;
//	int& currentYear;
//	int day;
//	int month;
//	int year;
//public:
//	Date(int currYear): baseYear{2000}, currentYear(currYear)
//		void setDay(int value)
//			{
//				day = value;
//			}
//			int getDay() const
//			{
//				return day;
//			}
//};
//
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//
//
//	Date aDate;
//	aDate.setDay(10);
//	cout << aDate.getDay() << endl;
//	getchar();
//	return 0;
//}

//class Account
//{
//	double sum;
//	const double rate;
//public:
//	Account(double Rate, double Sum):rate{Rate}
//	{
//		
//		this->sum = sum;
//	}
//	double getRate() const
//	{
//		return rate;
//	}
//	double getIncome() 
//	{
//		return sum * rate / 100;
//	}
//	double getIncome() const
//	{
//		return sum * rate / 100;
//	}
//	double setSum()
//	{
//		sum += getIncome();
//		return sum;
//	}
//	double getSum() const
//	{
//	
//		return sum;
//	}
//};
//
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	Account account(5, 2000);
//	const Account account1(8, 5000);
//	account.getRate();
//	account1.getRate();
//	account.getSum();
//	account1.getSum();
//	account.getIncome();
//	account1.getIncome();
//	account.setSum();
//	
//	_getch();
//}
//using namespace std;
//
//class Date
//{
//	int day;
//	int month;
//	int year;
//public:
//	Date(int day, int month, int year) :day{ day }, month{ month }, year{ year }
//	{}
//	Date(int year): Date(1,1,year)
//	{}
//	friend void displayDate(Date date);
//};
//void displayDate(Date date)
//{
//	std::cout << date.day << ". " << date.month << " . " << date.year << " . " << std::endl;
//}
//Date baseDate()
//{
//	return 2000;
//}
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	displayDate(2020);
//	Date date = 2010;
//	displayDate(date);
//	Date date2000 = baseDate();
//	displayDate(date2000);
//	getchar();
//	return 0;
//}

using namespace std;

class Array
{
	int size;
	int* array;
public:
	explicit Array(int size = 10);
	~Array();
	int getSize() const;
	int getValue(int index) const;
	void setValue(int index, int value);
	void display(int index) const;
};
Array::Array(int size)
{
	Array::size = size;
	array = new int[size];
}
Array:: ~Array()
{
	delete[] array;
}
int Array::getSize() const
{
	return size;
}
int Array::getValue(int index) const
{
	return array[index];
}
void Array::setValue(int index, int value)
{
	array[index] = value;
}
void Array::display(int index) const
{
	cout << array[index];
}
void display(const Array& array)
{
	for (int i = 0; i < array.getSize(); i++)
		array.display(i);
	cout << endl;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int size = 4;
	Array array(size);
	for (int i = 0; i < size; i++)
		array.setValue(i, size - 1);
		display(array);
		cout << "!!! " << endl;
		display(3);
		_getch();
		return 0;
}
#endif



