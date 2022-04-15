#include <iostream>

void MyFunc() {
    std::cout << "void MyFunc()" << std::endl;
}

void MyFunc(char c) {
    std::cout << "void MyFunc(char c)" << std::endl;
}

void MyFunc(int a, int b) {
    std::cout << "void MyFunc(int a, int b)" << std::endl;
}

int main() {
    MyFunc();
    MyFunc('A');
    MyFunc(12, 13);
    return 0;
}