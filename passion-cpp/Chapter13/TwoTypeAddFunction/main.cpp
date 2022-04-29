#include <iostream>

using namespace std;

template <typename T>
T add(T num1, T num2) {
    
    cout << "T add(T num1, T num2)" << endl;
    return num1 + num2;

}


double add(double num1, double num2) {

    cout << "double add(double num1, double num2)" << endl;
    return num1 + num2;

}


int main() {

    cout << add(5, 7) << endl;
    cout << add(3.7, 7.5) << endl;
    cout << add<int>(5, 7) << endl;
    cout << add<double>(3.7, 7.5) << endl;

    cout << endl;
    return 0;
    
}