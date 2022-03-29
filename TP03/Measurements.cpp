#include "Measurements.h"

using namespace std;
using namespace std::chrono;

int randint(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int* prepare_array(size_t n) {
    int* arr = (int*)malloc(n * sizeof(*arr));

    for (int i = 0; i < 1000; ++i) {
        arr[i] = randint(1, 1000);
    }

    return arr;
}

void mesure_sort(size_t n) {
    int* original = prepare_array(n);
    int* copy = (int*)malloc(n * sizeof(*copy));

    if (copy == nullptr)
        return;

    memcpy(copy, original, n * sizeof(*copy));

    auto begin = high_resolution_clock::now();
    quick_sort(original, n);
    auto end = high_resolution_clock::now();

    cout << "Comparing sorting array of size "
        << n
        << "." << endl;


    cout << " - Quicksort  took "
        << duration_cast<milliseconds>(end - begin).count()
        << " ms" << endl;

    begin = high_resolution_clock::now();
    bubble_sort(copy, n);
    end = high_resolution_clock::now();

    cout << " - Bubblesort took "
        << duration_cast<milliseconds>(end - begin).count()
        << " ms" << endl << endl;
}