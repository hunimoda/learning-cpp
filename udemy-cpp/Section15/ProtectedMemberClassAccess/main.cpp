#include <iostream>


class Base {

public:
    int a { 0 };
    void Display() {
        std::cout << a << ", " << b << ", " << c << std::endl;
    }

protected:
    int b { 0 };

private:
    int c { 0 };

};


class Derived: public Base {

    // Note friends of Derived have access to only what Derived has access to

    // a will be public
    // b will be protected
    // c will be inherited, but not accessible
public:
    void AccessBaseMembers() {
        a = 100; // OK. a is public
        b = 200; // OK. b is protected
        // c = 300; // NOT OK. c is not accessible from Derived
    }

};


int main() {

    std::cout << "=== Base member access from base objects ========" << std::endl;
    Base base;
    base.a = 100; // OK
    // base.b = 200; // Compiler error (private)
    // base.c = 300; // Compiler error (private)

    std::cout << "=== Base member access from derived objects =====" << std::endl;
    Derived d;
    d.a = 100; // OK
    // d.b = 200; // Compiler error
    // d.c = 300; // Compiler error

    return 0;

}