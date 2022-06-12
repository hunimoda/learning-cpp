#include <iostream>
#include <queue>

template <typename T>
void Display(std::queue<T> q) {
  std::cout << "[";
  while (!q.empty()) {
    std::cout << " " << q.front();
    q.pop();
  }
  std::cout << " ]" << std::endl;
}

int main() {
  std::queue<int> q;
  for (int n : {1, 2, 3, 4, 5}) q.push(n);
  Display(q);

  std::cout << "front: " << q.front() << std::endl;  // 1
  std::cout << "back: " << q.back() << std::endl;  // 5

  q.push(100);
  Display(q);

  q.pop();
  q.pop();
  Display(q);

  while (!q.empty()) q.pop();
  Display(q);

  std::cout << "size: " << q.size() << std::endl;

  q.push(10);
  q.push(100);
  q.push(1000);
  Display(q);

  std::cout << "front: " << q.front() << std::endl;
  std::cout << "back: " << q.back() << std::endl;

  q.front() = 5;
  q.back() = 5000;
  Display(q);

  std::cout << "front: " << q.front() << std::endl;
  std::cout << "back: " << q.back() << std::endl;

  return 0;
}