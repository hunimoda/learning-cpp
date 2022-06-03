#include <iostream>
#include <fstream>
#include <string>

int main() {
  std::ifstream in_file("poem.txt");
  if (!in_file) {
    std::cerr << "Could not open file" << std::endl;
    return 1;
  }
  
  // while (!in_file.eof()) {
  //   std::getline(in_file, line);
  //   std::cout << line << std::endl;
  // }
  std::string line;
  while (std::getline(in_file, line))
    std::cout << line << std::endl;
  in_file.close();

  return 0;
}