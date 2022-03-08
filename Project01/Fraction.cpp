#include <stdio.h>
#include <malloc.h>
#include "Fraction.h"

Fraction::Fraction(int num, int den) {
	numerator = num;
	
	if (den == 0) {
		denominator = 0;
	}
	else {
		denominator = den;
	}
}

Fraction Fraction::operator*(int scalar) {
	return Fraction(numerator * scalar, denominator);
}

char* Fraction::to_string() {
	if (denominator == 0)
		return "0";

	int size = snprintf(NULL, 0, fraction_format, numerator, denominator);
	char* res = (char*)malloc(100);
	if (res != NULL)
		sprintf(res, fraction_format, numerator, denominator);

	return res;
}