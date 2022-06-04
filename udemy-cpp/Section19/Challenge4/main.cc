#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

int main() {
  std::ifstream in_file("romeoandjuliet.txt");
  std::ofstream out_file("romeoandjuliet_numbered.txt");
  if (!in_file) {
    std::cerr << "Could not open file" << std::endl;
    return 1;
  }
  if (!out_file) {
    std::cerr << "Could not create file" << std::endl;
    return 2;
  }
  int line_number = 0;
  std::string line;
  while (std::getline(in_file, line)) {
    if (line.length() == 0) {
      out_file << std::endl;
      continue;
    }
    out_file << std::setw(8) << std::left << ++line_number;
    out_file << line << std::endl;
  }
  in_file.close();
  out_file.close();
  return 0;
}