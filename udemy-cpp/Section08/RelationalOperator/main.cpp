#include <iostream>

using namespace std;

int main() {
    int num1 {}, num2 {};

    cout << boolalpha;
    cout << "Enter two integers: ";
    cin >> num1 >> num2;

    //cout << num1 << " > " << num2 << ": " << (num1 > num2) << endl;
    //cout << num1 << " >= " << num2 << ": " << (num1 >= num2) << endl;
    //cout << num1 << " < " << num2 << ": " << (num1 < num2) << endl;
    //cout << num1 << " <= " << num2 << ": " << (num1 <= num2) << endl;

    const int kLower {10};
    const int kUpper {20};

    cout << "\nEnter an integer greater than " << kLower << ": ";
    cin >> num1;
    cout << num1 << " > " << kLower 
        << " is " << (num1 > kLower) << endl;
    
    cout << "\nEnter an integer less than or equal to " << kUpper << ": ";
    cin >> num1;
    cout << num1 << " <= " << kUpper 
        << " is " << (num1 <= kUpper) << endl;

    return 0;
}