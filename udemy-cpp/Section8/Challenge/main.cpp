#include <iostream>

using namespace std;

void ShowCentsConverted(int cents) {
    int dollars = cents / 100;
    cents %= 100;
    cout << "dollars    : " << dollars << endl;

    int quarters = cents / 25;
    cents %= 25;
    cout << "quarters   : " << quarters << endl;

    int dimes = cents / 10;
    cents %= 10;
    cout << "dimes      : " << dimes << endl;

    int nickels = cents / 5;
    cents %= 5;
    cout << "nickels    : " << nickels << endl;

    cout << "pennies    : " << cents << endl;
}

int main() {
    int cents {};

    cout << "Enter an amount in cents: ";
    cin >> cents;

    cout << "\nYou can provide this change as follows:" << endl;
    ShowCentsConverted(cents);

    return 0;
}