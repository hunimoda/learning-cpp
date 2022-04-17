#include <iostream>

using namespace std;

int main() {
    int num1 {10};
    int num2 {20};

    num1 = 100;
    num2 = num1 * 2;

    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;

    num1 = num2 = 1000;

    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;

    return 0;
}