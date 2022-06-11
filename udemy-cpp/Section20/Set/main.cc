#include <iostream>
#include <algorithm>
#include <string>
#include <set>

class Person {
 public:
  friend std::ostream &operator<<(std::ostream &os, const Person &p);
  Person() : Person("Unknown", 0) {}
  Person(std::string name, int age) : name_(name), age_(age) {}
  bool operator<(const Person &rhs) const { return this->age_ < rhs.age_; }
  bool operator==(const Person &rhs) const {
    return this->name_ == rhs.name_ && this->age_ == rhs.age_;
  }

 private:
  std::string name_;
  int age_;
};

std::ostream &operator<<(std::ostream &os, const Person &p) {
  return os << p.name_ << ": " << p.age_;
}

template <typename T>
void Display(const std::set<T> &s) {
  if (s.empty()) {
    std::cout << "{ } - set is empty" << std::endl;
    return;
  }

  auto it = s.begin();
  std::cout << "{ " << *it++;
  while (it != s.end())
    std::cout << ", " << *it++;
  std::cout << " }" << std::endl;
}

void Test1() {
  std::cout << "\nTest1 ----------------------------------------" << std::endl;
  std::set<int> s{1, 4, 3, 5, 2};
  Display(s);

  s = {1, 2, 3, 1, 1, 2, 2, 3, 3, 4, 5};
  Display(s);

  s.insert(0);
  s.insert(10);
  Display(s);

  if (s.count(10)) {
    std::cout << "10 is in the set" << std::endl;
  } else {
    std::cout << "10 is NOT in the set" << std::endl;
  }

  // auto it = std::find(s.begin(), s.end(), 5);  // Don't use this
  auto it = s.find(5);  // This is better
  if (it != s.end())
    std::cout << "Found: " << *it << std::endl;

  s.clear();
  Display(s);
}

void Test2() {
  std::cout << "\nTest2 ----------------------------------------" << std::endl;
  std::set<Person> stooges{{"Curly", 3}, {"Larry", 1}, {"Moe", 2}};
  Display(stooges);

  stooges.emplace("James", 50);
  Display(stooges);

  stooges.emplace("Frank", 50);
  Display(stooges);

  auto it = stooges.find(Person{"Moe", 2});
  if (it != stooges.end())
    stooges.erase(it);
  Display(stooges);

  it = stooges.find(Person{"XXXX", 50});
  if (it != stooges.end())
    stooges.erase(it);
  Display(stooges);
}

void Test3() {
  std::cout << "\nTest3 ----------------------------------------" << std::endl;
  std::set<std::string> s{"A", "B", "C"};
  Display(s);

  auto result = s.insert("D");
  Display(s);

  std::cout << std::boolalpha;
  std::cout << "first: " << *(result.first) << std::endl;
  std::cout << "second: " << result.second << std::endl << std::endl;

  result = s.insert("A");
  Display(s);

  std::cout << "first: " << *(result.first) << std::endl;
  std::cout << "second: " << result.second << std::endl << std::endl;
}

int main() {
  // Test1();
  // Test2();
  Test3();
  return 0;
}
