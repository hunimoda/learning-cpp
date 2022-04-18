#include <iostream>
#include <string>
#include <vector>

using namespace std;

void pass_by_ref1(int &num);
void pass_by_ref2(string &s);
void pass_by_ref3(vector<string> &v);
void print_vector(const vector<string> &v);

int main() {

    int num {10};
    int another_num {20};

    cout << "[before] num: " << num << endl;
    pass_by_ref1(num);
    cout << "[after]  num: " << num << endl;

    cout << "[before] another_num: " << another_num << endl;
    pass_by_ref1(another_num);
    cout << "[after]  another_num: " << another_num << endl;

    string name {"Frank"};

    cout << "\n[before] name: " << name << endl;
    pass_by_ref2(name);
    cout << "[after]  name: " << name << endl;

    vector<string> stooges {"Larry", "Moe", "Curly"};
    cout << "\n[before] stooges: ";
    print_vector(stooges);
    
    pass_by_ref3(stooges);
    cout << "[after]  stooges: ";
    print_vector(stooges);

    return 0;

}

void pass_by_ref1(int &num) {
    num = 1000;
}

void pass_by_ref2(string &s) {
    s = "Changed";
}

void pass_by_ref3(vector<string> &v) {
    v.clear();
}

void print_vector(const vector<string> &v) {
    for (auto s: v) {
        cout << s << " ";
    }
    cout << endl;
}