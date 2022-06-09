#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

class Person {
 public:
  friend std::ostream &operator<<(std::ostream &os, const Person &p);
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

std::ostream &operator<<(std::ostream &os, const Person &p) {
  os << p.name_ << ": " << p.age_;
  return os;
}

template <typename T>
void Display(const std::vector<T> &v) {
  std::cout << "[";
  std::for_each(v.begin(), v.end(), [](T param) { std::cout << " " << param; });
  std::cout << " ]" << std::endl;
}

void Test1() {
  std::cout << "\nTest1 ----------------------------------------" << std::endl;
  std::vector<int> v{1, 2, 3, 4, 5};
  Display(v);

  v = {2, 4, 5, 6};
  Display(v);

  std::vector<int> v2(10, 100);
  Display(v2);
}

void Test2() {
  std::cout << "\nTest2 ----------------------------------------" << std::endl;
  std::vector<int> v{1, 2, 3, 4, 5};
  Display(v);
  std::cout << "v size: " << v.size() << std::endl;
  std::cout << "v max size: " << v.max_size() << std::endl;
  std::cout << "v capacity: " << v.capacity() << std::endl << std::endl;

  v.push_back(6);
  Display(v);
  std::cout << "v size: " << v.size() << std::endl;
  std::cout << "v max size: " << v.max_size() << std::endl;
  std::cout << "v capacity: " << v.capacity() << std::endl << std::endl;

  v.shrink_to_fit();
  Display(v);
  std::cout << "v size: " << v.size() << std::endl;
  std::cout << "v max size: " << v.max_size() << std::endl;
  std::cout << "v capacity: " << v.capacity() << std::endl << std::endl;

  v.reserve(100);
  Display(v);
  std::cout << "v size: " << v.size() << std::endl;
  std::cout << "v max size: " << v.max_size() << std::endl;
  std::cout << "v capacity: " << v.capacity() << std::endl << std::endl;
}

void Test3() {
  std::cout << "\nTest3 ----------------------------------------" << std::endl;
  std::vector<int> v{1, 2, 3, 4, 5};
  Display(v);
  v[0] = 100;
  v.at(1) = 200;
  Display(v);
}

void Test4() {
  std::cout << "\nTest4 ----------------------------------------" << std::endl;
  std::vector<Person> stooges;
  Person p1("Larry", 18);
  Display(stooges);
  stooges.push_back(p1);
  Display(stooges);
  stooges.push_back(Person("Moe", 25));
  Display(stooges);
  stooges.emplace_back("Curly", 30);
  Display(stooges);
}

void Test5() {
  std::cout << "\nTest5 ----------------------------------------" << std::endl;
  std::vector<Person> stooges{{"Larry", 18}, {"Moe", 25}, {"Curly", 30}};
  Display(stooges);
  std::cout << "\nFront: " << stooges.front() << std::endl;
  std::cout << "Back: " << stooges.back() << std::endl;

  stooges.pop_back();
  Display(stooges);
}

void Test6() {
  std::cout << "\nTest6 ----------------------------------------" << std::endl;
  std::vector<int> v{1, 2, 3, 4, 5};
  Display(v);

  v.clear();
  Display(v);

  v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Display(v);
  v.erase(v.begin(), v.begin() + 2);
  Display(v);

  v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto it = v.begin();
  while (it != v.end()) {
    if (*it % 2) {
      it++;
    } else {
      v.erase(it);
    }
  }
  Display(v);
}

void Test7() {
  std::cout << "\nTest7 ----------------------------------------" << std::endl;
  std::vector<int> v1{1, 2, 3, 4, 5};
  std::vector<int> v2{10, 20, 30, 40, 50};

  Display(v1);
  Display(v2);
  std::cout << std::endl;

  v2.swap(v1);
  Display(v1);
  Display(v2);
}

void Test8() {
  std::cout << "\nTest8 ----------------------------------------" << std::endl;
  std::vector<int> v{1, 21, 3, 40, 12};
  Display(v);
  std::sort(v.begin(), v.end());
  Display(v);
}

void Test9() {
  std::cout << "\nTest9 ----------------------------------------" << std::endl;
  std::vector<int> v1{1, 2, 3, 4, 5};
  std::vector<int> v2{10, 20};

  Display(v1);
  Display(v2);
  std::cout << std::endl;

  std::copy(v1.begin(), v1.end(), std::back_inserter(v2));
  Display(v1);
  Display(v2);
  std::cout << std::endl;

  v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  v2 = {10, 20};

  Display(v1);
  Display(v2);
  std::cout << std::endl;

  std::copy_if(v1.begin(), v1.end(), std::back_inserter(v2),
               [](int x) { return x % 2 == 0; });
  Display(v1);
  Display(v2);
  std::cout << std::endl;
}

void Test10() {
  std::cout << "\nTest10 ---------------------------------------" << std::endl;
  std::vector<int> v1{1, 2, 3, 4, 5};
  std::vector<int> v2{10, 20, 30, 40, 50};
  std::vector<int> v3{30, 40};

  Display(v1);
  Display(v2);
  Display(v3);
  std::cout << std::endl;

  std::transform(v1.begin(), v1.end(), v2.begin(), std::back_inserter(v3), 
                 [](int x, int y) { return x * y; });
  Display(v1);
  Display(v2);
  Display(v3);
  std::cout << std::endl;
}

void Test11() {
  std::cout << "\nTest11 ---------------------------------------" << std::endl;
  std::vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> v2{100, 200, 300, 400};

  Display(v1);
  Display(v2);
  std::cout << std::endl;

  auto it = std::find(v1.begin(), v1.end(), 5);
  if (it != v1.end()) {
    std::cout << "inserting..." << std::endl;
    v1.insert(it, v2.begin(), v2.end());
  } else {
    std::cout << "5 not found" << std::endl;
  }
  Display(v1);
}

int main() {
  // Test1();
  // Test2();
  // Test3();
  // Test4();
  // Test5();
  // Test6();
  // Test7();
  // Test8();
  // Test9();
  // Test10();
  Test11();
  return 0;
}