#include <iostream>

int main() {
  int uninitialized;  // contains garbage value
  int initialized1 = 7;
  int initialized2{10};

  std::cout << uninitialized << " is a random value" << std::endl;
  std::cout << initialized1 << " and "
            << initialized2 << "are initialized" << std::endl;

  return 0;
}