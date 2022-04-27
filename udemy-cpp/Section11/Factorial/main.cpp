#include <iostream>

using namespace std;

unsigned long long factorial(unsigned long long);

int main() {

    cout << factorial(3) << endl;
    cout << factorial(8) << endl;
    cout << factorial(12) << endl;
    cout << factorial(20) << endl;

    return 0;

}

unsigned long long factorial(unsigned long long n) {
    if (n <= 1) return 1;

    return n * factorial(n - 1);
}