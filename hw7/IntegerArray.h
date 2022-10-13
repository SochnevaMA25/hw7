#pragma once
#include "stdafx.h"
#include <exception>
#include <iostream>
#include <stdexcept>
#include <typeinfo>
#include <new>
#include <climits>
#include<vector>

using namespace std;

class range_error : public runtime_error {
public:
    explicit range_error(const string& message);
    explicit range_error(const char *message);
};

class IntegerArray
{
	int m_length;								//������
	int* m_data;								//������	

public:
	IntegerArray(){};

    IntegerArray(int length):
        m_length(length)
    {
		try
	{
		Divide(length);
		m_data = new int[length];
	}
		catch (const exception& e)
	{
		cerr << "Caught: " << e.what() << endl;
		cerr << "Type: " << typeid(e).name() << endl;
	}

        
    }
	~IntegerArray()
	{
		delete[] m_data;
	}

int Divide(int a);

int check(int a);
//������ ������� �������
void erase();
//������ � ��������� ������� �� �������
int& operator[](int index);

//������ �������
int getLength() const;

void reallocate(int newLength);

// ��������� ������� ������� ��� ���������� ������
void resize(int newLength);

//�������� �������
void insertBefore(int value, int index);

void copyS();

//������� �������
void remove(int index);
};

