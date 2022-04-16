#include <iostream>

namespace A {
    void MyFunc();
}

namespace B {
    void MyFunc();
}

int main() {
    A::MyFunc();
    B::MyFunc();
    return 0;
}

void A::MyFunc() {
    std::cout << "A::MyFunc()" << std::endl;
}

void B::MyFunc() {
    std::cout << "B::MyFunc()" << std::endl;
}