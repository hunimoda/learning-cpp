#include <iostream>

class Base {
 public:
  virtual ~Base() {
    std::cout << "Base::~Base" << std::endl;
  }
  virtual void SayHello() const {
    std::cout << "Hello from Base class" << std::endl;
  }
};

class Derived : public Base {
 public:
  virtual ~Derived() {
    std::cout << "Derived::~Derived" << std::endl;
  }
  virtual void SayHello() const override {
    std::cout << "Hello from Derived class" << std::endl;
  }
};

int main() {
  Base *ptr = new Base();
  ptr->SayHello();
  delete ptr;

  ptr = new Derived();
  ptr->SayHello();
  delete ptr;

  return 0;
}