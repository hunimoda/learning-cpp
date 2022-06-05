#include <iostream>
#include <string>

template <typename T>
T Min(T a, T b) {
  return a < b ? a : b;
}

template <typename T1, typename T2>
void Func(T1 a, T2 b) {
  std::cout << a << ", " << b << std::endl;
}

struct Person {
  std::string name;
  int age;
  bool operator<(const Person &p) const {
    return this->age < p.age;
  }
};

std::ostream &operator<<(std::ostream &os, const Person &p) {
  return os << "name: " << p.name << ", age: " << p.age;
}

template <typename T>
void Swap(T &a, T &b) {
  // T temp = a;
  // a = b;
  // b = temp;
  T temp = std::move(a);
  a = std::move(b);
  b = std::move(temp);
}

int main() {
  Person p1 = { "Curly", 15 };
  Person p2 = { "Moe", 30 };
  Person p3 = Min<Person>(p1, p2);
  std::cout << p3 << std::endl;

  std::cout << Min<int>(2, 3) << std::endl;
  std::cout << Min(2, 3) << std::endl;
  std::cout << Min('A', 'B') << std::endl;
  std::cout << Min(12.5, 9.2) << std::endl;
  std::cout << Min(5 + 2 * 2, 7 + 40) << std::endl;

  Func<int, int>(10, 20);
  Func(10, 20);
  Func<char, double>('A', 12.3);
  Func('A', 12.3);
  Func(1000, "Testing");
  Func(2000, std::string("Frank"));
  Func<Person, Person>(p1, p2);
  Func(p1, p2);

  Swap(p1, p2);
  Func(p1, p2);

  return 0;
}