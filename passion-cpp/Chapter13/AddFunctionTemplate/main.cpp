#include <iostream>

using namespace std;

template <typename T>
T add(T num1, T num2) { return num1 + num2; }

int main() {

    cout << add<int>(15, 20) << endl;   // 35
    cout << add<double>(2.9, 3.7) << endl;  // 6.6
    cout << add<int>(3.2, 3.2) << endl; // 6
    cout << add<double>(3.14, 2.75) << endl;    // 5.89

    cout << endl;
    return 0;

}
