#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <cctype>
#include <iomanip>

std::string &FormatLine(std::string &line) {
  for (char &c : line)
    c = std::isalpha(c) ? std::tolower(c) : ' ';
  return line;
}

void DisplayWordInfo(const std::string &word, int count,
                     const std::set<int> &line_numbers) {
  std::cout << std::setw(15) << std::left << word;
  std::cout << std::setw(2) << std::right << count;
  std::cout << std::setw(3) << "";
  
  std::string s;
  for (int line_number : line_numbers)
    s += std::to_string(line_number) + ", ";
  std::cout << std::setw(80) << std::left << s.substr(0, s.length() - 2)
            << std::endl;
}

int main() {
  std::ifstream in_file("words.txt");
  if (!in_file) {
    std::cerr << "Could not open file" << std::endl;
    return 1;
  }
  
  std::map<std::string, int> word_count;
  std::map<std::string, std::set<int>> line_numbers;
  std::string line;
  int line_number = 0;

  while (std::getline(in_file, line)) {
    line_number++;

    std::istringstream iss(FormatLine(line));
    std::string word;

    while (iss >> word) {
      word_count[word]++;
      line_numbers[word].insert(line_number);
    }
  }
  in_file.close();

  for (const auto &[word, count] : word_count)
    DisplayWordInfo(word, count, line_numbers[word]);

  return 0;
}