#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

template <typename T>
void Display(const std::deque<T> &d) {
  std::cout << "[";
  for (const auto &elem : d)
    std::cout << " " << elem;
  std::cout << " ]" << std::endl;
}

void Test1() {
  std::cout << "\nTest1 ----------------------------------------" << std::endl;
  std::deque<int> d{1, 2, 3, 4, 5};
  Display(d);

  d = {2, 4, 5, 6};
  Display(d);

  std::deque<int> d1(10, 100);
  Display(d1);

  d[0] = 100;
  d.at(1) = 200;
  Display(d);
}

void Test2() {
  std::cout << "\nTest2 ----------------------------------------" << std::endl;
  std::deque<int> d{0, 0, 0};
  Display(d);

  d.push_back(10);
  d.push_back(20);
  Display(d);

  d.push_front(100);
  d.push_front(200);
  Display(d);

  std::cout << "front: " << d.front() << std::endl;
  std::cout << "back:  " << d.back() << std::endl;
  std::cout << "size:  " << d.size() << std::endl;

  d.pop_back();
  d.pop_front();
  Display(d);
}

void Test3() {
  std::cout << "\nTest3 ----------------------------------------" << std::endl;
  std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::deque<int> d;

  for (const auto &elem : v) {
    if (elem & 1) {
      d.push_front(elem);
    } else {
      d.push_back(elem);
    }
  }
  Display(d);
}

void Test4() {
  std::cout << "\nTest4 ----------------------------------------" << std::endl;
  std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::deque<int> d;

  for (const auto &elem : v)
    d.push_front(elem);
  Display(d);

  d.clear();

  for (const auto &elem : v)
    d.push_back(elem);
  Display(d);
}

void Test5() {
  std::cout << "\nTest5 ----------------------------------------" << std::endl;
  std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::deque<int> d;

  std::copy(v.begin(), v.end(), std::front_inserter(d));
  Display(d);

  d.clear();

  std::copy(v.begin(), v.end(), std::back_inserter(d));
  Display(d);
}

int main() {
  // Test1();
  // Test2();
  // Test3();
  // Test4();
  Test5();
  return 0;
}