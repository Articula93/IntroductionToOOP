#include<iostream>
using namespace std;

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
	double distance(Point& A, Point& B)
	{
		double distance = sqrt(pow(A.get_x() - B.get_x(), 2)) + (pow(A.get_y() - B.get_y(), 2));
		cout <<"Расстояние до точки А = "  << distance << endl;
		return distance;
		
	}
};



void main()
{
	setlocale(LC_ALL, "Russian");
	Point A;
	A.set_x(10);
	A.set_y(7);
	Point B;
	B.set_x(8);
	B.set_y(12);
	A.distance(A,B);

	
	
}

