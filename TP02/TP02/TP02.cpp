#include <iostream>

#include "MyMath.h"
#include "PrintFile.h"
#include "Primes.h"
#include <vector>
#include <algorithm>

using namespace std;

void Task01() {
    int a;
    int b;

    cout << "Enter a: ";
    cin >> a;

    cout << "Enter b: ";
    cin >> b;

    cout << a << " * " << b << " = " << multiply(a, b) << "\n";

    cout << "Enter a: ";
    cin >> a;

    cout << "Enter b: ";
    cin >> b;

    cout << a << " / " << b << " = " << divide(a, b) << "\n";

    cout << "Enter a: ";
    cin >> a;

    cout << "sqrt(" << a << ") = " << sqrt(a) << "\n";
}

void Task02() {
    string filename;
    cout <<"Enter filename: ";
    cin >> filename;

    cout << readFile(filename);
}

void Task03() {
    vector<int> arr;
    init_array(arr, 100);

    for_each(arr.rbegin(), arr.rend(), print_if_prime);
}

int main()
{
    Task03();
}
