#include <iostream>

class Base {
 public:
  Base() : value_{0} {
    std::cout << "Base no-args constructor" << std::endl;
  }
  Base(int x) : value_{x} {
    std::cout << "Base (int) overloaded constructor" << std::endl;
  }
  ~Base() {
    std::cout << "Base destructor" << std::endl;
  }

 private:
  int value_;
};

class Derived : public Base {
 public:
  Derived() : Base{}, doubled_value_{0} {
    std::cout << "Derived no-args constructor" << std::endl;
  }
  Derived(int x) : Base{x}, doubled_value_{2 * x} {
    std::cout << "Derived (int) constructor" << std::endl;
  }
  ~Derived() {
    std::cout << "Derived destructor" << std::endl;
  }

 private:
  int doubled_value_;
};

int main() {
  // Derived d;
  Derived d{1000};
  return 0;
}