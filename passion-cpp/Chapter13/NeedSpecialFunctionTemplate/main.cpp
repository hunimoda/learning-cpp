#include <iostream>

using std::cout;
using std::endl;


template <class T>
T max(T val1, T val2) {

    return (val1 > val2) ? val1 : val2;

}


int main() {

    cout << max(11, 15) << endl;
    cout << max('T', 'Q') << endl;
    cout << max(3.5, 7.5) << endl;
    cout << max("simple", "best") << endl;

    cout << endl;
    return 0;

}