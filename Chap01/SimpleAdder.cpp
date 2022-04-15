#include <iostream>

int main() {
  double val1;
  std::cout << "1st number: ";
  std::cin >> val1;

  double val2;
  std::cout << "2nd number: ";
  std::cin >> val2;

  double result = val1 + val2;
  std::cout << "sum: " << result << std::endl;
  return 0;
}