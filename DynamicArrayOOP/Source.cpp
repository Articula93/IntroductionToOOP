#include<iostream>
using namespace std;

class DynArray
{
	int* arr;
	int size;
public:
	DynArray(int sizeP) : arr{ new int[sizeP] {} }, size{ sizeP }
	{
		cout << "DynArr constructed for " << size << "elements, for " << this << '\n';
	}
	DynArray():DynArray(5){}
	DynArray(const DynArray& object) : arr{ new int[object.size] }, size{ object.size }
	{
		/*� ������ ��������������� ����� ���� �������� ����� ���� ������������ ������
		���� �� �������, ��� � � ���������� ���������� ������ DynArray.
		��������� ������ �������� �� ������������� ����� ������ �� ����� ����������.*/
		for (int i{ 0 }; i < size; i++)
			arr[i] = object.arr[i];
		cout << "DynArr constructed for " << size << "elements, for " << this << '\n';
	}
	DynArray& operator = (const DynArray& object)
	{

	}
};


int main()
{
	setlocale(LC_ALL, "Russian");

	return 0;
}