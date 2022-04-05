#include "MyVector.h"

MyVector::MyVector(int size, string default_value)
{
	if (size > 50) {
		size = 50;
	}

	m_size = size;
	m_arr.fill(default_value);
}

int MyVector::size() {
	return m_size;
}

string MyVector::at(int i) {
	return m_arr.at(i);
}