#include <iostream>
#include <fstream>
#include <string>

int main() {
  std::string file_name;
  std::cout << "File to copy: ";
  std::cin >> file_name;

  std::ifstream in_file(file_name);
  if (!in_file) {
    std::cerr << "File doesn't exist: " << file_name << std::endl;
    return 1;
  }

  std::string file_content, line;
  while (std::getline(in_file, line))
    file_content += line + "\n";
  in_file.close();

  std::ofstream out_file("copy_" + file_name);
  if (!out_file) {
    std::cerr << "Could not create file: " << "copy_" + file_name << std::endl;
    return 1;
  }
  out_file << file_content;
  out_file.close();

  return 0;
}