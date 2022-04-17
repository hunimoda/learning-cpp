#include <iostream>

using namespace std;

int main() {
    int counter {10};
    int result {0};

    //cout << counter << endl;

    //counter = counter + 1;
    //cout << counter << endl;

    //counter++;
    //cout << counter << endl;

    //++counter;
    //cout << counter << endl;

    cout << counter << endl;

    // result = ++counter;
    result = counter++;
    cout << counter << endl;
    cout << result << endl;
    cout << 0.0 + counter / 3 << endl;
    cout << static_cast<double>(3) / 2 << endl;

    return 0;
}