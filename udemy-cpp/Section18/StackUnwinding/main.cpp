#include <iostream>

void FuncA();
void FuncB();
void FuncC();

void FuncA() {
  std::cout << "Starting FuncA" << std::endl;
  FuncB();
  std::cout << "Ending FuncA" << std::endl;
}

void FuncB() {
  std::cout << "Starting FuncB" << std::endl;
  try {
    FuncC();
  } catch (int &e) {
    std::cerr << "Caught error in FuncB: " << e << std::endl;
  }
  std::cout << "Ending FuncB" << std::endl;
}

void FuncC() {
  std::cout << "Starting FuncC" << std::endl;
  throw 100;
  std::cout << "Ending FuncC" << std::endl;
}

int main() {
  std::cout << "Starting main" << std::endl;
  try {
    FuncA();
  } catch (int &e) {
    std::cerr << "Caught error in main: " << e << std::endl;
  }
  std::cout << "Ending main" << std::endl;
  return 0;
}