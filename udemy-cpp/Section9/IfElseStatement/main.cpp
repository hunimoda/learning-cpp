#include <iostream>

using namespace std;

int main() {
    int num {};
    const int kTargetValue {10};

    cout << "Enter a number and I'll compare it to " << kTargetValue << ": ";
    cin >> num;

    cout << "\n======================================" << endl;

    if (num >= kTargetValue) {
        int diff {num - kTargetValue};

        cout << num << " is greater than or equal to " << kTargetValue << endl;
        cout << num << " is " << diff << " greater than " << kTargetValue << endl;
    } else {
        int diff {kTargetValue - num};

        cout << num << " is less than " << kTargetValue << endl;
        cout << num << " is " << diff << " less than " << kTargetValue << endl;
    }

    return 0;
}