#include <iostream>
#include <queue>

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
void Display(std::priority_queue<T> pq) {
  std::cout << "[";
  while (!pq.empty()) {
    std::cout << " " << pq.top();
    pq.pop();
  }
  std::cout << " ]" << std::endl;
}

void Test1() {
  std::cout << "\nTest1 ========================================" << std::endl;
  std::priority_queue<int> pq;
  for (int n : {3, 5, 7, 12, 23, 12, 4, 100, 0, 3, 5, 7})
    pq.push(n);

  std::cout << "Size: " << pq.size() << std::endl;
  std::cout << "Top: " << pq.top() << std::endl;

  Display(pq);

  pq.pop();
  Display(pq);
}

void Test2() {
  std::cout << "\nTest2 ========================================" << std::endl;

  std::priority_queue<Person> pq;
  pq.push(Person("A", 1));
  pq.push(Person("B", 10));
  pq.push(Person("C", 1));
  pq.push(Person("D", 1));
  pq.push(Person("E", 14));
  pq.push(Person("F", 10));
  pq.push(Person("G", 18));
  pq.push(Person("H", 7));
  pq.push(Person("I", 27));

  Display(pq);
}
int main() {
  // Test1();
  Test2();
  return 0;
}