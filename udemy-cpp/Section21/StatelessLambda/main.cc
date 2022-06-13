// Stateless lambda expressions
// [] - empty capture lists

#include <iostream>
#include <string>
#include <vector>
#include <functional>  // for std::function
#include <algorithm>

class Person {
 public:
  friend std::ostream &operator<<(std::ostream &os, const Person &p);
  Person(std::string name, int age) : name_(name), age_(age) {}
  Person(const Person &p) : Person(p.name_, p.age_) {}
  ~Person() = default;
  std::string GetName() const { return this->name_; }
  void SetName(std::string name) { this->name_ = name; }
  int GetAge() const { return this->age_; }
  void SetAge(int age) { this->age_ = age; }

 private:
  std::string name_;
  int age_;
};

std::ostream &operator<<(std::ostream &os, const Person &p) {
  return os << p.name_ << ": " << p.age_;
}

void Test1() {
  std::cout << "\nTest1 ========================================" << std::endl;
  []() { std::cout << "Hi" << std::endl; }();
  [](int x) { std::cout << x << std::endl; }(100);
  [](int x, int y) { std::cout << x + y << std::endl; }(100, 200);
}

void Test2() {
  std::cout << "\nTest2 ========================================" << std::endl;
  
  auto lambda1 = []() { std::cout << "Hi" << std::endl; };
  lambda1();  // Hi

  int num1 = 100, num2 = 100;
  auto lambda2 = [](int x, int y) { std::cout << x + y << std::endl; };
  lambda2(10, 20);  // 30
  lambda2(num1, num2);  // 200

  auto lambda3 = [](int &x, int y) {
    std::cout << "x: " << x << ", y: " << y << std::endl;
    x = 1000, y = 2000;
  };
  lambda3(num1, num2);  // x: 100, y: 100
  std::cout << "num1: " << num1 << ", num2: " << num2 << std::endl;
  // num1: 1000, num2: 100
}

void Test3() {
  std::cout << "\nTest3 ========================================" << std::endl;
  Person stooge("Larry", 18);
  std::cout << stooge << std::endl;  // Larry: 18

  auto lambda1 = [](Person p) { std::cout << p << std::endl; };
  lambda1(stooge);  // Larry: 18 (copy-constructed)

  auto lambda2 = [](const Person &p) { std::cout << p << std::endl; };
  lambda2(stooge);  // Larry: 18 (original)

  auto lambda3 = [](Person &p) {
    p.SetName("Frank");
    p.SetAge(25);
    std::cout << p << std::endl;
  };
  lambda3(stooge);  // Frank: 25 (local variable p printed)

  std::cout << stooge << std::endl;  // Frank: 25 (changed in lambda3)
}

void FilterVector(const std::vector<int> &v,
                  const std::function<bool(int)> &predicate) {
  std::cout << "[";
  for (auto elem : v)
    if (predicate(elem)) std::cout << " " << elem;
  std::cout << " ]" << std::endl;
}

void Test4() {
  std::cout << "\nTest4 ========================================" << std::endl;
  std::vector<int> nums{10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

  FilterVector(nums, [](int x) { return x > 50; });
  FilterVector(nums, [](int x) { return x <= 30; });
  FilterVector(nums, [](int x) { return 30 <= x && x <= 60; });
}

auto MakeLambda() {
  return []() { std::cout << "Hello World!" << std::endl; };
}

void Test5() {
  std::cout << "\nTest5 ========================================" << std::endl;
  auto lambda = MakeLambda();
  lambda();
}

void Test6() {
  std::cout << "\nTest6 ========================================" << std::endl;
  auto lambda = [](auto x, auto y) {
    std::cout << "x: " << x << ", y: " << y << std::endl;
    // std::cout << "x + y: " << x + y << std::endl;
  };

  lambda(10, 20);
  lambda(100.3, 200);
  lambda(12.5, 15.54);

  // lambda(Person("Larry", 18), Person("Curly", 22));
}

void Test7() {
  std::cout << "\nTest7 ========================================" << std::endl;

  std::vector<Person> stooges{{"Larry", 18}, {"Moe", 30}, {"Curly", 25}};
  std::sort(stooges.begin(), stooges.end(),
            [](const Person &p1, const Person &p2) {
              return p1.GetName() < p2.GetName();
            });
  std::for_each(stooges.begin(), stooges.end(),
                [](const Person &p) { std::cout << p << std::endl; });
  std::cout << std::endl;

  std::sort(stooges.begin(), stooges.end(),
            [](const Person &p1, const Person &p2) {
              return p1.GetAge() < p2.GetAge();
            });

  std::for_each(stooges.begin(), stooges.end(),
                [](const Person &p) { std::cout << p << std::endl; });
  std::cout << std::endl;
}

int main() {
  // Test1();
  // Test2();
  // Test3();
  // Test4();
  // Test5();
  // Test6();
  Test7();

  std::cout << std::endl;
  return 0;
}