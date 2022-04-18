#include <iostream>

using namespace std;

void local_example(int x);
void global_example();
void static_local_example();

int num1 {300};

int main() {

    int num1 {100};
    int num2 {500};

    cout << "Local num1 is: " << num1 << " in main" << endl;

    {
        cout << "Local num1 is: " << num1 << " in inner block" << endl;

        int num1 {200};

        cout << "Local num1 is: " << num1 << " in inner block" << endl;
        cout << "Inner block in main can see out - num2 is: " << num2 << endl;
    }

    cout << "Local num1 is: " << num1 << " in main" << endl;

    local_example(10);
    local_example(20);

    global_example();
    global_example();

    static_local_example();
    static_local_example();
    static_local_example();

    return 0;

}

void local_example(int x) {
    int num1 {1000};

    cout << "\nLocal num1 is: " << num1 << " in local_example - start" << endl;

    num1 = x;
    cout << "Local num1 is: " << num1 << " in local_example - end" << endl;
}

void global_example() {
    cout << "\nGlobal num1 is: " << num1 << " in global_example - start" << endl;

    num1 *= 2;
    cout << "Global num is: " << num1 << " in global_example - end" << endl;
}

void static_local_example() {
    static int num1 {5000};

    cout << "\nLocal static num1 is: " << num1 << " in static_local_example - start" << endl;

    num1 += 1000;
    cout <<  "Local static num1 is: " << num1 << " in static_local_example - end" << endl;
}