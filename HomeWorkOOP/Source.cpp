#include<iostream>
using namespace std;
//#define TWO_POINT
#define ONE_POINT
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