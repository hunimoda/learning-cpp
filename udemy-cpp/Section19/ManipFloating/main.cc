#include <iostream>
#include <iomanip>

int main() {
  double num_1 = 123456789.987654321;
  double num_2 = 1234.5678;
  double num_3 = 1234.0;

  std::cout << "\n-- Defaults -------------------------" << std::endl;
  std::cout << num_1 << std::endl;
  std::cout << num_2 << std::endl;
  std::cout << num_3 << std::endl;

  std::cout << std::setprecision(2);
  std::cout << "\n-- Precision 2 ----------------------" << std::endl;
  std::cout << num_1 << std::endl;
  std::cout << num_2 << std::endl;
  std::cout << num_3 << std::endl;

  std::cout << std::setprecision(5);
  std::cout << "\n-- Precision 5 ----------------------" << std::endl;
  std::cout << num_1 << std::endl;
  std::cout << num_2 << std::endl;
  std::cout << num_3 << std::endl;

  std::cout << std::setprecision(9);
  std::cout << "\n-- Precision 9 ----------------------" << std::endl;
  std::cout << num_1 << std::endl;
  std::cout << num_2 << std::endl;
  std::cout << num_3 << std::endl;

  std::cout << std::setprecision(3) << std::fixed;
  std::cout << "\n-- Precision 3 & fixed --------------" << std::endl;
  std::cout << num_1 << std::endl;
  std::cout << num_2 << std::endl;
  std::cout << num_3 << std::endl;

  std::cout << std::setprecision(3) << std::scientific;
  std::cout << "\n-- Precision 3 & scientific ---------" << std::endl;
  std::cout << num_1 << std::endl;
  std::cout << num_2 << std::endl;
  std::cout << num_3 << std::endl;

  std::cout << std::setprecision(3) << std::scientific << std::uppercase;
  std::cout << "\n-- Precision 3 & scientific & upper -" << std::endl;
  std::cout << num_1 << std::endl;
  std::cout << num_2 << std::endl;
  std::cout << num_3 << std::endl;

  std::cout << std::setprecision(3) << std::fixed << std::showpos;
  std::cout << "\n-- Precision 3 & fixed & showpos ----" << std::endl;
  std::cout << num_1 << std::endl;
  std::cout << num_2 << std::endl;
  std::cout << num_3 << std::endl;

  std::cout.unsetf(std::ios::scientific | std::ios::fixed);
  std::cout << std::resetiosflags(std::ios::showpos);

  std::cout << std::setprecision(10) << std::showpoint;
  std::cout << "\n-- Precision 10 & showpoint ---------" << std::endl;
  std::cout << num_1 << std::endl;
  std::cout << num_2 << std::endl;
  std::cout << num_3 << std::endl;

  std::cout.unsetf(std::ios::scientific | std::ios::fixed |
                   std::ios::showpos | std::ios::showpoint);
  std::cout << std::setprecision(6);

  std::cout << "\n-- Back to defaults -----------------" << std::endl;
  std::cout << num_1 << std::endl;
  std::cout << num_2 << std::endl;
  std::cout << num_3 << std::endl;

  return 0;
}