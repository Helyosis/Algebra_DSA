#include "Rectangle.h"

Rectangle::Rectangle(int w, int h) {
	width = w > 0 ? w : 0;
	height = h > 0 ? h : 0;
}

int Rectangle::area() {
	return width * height;
}

char* Rectangle::to_string() {
	int size = snprintf(NULL, 0, rect_format, width, height, area());
	char* res = (char*) malloc(size + 1);
	if (res != NULL)
		sprintf(res, rect_format, width, height, area());

	return res;
}