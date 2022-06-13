#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>  // for std::iota

void Test1() {
  std::cout << "\nTest1 ========================================" << std::endl;
  std::vector<int> nums{10, 20, 30, 40, 50};
  std::for_each(nums.begin(), nums.end(), [](int x) { std::cout << x << " "; });
  std::cout << std::endl;
}

void Test2() {
  std::cout << "\nTest2 ========================================" << std::endl;
  struct Point {
    int x;
    int y;
  };

  Point p1{1, 2}, p2{4, 3}, p3{3, 5}, p4{3, 1};
  std::vector<Point> triangle1{p1, p2, p3};
  std::vector<Point> triangle2{p2, p1, p3};
  std::vector<Point> triangle3{p1, p2, p4};

  if (std::is_permutation(
          triangle1.begin(), triangle1.end(), triangle2.begin(),
          [](const Point &p1, const Point &p2) {
            return p1.x == p2.x && p1.y == p2.y;
          })) {
    std::cout << "Triangle1 and triangle2 are equivalent" << std::endl;
  } else {
    std::cout << "Triangle1 and triangle2 are NOT equivalent" << std::endl;
  }

  if (std::is_permutation(
          triangle1.begin(), triangle1.end(), triangle3.begin(),
          [](const Point &p1, const Point &p2) {
            return p1.x == p2.x && p1.y == p2.y;
          })) {
    std::cout << "Triangle1 and triangle3 are equivalent" << std::endl;
  } else {
    std::cout << "Triangle1 and triangle3 are NOT equivalent" << std::endl;
  }
}

void Test3() {
  std::cout << "\nTest3 ========================================" << std::endl;
  std::vector<int> test_scores{93, 88, 75, 68, 65};
  int bonus_points = 5;

  std::transform(
      test_scores.begin(), test_scores.end(), test_scores.begin(),
      [bonus_points](int test_score) { return test_score + bonus_points; });
  for (const auto test_score : test_scores)
    std::cout << test_score << " ";
  std::cout << std::endl;
}

void Test4() {
  std::cout << "\nTest4 ========================================" << std::endl;
  std::vector<int> nums{1, 2, 3, 4, 5};
  nums.erase(
      std::remove_if(nums.begin(), nums.end(),
      [](int x) { return x % 2 == 0; }), nums.end());
  for (int num : nums)
    std::cout << num << " ";
  std::cout << std::endl;
}

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
  return os << "Person {name: '" << p.name_ << "', age: " << p.age_ << "}";
}

void Test5() {
  std::cout << "\nTest5 ========================================" << std::endl;
  Person person1("Larry", 18);
  Person person2("Moe", 30);
  Person person3("Curly", 25);

  std::vector<Person> people{person1, person2, person3};
  for (const auto &person : people)
    std::cout << person << std::endl;
  std::cout << std::endl;

  std::sort(people.begin(), people.end(),
            [](const Person &p1, const Person &p2) {
              return p1.GetName() < p2.GetName();
            });
  for (const auto &person : people)
    std::cout << person << std::endl;
  std::cout << std::endl;

  std::sort(people.begin(), people.end(),
            [](const Person &p1, const Person &p2) {
              return p1.GetAge() > p2.GetAge();
            });
  for (const auto &person : people)
    std::cout << person << std::endl;
  std::cout << std::endl;
}

bool InBetween(const std::vector<int> &nums, int min_value, int max_value) {
  return std::all_of(
      nums.begin(), nums.end(), [min_value, max_value](int x) {
        return min_value <= x && x <= max_value;
      });
}

void Test6() {
  std::cout << "\nTest6 ========================================" << std::endl;
  std::cout << std::boolalpha;

  std::vector<int> nums(10);
  std::iota(nums.begin(), nums.end(), 1);

  for (int num : nums)
    std::cout << num << " ";
  std::cout << std::endl;

  std::cout << InBetween(nums, 50, 60) << std::endl;  // false
  std::cout << InBetween(nums, 1, 10) << std::endl;  // true
  std::cout << InBetween(nums, 5, 7) << std::endl;  // false
}

class PasswordValidator1 {
 public:
  bool IsValid(std::string password) {
    return std::all_of(
        password.begin(), password.end(),
        [this](char c) {
          return c != restricted_;
        });
  }

 private:
  char restricted_ = '$';
};

class PasswordValidator2 {
 public:
  bool IsValid(std::string password) {
    return std::all_of(
        password.begin(), password.end(),
        [this](char c) {
          return std::none_of(
              restricted_.begin(), restricted_.end(),
              [this, c](char restricted_char) { return c == restricted_char; });
        });
  }

 private:
  std::vector<char> restricted_{'!', '$', '+'};
};

void Test7() {
  std::cout << "\nTest7 ========================================" << std::endl;

  // PasswordValidator1 --------------------------------------------------------
  std::string password = "holywood1$";
  PasswordValidator1 pv1;

  if (pv1.IsValid(password)) {
    std::cout << password << " is a valid password" << std::endl;
  } else {
    std::cout << password << " is NOT a valid password" << std::endl;
  }

  password = "holywood1";
  if (pv1.IsValid(password)) {
    std::cout << password << " is a valid password" << std::endl;
  } else {
    std::cout << password << " is NOT a valid password" << std::endl;
  }
  std::cout << std::endl;

  // PasswordValidator2 --------------------------------------------------------
  password = "C++Rocks!";
  PasswordValidator2 pv2;

  if (pv2.IsValid(password)) {
    std::cout << password << " is a valid password" << std::endl;
  } else {
    std::cout << password << " is NOT a valid password" << std::endl;
  }
  
  password = "CPlusPlusRocks!";
  if (pv2.IsValid(password)) {
    std::cout << password << " is a valid password" << std::endl;
  } else {
    std::cout << password << " is NOT a valid password" << std::endl;
  }

  password = "CPlusPlusRocks";
  if (pv2.IsValid(password)) {
    std::cout << password << " is a valid password" << std::endl;
  } else {
    std::cout << password << " is NOT a valid password" << std::endl;
  }
}

int main() {
  // Test1();
  // Test2();
  // Test3();
  // Test4();
  // Test5();
  // Test6();
  Test7();
  return 0;
}