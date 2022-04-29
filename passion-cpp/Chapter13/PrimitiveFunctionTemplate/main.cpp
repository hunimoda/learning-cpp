#include <iostream>

using namespace std;

template <class T1, class T2>
void show_data(double num) {

    cout << (T1) num << ", " << (T2) num << endl;

}


int main() {

    show_data<char, int>(65);   // A, 65
    show_data<char, int>(67);   // C, 67
    show_data<char, double>(68.9);  // D, 68.9
    show_data<short, double>(69.2); // 69, 69.2
    show_data<short, double>(70.4); // 70, 70.4

    cout << endl;
    return 0;

}