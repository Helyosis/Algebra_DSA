#pragma once
#include <string>
#include <array>

using namespace std;

class MyVector
{
private:
	int m_size;
	array<string, 50> m_arr;

public:
	MyVector(int size, string default_value);
	int size();
	string at(int i);
};

