#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    //int num {10};

    //cout << "Value of num is: " << num << endl;
    //cout << "sizeof num is: " << sizeof num << endl;
    //cout << "Address of num is: " << &num << endl;

    //int *p;

    //cout << "\nValue of p is: " << p << endl;
    //cout << "Address of p is: " << &p << endl;
    //cout << "sizeof p is: " << sizeof p << endl;

    //p = nullptr;
    //cout << "\nValue of p is: " << p << endl;

    //int *p1 {nullptr};
    //double *p2 {nullptr};
    //unsigned long long *p3 {nullptr};
    //vector<string> *p4 {nullptr};
    //string *p5 {nullptr};

    //cout << "\nsizeof p1 is: " << sizeof p1 << endl;
    //cout << "sizeof p2 is: " << sizeof p2 << endl;
    //cout << "sizeof p3 is: " << sizeof p3 << endl;
    //cout << "sizeof p4 is: " << sizeof p4 << endl;
    //cout << "sizeof p5 is: " << sizeof p5 << endl;

    int score {10};
    double high_temp {100.7};

    int *score_ptr {nullptr};
    score_ptr = &score;
    //score_ptr = &high_temp;

    cout << "\nValue of score is: " << score << endl;
    cout << "Address of score is: " << &score << endl;
    cout << "Value of score_ptr is: " << score_ptr << endl;

    return 0;

}