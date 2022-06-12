#include <iostream>
#include <stack>
#include <vector>
#include <list>

template <typename T>
void Display(std::stack<T> s) {
  std::cout << "[";
  while (!s.empty()) {
    std::cout << " " << s.top();
    s.pop();
  }
  std::cout << " ]" << std::endl;
}

int main() {
  std::stack<int> s;
  std::stack<int, std::vector<int>> s1;
  std::stack<int, std::list<int>> s2;
  std::stack<int, std::deque<int>> s3;

  for (int n : {1, 2, 3, 4, 5}) s.push(n);
  Display(s);

  s.push(100);
  Display(s);

  s.pop(), s.pop();
  Display(s);

  while (!s.empty()) s.pop();
  Display(s);

  std::cout << "Size: " << s.size() << std::endl;

  s.push(10);
  Display(s);

  s.top() = 100;
  Display(s);

  return 0;
}