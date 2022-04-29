#include <iostream>
#include <vector>

using namespace std;


template <class T>
T sum_vector(const vector<T> &v) {

    T sum {};

    for (T value: v) {
        sum += value;
    }

    return sum;

}


int main() {

    vector<int> int_vector {1, 2, 3, 4};
    vector<double> db_vector {1.1, 2.2, 3.3};

    cout << sum_vector<int>(int_vector) << endl;
    cout << sum_vector<double>(db_vector) << endl;

    cout << endl;
    return 0;

}