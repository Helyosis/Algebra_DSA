#include <iostream>
#include "MyMath.h"

using namespace std;

int multiply(int a, int b) {
	if (a == 0 || b == 0) return 0;
	if (a == 1)
		return b;
	if (b == 1)
		return a;

	float tmp = multiply(a, b / 2);
	return tmp + tmp + (b % 2 == 0 ? 0 : a);
}

int divide(int a, int b) {
	if (b == 0) {
		cout << "[-] Error cannot compute: " << a << "/" << b << ". Division by 0";
		return 0;
	}

	if (a < 0)
		return -1 * divide(-a, b);
	if (b < 0)
		return -1 * divide(a, -b);

	int res = 0;
	while (a >= b) {
		res++;
		a -= b;
	}

	return res;
}

int sqrt(int a) {
	int i = 0;
	while (i * i < a) {
		i++;
	}

	return i - 1;
}