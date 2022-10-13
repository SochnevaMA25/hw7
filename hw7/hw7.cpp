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
	int mas = 0;		//количество элементов
	int n = 0;			//resize
	int c = 0;			//число
	int b = 0;			//номер элемента

	cout << "Введите количество элеменов в контейнере: " << endl;
	cin >> mas;
	
	IntegerArray array(mas);
	for (int i = 0; i<mas; ++i)
	array[i] = i+1;

	cout << "Изменение размера контейнера: " << endl;
	cin >> n;
	array.resize(n);
	n = 0;
	cout << "Какое число нужно вставить? Куда? Введите: " << endl;
	cin >> c;
	cin >> n;
	array.insertBefore(c, n);
	n = 0;
	cout << "Какой элемент нужно удалить? " << endl;
	cin >> n;
	array.remove(n);

	for (int i = 0 ; i<array.getLength(); ++i)
	{
		cout << array[i] << ' ' << endl;
	}

	n = 0;
	cout << "Какой элемент нужно вывести в консоль? " << endl;
	cin >> n;
	cout << " Element : " <<  array[n] << endl;	
	array.copyS(); 
	

	system("pause");
}
