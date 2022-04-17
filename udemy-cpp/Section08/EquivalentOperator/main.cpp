#include <iostream>

using namespace std;

int main() {
    bool equal_result {false};
    bool not_equal_result {false};

    //int num1 {}, num2 {};

    //cout << boolalpha;

    //cout << "Enter two integers: ";
    //cin >> num1 >> num2;

    //equal_result = (num1 == num2);
    //not_equal_result = (num1 != num2);

    //cout << "Equals: " << equal_result << endl;
    //cout << "Not equals: " << not_equal_result << endl;

    //char char1 {}, char2 {};

    //cout << "Enter two characters: ";
    //cin >> char1 >> char2;

    //equal_result = (char1 == char2);
    //not_equal_result = (char1 != char2);

    //cout << "Equals: " << equal_result << endl;
    //cout << "Not equals: " << not_equal_result << endl;

    //double double1 {}, double2 {};

    //cout << "Enter two doubles: ";
    //cin >> double1 >> double2;

    //equal_result = (double1 == double2);
    //not_equal_result = (double1 != double2);

    //cout << "Equals: " << equal_result << endl;
    //cout << "Not equals: " << not_equal_result << endl;

    double double1 {};
    int int1 {};

    cout << "Enter an integer and double: ";
    cin >> int1 >> double1;

    equal_result = (int1 == double1);
    not_equal_result = (int1 != double1);

    cout << "Equals: " << equal_result << endl;
    cout << "Not equals: " << not_equal_result << endl;

    return 0;
}