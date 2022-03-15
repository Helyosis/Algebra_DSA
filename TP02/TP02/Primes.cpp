#include "Primes.h"

bool prime(int& n) {
	if (n == 1)
		return false;

	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0)
			return false;
	}

	return true;
}

void init_array(vector<int> &arr, int length) {
	for (int i = 0; i < length; ++i) {
		arr.push_back(i + 1);
	}
}

void print_if_prime(int x) {
	if (prime(x))
		cout << x << endl;
}