#include <iostream>

namespace A {
    void Func();
}

namespace A {
    void MyFunc();
}

namespace B {
    void YourFunc();
}

int main() {
    A::Func();
    return 0;
}

void A::Func() {
    std::cout << "A::Func()" << std::endl;
    MyFunc();
    B::YourFunc();
}

void A::MyFunc() {
    std::cout << "A::MyFunc()" << std::endl;
}

void B::YourFunc() {
    std::cout << "B::YourFunc()" << std::endl;
}