#include <iostream>

class Base {
 public:
  void SayHello() const {
    std::cout << "Hello - I'm a Base class object" << std::endl;
  }
};

class Derived : public Base {
 public:
  void SayHello() const {
    std::cout << "Hello - I'm a Derived class object" << std::endl;
  }
};

void Greetings(const Base &obj) {
  std::cout << "Greetings: ";
  obj.SayHello();
}

int main() {
  Base base;
  base.SayHello();

  Derived derived;
  derived.SayHello();

  Greetings(base);
  Greetings(derived);

  Base *base_ptr{&base};
  base_ptr->SayHello();
  base_ptr = &derived;
  base_ptr->SayHello();

  base_ptr = new Derived;
  base_ptr->SayHello();

  return 0;
}