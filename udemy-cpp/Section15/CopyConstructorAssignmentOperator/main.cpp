#include <iostream>

class Base {
 public:
  Base() : value_{0} {
    std::cout << "Base no-args constructor" << std::endl;
  }
  Base(int x) : value_{x} {
    std::cout << "Base (int) overloaded constructor" << std::endl;
  }
  Base(const Base &other) : value_{other.value_} {
    std::cout << "Base copy constructor" << std::endl;
  }
  Base &operator=(const Base &rhs) {
    std::cout << "Base operator=" << std::endl;
    if (this != &rhs) value_ = rhs.value_;
    return *this;
  }
  ~Base() { std::cout << "Base destructor" << std::endl; }

 private:
  int value_;
};

class Derived : public Base {
 public:
  Derived() : Base{} {
    std::cout << "Derived no-args constructor" << std::endl;
  }
  Derived(int x) : Base{x}, doubled_value_{2 * x} {
    std::cout << "Derived (int) overloaded constructor" << std::endl;
  }
  Derived(const Derived &other)
      : Base{other}, doubled_value_{other.doubled_value_} {
    std::cout << "Derived copy constructor" << std::endl;
  }
  Derived &operator=(const Derived &rhs) {
    if (this == &rhs) return *this;
    Base::operator=(rhs);
    doubled_value_ = rhs.doubled_value_;
    return *this;
  }
  ~Derived() { std::cout << "Derived destructor" << std::endl; }

 private:
  int doubled_value_;
};

int main() {
  // Base b{100};
  // Base b1{b};
  // b = b1;

  Derived d{100};
  Derived d1{d};
  d = d1;

  return 0;
}