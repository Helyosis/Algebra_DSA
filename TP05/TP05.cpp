#include <list>
#include <forward_list>
#include <iostream>
#include <algorithm>

#include <chrono>
#include <sstream>

#include <fstream>

using namespace std;
using namespace chrono;

void print_element(int x) {
    cout << x << " ";
}

string generate_random_string(int length) {
    string charset = "abcdefghijklmnopqrstuvwxyz";
    stringstream ss;

    for (int i = 0; i < length; ++i) {
        ss << charset[rand() % 26];
    }

    string result;
    ss >> result;

    return result;
}

template<class T>
T convert(string s) {
    stringstream ss;
    ss << s;
    T result;
    ss >> result;
    return result;
}

void Task01() {
    list<int> l(10);

    for (auto it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    // All numbers are 0 because it is the default value of an int

    int i = 10;
    for (auto it = l.rbegin(); it != l.rend(); ++it) {
        *it = i--;
    }

    cout << l.front() << endl;
    cout << l.back() << endl;

    for (auto it = l.begin(); it != l.end(); ++it) {
        cout << *(it++) << " ";
    }
    cout << endl;
    // This algorithm is very dependent on the content of list, and we have to inrement it twice instead of indexing it

    forward_list<int> fl;
    for (auto it = l.begin(); it != l.end(); ++it) {
        ++it;
        fl.push_front(*it);
    }

    for_each(fl.begin(), fl.end(), print_element);
    cout << endl;
    // We can't print them backwards because a forward list cannot point to its previous element

    while (!fl.empty() ) {
        fl.erase_after(fl.before_begin());
    }
    // We cannot access fl.size(), it doesn't exist

    l.clear();
    cout << l.size() << endl;
}


void Task02() {
    int list_length = 100000;
    int string_length = 30;

    auto start = high_resolution_clock::now();
    list<string> l1;
    for (int i = 0; i < list_length; ++i) {
        l1.push_back(generate_random_string(string_length));
    }
    auto end = high_resolution_clock::now();

    milliseconds duration = duration_cast<milliseconds>(end - start);
    cout << "List: adding to the end. Took " << duration.count() << " ms." << endl;

    start = high_resolution_clock::now();
    list<string> l2;
    for (int i = 0; i < list_length; ++i) {
        l2.push_front(generate_random_string(string_length));
    }
    end = high_resolution_clock::now();

    duration = duration_cast<milliseconds>(end - start);
    cout << "List: adding to the start. Took " << duration.count() << " ms." << endl;

    start = high_resolution_clock::now();
    forward_list<string> l3;
    for (int i = 0; i < list_length; ++i) {
        l3.push_front(generate_random_string(string_length));
    }
    end = high_resolution_clock::now();

    duration = duration_cast<milliseconds>(end - start);
    cout << "Forward list: adding to the start. Took " << duration.count() << " ms." << endl;
}

void Task03() {
    ifstream in;
    in.open("LakeHuron.csv");

    int start_year = -1;
    list<float> levels;

    string line;
    getline(in, line); // We discard the first line because it doesn't contain any data
    while (getline(in, line)) {
        stringstream ss;
        ss << line;
        string tmp;
        getline(ss, tmp, ','); // Again, we discard the id
        getline(ss, tmp, ',');
        int time = convert<int>(tmp);
        if (start_year == -1)
            start_year = time;

        getline(ss, tmp);
        float level_value = convert<float>(tmp);

        levels.push_back(level_value);
    }

    cout << "What year ? ";
    int year;
    cin >> year;

    int nb = year - start_year;
    for (int i = 0; i <= nb; ++i) {
        levels.pop_front();
    }

    for (auto it = levels.rbegin(); it != levels.rend(); ++it) {
        cout << *it << endl;
    }
    cout << endl;
}

int main()
{
    Task03();
}