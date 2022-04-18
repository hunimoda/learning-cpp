#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(char);
void print(int);
void print(double);
void print(string);
void print(string, string);
void print(vector<string>);

int main() {

    print(100);
    print('A');
    print(3.14);
    print(3.14F);
    print("C-style strings");

    string s {"C++ string"};
    print(s);

    print("C-style strings", s);

    vector<string> three_stooges {"Larry", "Moe", "Curly"};
    print(three_stooges);

    return 0;

}

void print(char c) {
    cout << "Printing char: " << c << endl;
}

void print(int num) {
    cout << "Printing int: " << num << endl;
}

void print(double num) {
    cout << "Printing double: " << num << endl;
}

void print(string s) {
    cout << "Printing string: " << s << endl;
}

void print(string s, string t) {
    cout << "Printing 2 strings: " << s << " and " << t << endl;
}

void print(vector<string> v) {
    cout << "Printing vector of strings:";
    for (auto s: v) {
        cout << " " << s;
    }
    cout << endl;
}