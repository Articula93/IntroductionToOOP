#include<iostream>
using namespace std;

#define delimiter "\n--------------------------------------------------------------------/n"
class Point
{

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

	//                  Constructors:
	//Point()
	//{
	//	x = y = double(); // значение по умолчанию для double
	//	cout << "constructor:\t " << this <<  endl;
	//}
	//Point(double x)
	//{
	//	this->x = x;
	//	this->y = double();
	//	cout << "1argConstructor:\t" << this << endl;
	//}
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor\t" << this << endl;
	}

	~Point()
	{
		cout << "destructor:\t " << this << endl;
	}
	//              Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "copyAssignment:\t" << this << endl;
		return *this;
	}
	Point& operator++()
	{
		x++;
		y++;
		return *this;
	}
	Point operator++(int)
	{
		Point old = *this;
		x++;
		y++;
		return old;
	}
	//                      Method:
	double distance(const Point& other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(pow(x_distance, 2) + pow(y_distance, 2));
		return distance;
	}
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};
double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(pow(x_distance, 2) + pow(y_distance, 2));
	return distance;
}
Point operator+(const Point& left, const Point& right)
{
	Point res;
	res.set_x(left.get_x() + right.get_x());
	res.set_y(left.get_y() + right.get_y());
	return res;
}


//#define STRUCT_POITN
//#define DISTANCE
//#define CONSTRUCTORS_CHECK
void main()
{
	setlocale(LC_ALL, "Russian");
#if defined STRUCT_POITN
	Point A;
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif
#if defined DISTANCE
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки А до точки В: " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками А и В: " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками В и А: " << distance(B, A);
	cout << delimiter << endl;
#endif
#if defined CONSTRUCTORS_CHECK
	Point A;   //default constructor
	A.print(); 
	cout << double() << endl;

	Point B(2, 3);
	B.print();

	Point C = 5;
	C.print();

	Point D = B;   //CopyConstructor
	D.print();

	Point E;
	E = D;    //CopyAssignment (=)
	E.print();
#endif

	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;
	Point A, B, C;
	A = B = C = Point(2, 3);
	C = A + B;
	C.print();
	C++;
	C.print();
}