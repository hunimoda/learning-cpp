#include <iostream>
#include <fstream>
#include <iomanip>

int main() {
  std::ifstream in_file("test.txt");
  if (!in_file) {
    std::cerr << "Couldn't open file" << std::endl;
    return 1;
  }
  
  std::string word;
  int num;
  double total;

  // while (!in_file.eof()) {
  //   in_file >> word >> num >> total;
  //   std::cout << std::setw(8) << word << std::setw(5) << num
  //             << std::setw(9) << total << std::endl;
  // }
  while (in_file >> word >> num >> total) {
    std::cout << std::setw(8) << word << std::setw(5) << num
              << std::setw(9) << total << std::endl;
  }
  in_file.close();

  return 0;
}