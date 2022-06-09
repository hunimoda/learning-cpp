#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <iomanip>
#include <cctype>

using std::deque;
using std::vector;
using std::string;

bool IsPalindrome(const string &s) {
  deque<char> d;
  for (const char c : s)
    if (std::isalpha(c)) d.push_back(std::tolower(c));
  
  while (d.size() > 1) {
    if (d.front() != d.back()) return false;
    d.pop_front(), d.pop_back();
  }
  return true;
}

void PrintRow(bool is_palindrome, const string &s) {
  std::cout << std::setw(8) << std::left << std::boolalpha << is_palindrome
            << std::right << s << std::endl;
}

int main() {
  vector<string> test_cases{
      "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
      "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA",
      "C++",
      "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!",
      "This is a palindrome", "palindrome"};
  
  std::cout << std::setw(8) << std::left << "Result"
            << std::right << "String" << std::endl;
  for (const auto &test_case : test_cases)
    PrintRow(IsPalindrome(test_case), test_case);
  std::cout << std::endl;
  return 0;
}