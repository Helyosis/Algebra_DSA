#include <iostream>

#include "MyMath.h"
#include "PrintFile.h"

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

int main()
{
    Task02();
}
