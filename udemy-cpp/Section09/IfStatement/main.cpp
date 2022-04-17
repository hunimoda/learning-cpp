#include <iostream>

using namespace std;

int main() {
    int input_integer {};

    cout << "Enter an integer: ";
    cin >> input_integer;

    const int kMin {10};
    const int kMax {100};

    if (kMin <= input_integer) {
        cout << input_integer << " >= " << kMin << endl;
    }

    if (input_integer <= kMax) {
        cout << input_integer << " <= " << kMax << endl;
    }

    bool is_within_bound {false};

    is_within_bound = (kMin <= input_integer) 
        && (input_integer <= kMax);

    if (is_within_bound) {
        cout << kMin << " <= " << input_integer 
            << " <= " << kMax << endl;
    }

    if (input_integer == kMin || input_integer == kMax) {
        cout << input_integer << "is either " << kMin 
            << " or " << kMax << endl;
    }

    return 0;
}