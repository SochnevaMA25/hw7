// hw7.cpp : main project file.

#include "stdafx.h"
#include <exception>
#include <iostream>
#include <stdexcept>
#include <typeinfo>
#include "IntegerArray.h"
#include<vector>

using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	int mas = 0;		//���������� ���������
	int n = 0;			//resize
	int c = 0;			//�����
	int b = 0;			//����� ��������

	cout << "������� ���������� �������� � ����������: " << endl;
	cin >> mas;
	
	IntegerArray array(mas);
	for (int i = 0; i<mas; ++i)
	array[i] = i+1;

	cout << "��������� ������� ����������: " << endl;
	cin >> n;
	array.resize(n);
	n = 0;
	cout << "����� ����� ����� ��������? ����? �������: " << endl;
	cin >> c;
	cin >> n;
	array.insertBefore(c, n);
	n = 0;
	cout << "����� ������� ����� �������? " << endl;
	cin >> n;
	array.remove(n);

	for (int i = 0 ; i<array.getLength(); ++i)
	{
		cout << array[i] << ' ' << endl;
	}

	n = 0;
	cout << "����� ������� ����� ������� � �������? " << endl;
	cin >> n;
	cout << " Element : " <<  array[n] << endl;	
	array.copyS(); 
	

	system("pause");
}
