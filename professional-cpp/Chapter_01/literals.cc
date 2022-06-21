#include <iostream>

int main() {
  // decimal, octal, hexa-decimal, binary literals
  std::cout << "123: " << 123 << std::endl;
  std::cout << "0123: " << 0123 << std::endl;
  std::cout << "0xabcd: " << 0xabcd << std::endl;
  std::cout << "0b1010: " << 0b1010 << std::endl;

  // digit separators
  std::cout << 123'456'789 << std::endl;

  return 0;
}