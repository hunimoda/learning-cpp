#include <iostream>
#include <cstddef>

int main() {
  char c = 'a';
  std::byte b{42};

  std::cout << c << std::endl;

  return 0;
}