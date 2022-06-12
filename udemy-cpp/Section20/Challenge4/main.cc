#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cctype>
#include <stack>
#include <queue>

using std::vector;
using std::string;
using std::stack;
using std::queue;

bool IsPalindrome(const string &str) {
  stack<char> s;
  queue<char> q;

  for (int i = 0; i < str.length() / 2; i++)
    q.push(str[i]);
  for (int i = (str.length() + 1) / 2; i < str.length(); i++)
    s.push(str[i]);

  while (!s.empty()) {
    if (s.top() != q.front()) return false;
    s.pop(), q.pop();
  }
  return true;
}

string ProcessString(const string &s) {
  string processed;
  for (const char c : s)
    if (std::isalpha(c)) processed += std::tolower(c);
  return processed;
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
    PrintRow(IsPalindrome(ProcessString(test_case)), test_case);

  std::cout << std::endl;
  return 0;
}