#pragma once
#include <stdio.h>
#include <malloc.h>


class Rectangle
{
private:
	int width;
	int height;

	char* rect_format = "R(%d, %d) = %d";

public:
	Rectangle(int w, int h);
	int area();
	char* to_string();
};

