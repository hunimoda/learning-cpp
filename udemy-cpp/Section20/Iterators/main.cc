#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

void Display(const std::vector<int> &v) {
  std::cout << "[ ";
  for (const auto &i : v)
    std::cout << i << " ";
  std::cout << "]" << std::endl;
}

void Test1() {
  std::cout << "\n----------------------------------------" << std::endl;
  std::vector<int> nums = { 1, 2, 3, 4, 5 };
  auto it = nums.begin();
  std::cout << *it << std::endl;

  it++;
  std::cout << *it << std::endl;

  it += 2;
  std::cout << *it << std::endl;

  it -= 2;
  std::cout << *it << std::endl;

  it = nums.end() - 1;
  std::cout << *it << std::endl;
}

void Test2() {
  std::cout << "\n----------------------------------------" << std::endl;
  std::vector<int> nums = { 1, 2, 3, 4, 5 };
  std::vector<int>::iterator it = nums.begin();
  while (it != nums.end())
    std::cout << *(it++) << std::endl;
  
  it = nums.begin();
  while (it != nums.end())
    *(it++) = 0;
  
  Display(nums);
}

void Test3() {
  std::cout << "\n----------------------------------------" << std::endl;
  std::vector<int> nums = { 1, 2, 3, 4, 5 };
  // std::vector<int>::const_iterator it = nums.begin();
  auto it = nums.cbegin();

  // while (it != nums.end())
  while (it != nums.cend())
    std::cout << *(it++) << std::endl;

  it = nums.cbegin();
  // it = nums.begin();
  // while (it != nums.end())
    // *(it++) = 0;
}

void Test4() {
  std::cout << "\n----------------------------------------" << std::endl;
  std::vector<int> v = { 1, 2, 3, 4, 5 };
  auto it1 = v.rbegin();
  while (it1 != v.rend())
    std::cout << *it1++ << std::endl;
  std::cout << std::endl;

  std::list<std::string> name = { "Larry", "Moe", "Curly" };
  auto it2 = name.crbegin();
  while (it2 != name.crend())
    std::cout << *it2++ << std::endl;

  std::map<std::string, std::string> favorites = {
    { "Frank", "C++" },
    { "Bill", "Java" },
    { "James", "Haskell" },
  };
  auto it3 = favorites.begin();
  while (it3 != favorites.end()) {
    std::cout << it3->first << ": " << it3->second << std::endl;
    it3++;
  }
}

void Test5() {
  std::cout << "\n----------------------------------------" << std::endl;
  std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  auto start = v.begin() + 2;
  auto end = v.end() - 3;

  for (auto it = start; it != end; it++)
    std::cout << *it << std::endl;
}

int main() {
  // Test1();
  // Test2();
  // Test3();
  // Test4();
  Test5();
  return 0;
}