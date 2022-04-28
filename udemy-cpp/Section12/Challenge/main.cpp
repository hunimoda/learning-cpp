#include <iostream>

using namespace std;

void print(const int [], int);
int *apply_all(const int [], int, const int [], int);

int main() {

    const size_t array1_size {5};
    const size_t array2_size {3};

    int array1[] {1, 2, 3, 4, 5};
    int array2[] {10, 20, 30};

    cout << "Array 1: ";
    print(array1, array1_size);

    cout << "Array 2: ";
    print(array2, array2_size);

    int *results = apply_all(array1, array1_size, array2, array2_size);
    constexpr size_t results_size {array1_size * array2_size};

    cout << "Result: ";
    print(results, results_size);

    cout << endl;
    return 0;

}

void print(const int array[], int ar_size) {
    for (int i = 0; i < ar_size; ++i) {
        cout << array[i] << ' ';
    }
    cout << endl;
}

int *apply_all(const int array1[], int ar1_size, const int array2[], int ar2_size) {
    int *new_array {nullptr};
    new_array = new int[ar1_size * ar2_size];

    for (int i = 0; i < ar2_size; ++i) {
        for (int j = 0; j < ar1_size; ++j) {
            new_array[ar1_size * i + j] = array1[j] * array2[i];
        }
    }

    return new_array;
}