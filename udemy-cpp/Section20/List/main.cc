#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>  // std::advance
#include <string>

class Person {
 public:
  friend std::ostream &operator<<(std::ostream &os, const Person &p);
  Person() : Person("Unknown", 0) {}
  Person(std::string name, int age) : name_(name), age_(age) {}
  bool operator<(const Person &rhs) const { return this->age_ < rhs.age_; }
  bool operator==(const Person &rhs) const {
    return this->age_ == rhs.age_ && this->name_ == rhs.name_;
  }

 private:
  std::string name_;
  int age_;
};

std::ostream &operator<<(std::ostream &os, const Person &p) {
  os << p.name_ << ": " << p.age_;
  return os;
}

template <typename T>
void Display(const std::list<T> &l) {
  std::cout << "[";
  for (const auto &elem : l)
    std::cout << " " << elem;
  std::cout << " ]" << std::endl;
}

void Test1() {
  std::cout << "\nTest1 ----------------------------------------" << std::endl;
  std::list<int> l1{1, 2, 3, 4, 5};
  Display(l1);

  std::list<std::string> l2;
  l2.push_back("Back");
  l2.push_front("Front");
  Display(l2);

  std::list<int> l3;
  l3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Display(l3);

  std::list<int> l4(10, 100);
  Display(l4);
}

void Test2() {
  std::cout << "\nTest2 ----------------------------------------" << std::endl;
  std::list<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Display(l);
  std::cout << "Size: " << l.size() << std::endl;
  std::cout << "Front: " << l.front() << std::endl;
  std::cout << "Back: " << l.back() << std::endl;

  l.clear();
  Display(l);
  std::cout << "Size (after clear): " << l.size() << std::endl;
}

void Test3() {
  std::cout << "\nTest3 ----------------------------------------" << std::endl;
  std::list<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Display(l);

  l.resize(5);
  Display(l);

  l.resize(10);
  Display(l);

  std::list<Person> persons;
  persons.resize(5);
  Display(persons);
}

void Test4() {
  std::cout << "\nTest4 ----------------------------------------" << std::endl;
  std::list<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Display(l);
  auto it = std::find(l.begin(), l.end(), 5);
  if (it != l.end())
    l.insert(it, 100);
  Display(l);

  std::list<int> l2{1000, 2000, 3000};
  l.insert(it, l2.begin(), l2.end());
  Display(l);

  std::advance(it, -4);
  std::cout << *it << std::endl;

  l.erase(it);
  Display(l);
}

void Test5() {
  std::cout << "\nTest5 ----------------------------------------" << std::endl;
  std::list<Person> stooges{{"Larry", 18}, {"Moe", 25}, {"Curly", 17}};
  Display(stooges);

  std::string name;
  int age;
  std::cout << "\nEnter name: ";
  std::getline(std::cin, name);
  std::cout << "Enter age: ";
  std::cin >> age;

  stooges.emplace_back(name, age);
  Display(stooges);

  auto it = std::find(stooges.begin(), stooges.end(), Person{"Moe", 25});
  if (it != stooges.end())
    stooges.emplace(it, "Frank", 18);
  Display(stooges);
}

void Test6() {
  std::cout << "\nTest6 ----------------------------------------" << std::endl;
  std::list<Person> stooges{{"Larry", 18}, {"Moe", 25}, {"Curly", 17}};
  Display(stooges);
  stooges.sort();
  Display(stooges);
}

int main() {
  // Test1();
  // Test2();
  // Test3();
  // Test4();
  // Test5();
  Test6();
  return 0;
}