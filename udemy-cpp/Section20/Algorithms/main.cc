#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>
#include <iomanip>

class Person {
 public:
  Person() = default;
  Person(std::string name, int age) : name_(name), age_(age) {}

  bool operator<(const Person &rhs) const {
    return this->age_ < rhs.age_;
  }

  bool operator==(const Person &rhs) const {
    return this->name_ == rhs.name_ && this->age_ == rhs.age_;
  }

 private:
  std::string name_;
  int age_;
};

void DrawHorizontalLine() {
  std::cout << std::setw(50) << std::setfill('=') << ""
            << std::setfill(' ') << std::endl;
}

void FindTest() {
  DrawHorizontalLine();
  // std::vector<int> v{1, 2, 3, 4, 5};
  // auto loc = std::find(std::begin(v), std::end(v), 1);
  // if (loc != std::end(v)) {
  //   std::cout << "Found the number: " << *loc << std::endl;
  // } else {
  //   std::cout << "Couldn't find the number" << std::endl;
  // }
  std::list<Person> players{
      {"Larry", 18},
      {"Moe", 20},
      {"Curly", 21}};
  auto loc = std::find(players.begin(), players.end(), Person{"Moe", 21});
  if (loc != players.end()) {
    std::cout << "Found Moe" << std::endl;
  } else {
    std::cout << "Moe not found" << std::endl;
  }
}

void CountTest() {
  DrawHorizontalLine();
  std::vector<int> v{1, 2, 3, 4, 5, 1, 2, 1};
  int num = std::count(v.begin(), v.end(), 1);
  std::cout << num << " occurrences found" << std::endl;
}

void CountIfTest() {
  DrawHorizontalLine();
  std::vector<int> v{1, 2, 3, 4, 5, 1, 2, 1, 100};
  int num = std::count_if(v.begin(), v.end(), [](int x) { return !(x & 1); });
  std::cout << num << " even numbers found" << std::endl;
  num = std::count_if(v.begin(), v.end(), [](int x) { return x & 1; });
  std::cout << num << " odd numbers found" << std::endl;
  num = std::count_if(v.begin(), v.end(), [](int x) { return x >= 5; });
  std::cout << num << " numbers are greater than or equal to 5" << std::endl;
}

void ReplaceTest() {
  DrawHorizontalLine();
  std::vector<int> v{1, 2, 3, 4, 5, 1, 2, 1};
  for (int i : v)
    std::cout << i << " ";
  std::cout << std::endl;
  std::replace(v.begin(), v.end(), 1, 100);
  for (int i : v)
    std::cout << i << " ";
  std::cout << std::endl;
}

void AllOfTest() {
  DrawHorizontalLine();
  std::vector<int> v{1, 3, 5, 7, 9, 1, 3, 13, 19, 5};
  if (std::all_of(v.begin(), v.end(), [](int x) { return x > 10; })) {
    std::cout << "All the elements are > 10" << std::endl;
  } else {
    std::cout << "Not all the elements are > 10" << std::endl;
  }

  if (std::all_of(v.begin(), v.end(), [](int x) { return x < 20; })) {
    std::cout << "All the elements are < 20" << std::endl;
  } else {
    std::cout << "Not all the elements are < 20" << std::endl;
  }
}

void StringTransformTest() {
  DrawHorizontalLine();
  std::string s{"This is a test"};
  std::cout << "Before transform: " << s << std::endl;
  std::transform(s.begin(), s.end(), s.begin(), ::toupper);
  std::cout << "After transform: " << s << std::endl;
}

int main() {
  // FindTest();
  // CountTest();
  // AllOfTest();
  StringTransformTest();
  return 0;
}