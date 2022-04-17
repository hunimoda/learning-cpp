#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers(3);

    for (int i = 0; i < numbers.size(); i++) {
        cout << "Enter number [" << i + 1 << "]: ";
        cin >> numbers.at(i);
    }
    cout << endl;

    cout << "============================" << endl;
    cout << "What you entered: ";

    int sum {0};
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers.at(i) << ' ';
        sum += numbers.at(i);
    }
    cout << endl;

    cout << "Sum: " << sum << endl;
    cout << "Avg: " << static_cast<double>(sum) / numbers.size() << endl;

    return 0;
}