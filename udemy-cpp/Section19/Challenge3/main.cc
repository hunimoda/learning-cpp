#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using std::ifstream;
using std::string;
using std::vector;

vector<int> ComputeLps(const string &pattern) {
  vector<int> lps = { 0 };
  int i = 1, prev_lps = lps[0], p_length = pattern.length();
  while (i < p_length) {
    if (pattern[i] == pattern[prev_lps]) lps[i++] = ++prev_lps;
    else if (prev_lps) prev_lps = lps[prev_lps - 1];
    else lps[i++] = 0;
  }
  return lps;
}

void ToLowerCase(string &s) {
  for (char &c : s) c = std::tolower(c);
}

int SearchPattern(const string &s, string pattern) {
  ToLowerCase(pattern);
  vector<int> lps{ComputeLps(pattern)};
  int s_length = s.length(), p_length = pattern.length();
  int i = 0, j = 0, count = 0;
  while (i < s_length) {
    if (j >= p_length) {
      j = lps[j - 1];
      count++;
    }
    if (std::tolower(s[i]) == pattern[j]) i++, j++;
    else if (j == 0) i++;
    else j = lps[j - 1];
  }
  return count;
}

void DrawHorizontalLine(char c) {
  std::cout << std::setw(70) << std::setfill(c) << ""
            << std::setfill(' ') << std::endl;
}

int FindNumberOfWords(string &s) {
  s.push_back(' ');
  int count = 0, s_length = s.length();
  for (int i = 1; i < s_length; i++)
    if (std::isspace(s[i]) && !std::isspace(s[i - 1])) count++;
  s.pop_back();
  return count;
}

int main() {
  ifstream in_file("romeoandjuliet.txt");
  if (!in_file) {
    std::cerr << "File not found" << std::endl;
    return 1;
  }
  
  string entire_string, line;
  while (std::getline(in_file, line)) entire_string += line;

  std::cout << std::endl << std::endl;
  DrawHorizontalLine('=');
  std::cout << "Total number of words: " << FindNumberOfWords(entire_string)
            << std::endl;
  DrawHorizontalLine('=');
  std::cout << std::endl << std::endl;

  while (true) {
    DrawHorizontalLine('~');
    std::cout << "Search: ";
    string search;
    std::cin >> search;
    std::cout << search << " was found "
              << SearchPattern(entire_string, search) << " times" << std::endl;
    DrawHorizontalLine('~');
    std::cout << std::endl;
  }
  
  in_file.close();
  return 0;
}