#include <iostream>
#include <iomanip>

void DisplayRuler() {
  std::cout << "\n....:....|....:....|....:....|....:....|....:....|"
            << std::endl;
}

int main() {
  int num_1 = 1234;
  double num_2 = 1234.5678;
  std::string hello = "Hello";

  // Defaults
  std::cout << "\n-- Defaults------------------------------------" << std::endl;
  DisplayRuler();
  std::cout << num_1 << num_2 << hello << std::endl;

  // Defaults - one per line
  std::cout << "\n-- Defaults 'one per line' --------------------" << std::endl;
  DisplayRuler();
  std::cout << num_1 << std::endl;
  std::cout << num_2 << std::endl;
  std::cout << hello << std::endl;

  std::cout << "\n-- Width[10] for num_1 ------------------------" << std::endl;
  DisplayRuler();
  std::cout << std::setw(10) << num_1 << num_2 << hello << std::endl;

  std::cout << "\n-- Width[10] for num_1 & num_2 ----------------" << std::endl;
  DisplayRuler();
  std::cout << std::setw(10) << num_1
            << std::setw(10) << num_2 << hello << std::endl;

  std::cout << "\n-- Width[10] for all --------------------------" << std::endl;
  DisplayRuler();
  std::cout << std::setw(10) << num_1 << std::setw(10) << num_2
            << std::setw(10) << hello << std::endl;

  std::cout << std::left;
  std::cout << "\n-- Width[10] for all & left-justify -----------" << std::endl;
  DisplayRuler();
  std::cout << std::setw(10) << num_1 << std::setw(10) << num_2
            << std::setw(10) << hello << std::endl;

  std::cout << std::setfill('~') << std::left;
  std::cout << "\n-- Width[10] for all & left-justify & fill * --" << std::endl;
  DisplayRuler();
  std::cout << std::setw(10) << num_1 << std::setw(10) << num_2
            << std::setw(10) << hello << std::endl;

  std::cout << std::left;
  std::cout << "\n-- Width[10] for all & left-justify & fill ? --" << std::endl;
  DisplayRuler();
  std::cout << std::setw(10) << std::setfill('*') << num_1
            << std::setw(10) << std::setfill('#') << num_2
            << std::setw(10) << std::setfill('-') << hello << std::endl;

  return 0;
}