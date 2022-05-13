#include <iostream>


class Base {

private:
    int value_;

public:
    Base(): value_ { 0 } {
        std::cout << "Base no-args const." << std::endl;
    }
    Base(int x): value_ { x } {
        std::cout << "Base (int) overloaded const." << std::endl;
    }
    ~Base() { std::cout << "Base dest." << std::endl; }

};


class Derived: public Base {

private:
    int doubled_value_;

public:
    // Derived(): doubled_value_ { 0 } {
    //     std::cout << "Derived no-args const." << std::endl;
    // }
    // Derived(int x): doubled_value_ { 2 * x } {
    //     std::cout << "Derived (int) overloaded const." << std::endl;
    // }
    // ~Derived() { std::cout << "Derived dest." << std::endl; }
    
};


int main() {

    // Base b;
    // Base b { 100 };
    Derived d;

    return 0;

}