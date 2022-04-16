#include <iostream>

int main() {
  int val1, val2;
  int result = 0;
  std::cout << "Enter two numbers: ";
  std::cin >> val1 >> val2;

  int max = (val1 >= val2) ? val1 : val2;
  int min = (val1 < val2) ? val1 : val2;

  int sum = 0;
  for (int i = min + 1; i <= max - 1; i++) {
    sum += i;
  }

  std::cout << "Between sum: " << sum << std::endl;
  return 0;
}