#include <iostream>

class IllegalParameter {
 public:
  IllegalParameter() = default;
  ~IllegalParameter() = default;
};

class Simple {
 public:
  Simple(int a) {
    if (a < 0)
      throw IllegalParameter();
    parameter_ = a;
  }

  void Show() const {
    std::cout << "parameter_: " << parameter_ << std::endl;
  }

 private:
  int parameter_;
};

int main() {
  Simple simple_1(1);
  simple_1.Show();
  try {
    Simple simple_2(-1);
    simple_2.Show();
  } catch (const IllegalParameter &e) {
    std::cerr << "Illegal paremter was passed" << std::endl;
  }
  std::cout << "Bye" << std::endl;
  return 0;
}