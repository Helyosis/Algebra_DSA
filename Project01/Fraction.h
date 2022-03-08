#pragma once
class Fraction
{
private:
	int numerator;
	int denominator;

	const char* fraction_format = "%d/%d";
public:
	Fraction(int num, int den);
	Fraction operator*(int scalar);
	char* to_string();
};

