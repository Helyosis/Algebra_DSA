#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

#include "MyVector.h"

using namespace std;

int gen_rnd(int lo, int hi) {
    return lo + (rand() % (lo - hi + 1));
}

void Task01() {
    vector<int> v;
    v.reserve(100);

    cout << v.size() << endl;
    cout << v.capacity() << endl;

    for (unsigned int i = 0; i < v.capacity(); ++i) {
        v.insert(v.begin(), gen_rnd(1, 100));
        cout << v.at(0) << " ";;
    }
    cout << endl;
    v.resize(50);

    for (auto it = v.begin(); it < v.end(); ++it) {
        cout << *it << " ";;
    }
    cout << endl;

    v.reserve(30);

    for (auto it = v.rbegin(); it < v.rend(); ++it) {
        cout << *it << " ";;
    }
    cout << endl;


    vector<int> v2(v);

    v.clear();

    v2.erase(v2.begin(), v2.begin() + 10);

    cout << v2.front() << " " << v2.back() << endl;

    while (v2.size() > 0)
        v2.erase(v2.begin());
}

struct Point {
    int x;
    int y;
    int z;
};

void Task02() {
    vector<Point> v;

    ifstream input;
    input.open("points.txt");
    if (!input.good()) {
        cout << "4004" << endl;
        return;
    }

    string line;
    while (getline(input, line)) {
        stringstream ss;
        ss << line;
        Point p;
        ss >> p.x;
        ss >> p.y;
        ss >> p.z;

        v.push_back(p);
    }

    for (auto it = v.begin(); it < v.end(); ++it) {
        Point p = *it;
        cout << p.x << " " << p.y << " " << p.z << endl;
    }
}

void Task03() {
    MyVector v(10, "HELLOOOO");
    for (unsigned i = 0; i < v.size(); i++) {
        cout << v.at(i) << endl;
    }
}

void Task07() {
    ifstream input("ip_addresses.txt");

    string line;
    while (getline(input, line)) {
        stringstream ss;
        ss << line;

        int first;
        ss >> first;

        if (192 <= first && first < 224) {
            cout << line << endl;
        }
    }
}

void Task08() {
    array<int, 5> hist;
    string class_names[5] = {"A", "B", "C", "D", "E"};
    hist.fill(0);

    ifstream input("ip_addresses.txt");

    string line;
    while (getline(input, line)) {
        stringstream ss;
        ss << line;

        int first;
        ss >> first;

        if (first < 127)
            hist[0]++;
        else if (first == 127) // Localhost doesn't have a class
            continue;
        else if (first < 192)
            hist[1]++;
        else if (first < 224)
            hist[2]++;
        else if (first < 240)
            hist[3]++;
        else if (first < 255)
            hist[4]++;
    }

    for (int i = 0; i < 5; ++i) {
        cout << "Class " << class_names[i] << ": ";
        for (int j = 0; j < hist[i]; ++j) {
            cout << "#";
        }
        cout << " (" << hist[i] << ")" << endl;
    }
}

int main()
{
    Task07();
}