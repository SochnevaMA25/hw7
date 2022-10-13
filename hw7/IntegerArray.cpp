#include "StdAfx.h"
#include<vector>
#include "IntegerArray.h"


//полная очистка массива
int IntegerArray::Divide(int a)
{
    if (a == 0)
    {
        throw std::range_error("The range is in error!");
    }
	
    return a;
}
void IntegerArray::erase()
{
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
}

int IntegerArray::check(int a)
{
    if (a >= 0 && a <= m_length)
    {
		return a;
        
    }else
	{
		throw std::bad_array_new_length();
	}
}
//доступ к элементам массива по индексу
int& IntegerArray::operator[](int index)
{
	try 
	{
		check(index);
		return m_data[index];
	} 
	catch(const std::bad_array_new_length &e) 
	{
		cerr << "Caught: " << e.what() << endl;
		cerr << "Type: " << typeid(e).name() << endl;
	}
}

//размер массива
int IntegerArray::getLength() const 
{ 
	return m_length; 
}

void IntegerArray::reallocate(int newLength)
{
	erase();

	if (newLength <= 0)
		return;

	m_data = new int[newLength];
	m_length = newLength;
}

// изменение размера массива без сохранения данных
void IntegerArray::resize(int newLength)
{
	if (newLength == m_length)
		return;

	if (newLength <= 0)
	{
		return;
	}
	int* data( new int[newLength] );	

	if (m_length > 0)
		{
			int elementsToCopy( (newLength > m_length) ? m_length : newLength );

	
			for (int index = 0; index < elementsToCopy; ++index)
				data[index] = m_data[index];
		}


    delete[] m_data;

    m_data = data;
    m_length = newLength;
}

//вставить элемент
void IntegerArray::insertBefore(int value, int index)
{
	try 
	{
		check(index);
		int* data(new int[m_length+1]);

		for (int before = 0; before < index; ++before)
		{
			data[before] = m_data[before];
		}

		data[index] = value;

		for (int after = index ; after < m_length; ++after)
		{
			data[after+1] = m_data[after];
		}

		delete[] m_data;
		m_data = data;
		++m_length;
	}

	catch(const std::bad_array_new_length &e) 
	{
		cerr << "Caught: " << e.what() << endl;
		cerr << "Type: " << typeid(e).name() << endl;
	}
	
}

void IntegerArray::copyS()
{
	int* data(new int[m_length+1]);

	for (int before = 0; before < m_length; ++before)
	{
		data[before] = m_data[before];
	}
	
	for (int before = 0; before < m_length; ++before)
	{
		std::cout << data[before] << std::endl;
	}
}

//удалить элемент
void IntegerArray::remove(int index)
{
	
	try 
	{
		check(index);
		if (m_length == 1)
		{
			erase();
			return;
		}

		int* data(new int[m_length+1]);

		for (int before = 0; before < index; ++before)
		{
			data[before] = m_data[before];
		}

		for (int after = index+1; after < m_length; ++after)
		{
			data[after-1] = m_data[after];
		}

		delete[] m_data;
		m_data = data;
		--m_length;
	} 
	catch(const std::bad_array_new_length &e) 
	{
		cerr << "Caught: " << e.what() << endl;
		cerr << "Type: " << typeid(e).name() << endl;
	}
	
}
