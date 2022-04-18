#include <iostream>
#include <cmath>

using namespace std;

int main() {

    double number {};
    
    cout << "Enter a double: ";
    cin >> number;

    cout << "sqrt(" << number << "): " << sqrt(number) << endl;
    cout << "cbrt(" << number << "): " << cbrt(number) << endl;

    cout << "sin(" << number << "): " << sin(number) << endl;
    cout << "cos(" << number << "): " << cos(number) << endl;

    cout << "ceil(" << number << "): " << ceil(number) << endl;
    cout << "floor(" << number << "): " << floor(number) << endl;
    cout << "round(" << number << "): " << round(number) << endl;

    double power {};

    cout << "\nEnter a power to raise: " << number << " to ";
    cin >> power;
    
    cout << number << "^" << power << " = " << pow(number, power) << endl;

    return 0;

}