#include <iostream>

using std::cout;
using std::endl;


template <class T>
void swap(T &var1, T &var2) {

    T temp = var1;
    var1 = var2;
    var2 = temp;

}


int main() {

    int int_num1 {3};
    int int_num2 {7};

    cout << int_num1 << ", " << int_num2 << endl;
    swap<int>(int_num1, int_num2);
    cout << int_num1 << ", " << int_num2 << endl;

    double db_num1 {10.2};
    double db_num2 {20.4};

    cout << "------------------------------" << endl;
    cout << db_num1 << ", " << db_num2 << endl;
    swap<double>(db_num1, db_num2);
    cout << db_num1 << ", " << db_num2 << endl;

    cout << endl;
    return 0;

}