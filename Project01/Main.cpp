#include <iostream>
#include <fstream>

#include "Person.h"			// Task 01
#include "Rectangle.h"		// Task 02
#include "Fraction.h"		// Task 03
#include "Transmission.h"	// Task 04

using namespace std;

int Task01() {
	Person p = Person("John", "Doe", 69);
	p.print();

	return 0;
}

int Task02() {
	Rectangle r1 = Rectangle(1, 2);
	Rectangle r2 = Rectangle(2, 4);
	Rectangle r3 = Rectangle(3, 6);
	Rectangle r4 = Rectangle(4, 8);
	Rectangle r5 = Rectangle(5, 10);

	ofstream f;
	f.open("out.txt");
	f << r1.to_string() << endl;
	f << r2.to_string() << endl;
	f << r3.to_string() << endl;
	f << r4.to_string() << endl;
	f << r5.to_string() << endl;

	f.close();

	return 0;
}

int Task03() {
	cout << "Enter the numerator: ";
	int num;
	cin >> num;

	cout << "Enter the denominator: ";
	int den;
	cin >> den;

	cout << "Enter the scalar: ";
	int scalar;
	cin >> scalar;

	Fraction orig = Fraction(num, den);
	Fraction mult = orig * scalar;

	printf("%s * %d = %s", orig.to_string(), scalar, mult.to_string());

	return 0;
}

int Task04() {
	Transmission t = Transmission();
	cout << "Out of gear: " << t.to_string() << endl;
	t.gear_up();

	cout << "First gear: " << t.to_string() << endl;
	t.gear_up();

	cout << "Second gear: " << t.to_string() << endl;
	t.gear_up();

	cout << "Third gear: " << t.to_string() << endl;
	t.gear_up();

	cout << "Fourth gear: " << t.to_string() << endl;
	t.gear_up();

	cout << "Fifth gear: " << t.to_string() << endl;
	t.gear_up();

	cout << "Fifth gear: " << t.to_string() << endl;
	t.gear_down();

	cout << "Fourth gear: " << t.to_string() << endl;

	return 0;
}

int main() {
	return Task04();
}