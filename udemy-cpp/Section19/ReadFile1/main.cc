#include <iostream>
#include <fstream>

int main() {
  std::ifstream in_file("test.txt");
  if (!in_file) {
    std::cerr << "Cannot open file" << std::endl;
    return 1;
  }

  std::string word;
  int num;
  double total;

  in_file >> word >> num >> total;
  std::cout << word << std::endl;
  std::cout << num << std::endl;
  std::cout << total << std::endl;

  in_file.close();
  return 0;
}