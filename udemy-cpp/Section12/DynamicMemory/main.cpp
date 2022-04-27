#include <iostream>

using namespace std;

int main() {

    int *int_ptr {new int};

    cout << int_ptr << endl;
    delete int_ptr;

    double *double_ptr {nullptr};
    size_t size {0};

    cout << "How many temps? ";
    cin >> size;

    double_ptr = new double[size];
    cout << double_ptr << endl;

    delete [] double_ptr;

    while (true) {
        double_ptr = new double[100000];
    }

    cout << endl;
    return 0;

}