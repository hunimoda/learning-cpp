#include <iostream>
#include <vector>
#include <algorithm>

int global_x = 1000;

void Test1() {
  std::cout << "\nTest1 ========================================" << std::endl;
  int local_x = 100;

  auto lambda = [local_x]() {
    std::cout << local_x << std::endl;
    std::cout << global_x << std::endl;
  };
  lambda();
}

void Test2() {
  std::cout << "\nTest2 ========================================" << std::endl;
  int x = 100;
  auto lambda = [x]() mutable {
    x += 100;
    std::cout << x << std::endl;
  };

  lambda();  // 200
  std::cout << x << std::endl;  // 100

  lambda();  // 300
  std::cout << x << std::endl;  // 100
}

void Test3() {
  std::cout << "\nTest3 ========================================" << std::endl;
  int x = 100;

  auto lambda = [&x]() mutable {
    x += 100;
    std::cout << x << std::endl;
  };

  lambda();
  std::cout << x << std::endl;
}

void Test4() {
  std::cout << "\nTest4 ========================================" << std::endl;
  int x = 100, y = 200, z = 300;

  // Default capture by value - mutable
  // Only variables used within the lambda body are captured by value
  // The variable z is not captured by the value
  auto lambda = [=]() mutable {
    x += 100, y += 100;
    std::cout << x << std::endl;  // 200
    std::cout << y << std::endl;  // 300
  };

  lambda();
  std::cout << std::endl;
  std::cout << x << std::endl;  // 100
  std::cout << y << std::endl;  // 200
}

void Test5() {
  std::cout << "\nTest5 ========================================" << std::endl;
  int x = 100, y = 200, z = 300;

  // Default capture by reference
  // All three variables that are used(x, y, z) are captured
  auto lambda = [&]() {
    x += 100, y += 100, z += 100;
    std::cout << x << std::endl;  // 200
    std::cout << y << std::endl;  // 300
    std::cout << z << std::endl;  // 400
  };
  lambda();

  std::cout << std::endl;
  std::cout << x << std::endl;  // 200
  std::cout << y << std::endl;  // 300
  std::cout << z << std::endl;  // 400
}

void Test6() {
  std::cout << "\nTest6 ========================================" << std::endl;
  int x = 100, y = 200, z = 300;

  // Default capture by value, but capture y as reference
  auto lambda = [=, &y]() mutable {
    x += 100, y += 100, z += 100;
    std::cout << x << std::endl;  // 200
    std::cout << y << std::endl;  // 300
    std::cout << z << std::endl;  // 400
  };
  lambda();
  
  std::cout << std::endl;
  std::cout << x << std::endl;  // 100
  std::cout << y << std::endl;  // 300
  std::cout << z << std::endl;  // 300
}

void Test7() {
  std::cout << "\nTest7 ========================================" << std::endl;
  int x = 100, y = 200, z = 300;

  // Default capture by reference, but capture x and z by value
  auto lambda = [&, x, z]() mutable {
    x += 100, y += 100, z += 100;
    std::cout << x << std::endl;  // 200
    std::cout << y << std::endl;  // 300
    std::cout << z << std::endl;  // 400
  };
  lambda();

  std::cout << std::endl;
  std::cout << x << std::endl;  // 100
  std::cout << y << std::endl;  // 300
  std::cout << z << std::endl;  // 300
}

class Person {
 public:
  friend std::ostream &operator<<(std::ostream &os, const Person &p);

  Person() = default;
  Person(std::string name, int age) : name_(name), age_(age) {}
  Person(const Person &p) = default;
  ~Person() = default;

  std::string GetName() const { return this->name_; }
  void SetName(std::string name) { this->name_ = name; }
  int GetAge() const { return this->age_; }
  void SetAge(int age) { this->age_ = age; }

  // All versions are the same but use [this] version
  auto ChangePerson1() {
    return [this](std::string name, int age) { name_ = name, age_ = age; };
  }
  auto ChangePerson2() {
    return [=](std::string name, int age) { name_ = name, age_ = age; };
  }
  auto ChangePerson3() {
    return [&](std::string name, int age) { name_ = name, age_ = age; };
  }

 private:
  std::string name_;
  int age_;
};

std::ostream &operator<<(std::ostream &os, const Person &p) {
  return os << "{ " << p.name_ << ": " << p.age_ << " }";
}

void Test8() {
  std::cout << "\nTest8 ========================================" << std::endl;
  Person person("Larry", 18);
  std::cout << person << std::endl;

  // Default capture [this]: preferred way
  auto change_person1 = person.ChangePerson1();
  change_person1("Moe", 30);
  std::cout << person << std::endl;

  auto change_person2 = person.ChangePerson2();
  change_person2("Curly", 25);
  std::cout << person << std::endl;

  auto change_person3 = person.ChangePerson3();
  change_person3("Frank", 34);
  std::cout << person << std::endl;
}

class Lambda {
 public:
  Lambda(int y) : y(y) {}
  void operator() (int x) const {
    std::cout << x + y << std::endl;
  }

 private:
  int y;
};

void Test9() {
  std::cout << "\nTest9 ========================================" << std::endl;
  int y = 100;

  Lambda lambda1(y);
  auto lambda2 = [y](int x) { std::cout << x + y << std::endl; };

  lambda1(200);
  lambda2(200);
}

class People {
 public:
  People(int max_people = 10) : max_people_(max_people) {}
  People(const People &p) = default;
  void Add(std::string name, int age) { people_.emplace_back(name, age); }
  void SetMaxPeople(int max_people) { max_people_ = max_people; }
  int GetMaxPeople() const { return this->max_people_; }
  std::vector<Person> GetPeople(int max_age) {
    std::vector<Person> result;
    int count = 0;
    std::copy_if(people_.begin(), people_.end(), std::back_inserter(result), 
                 [this, &count, max_age](const Person &p) {
                   return p.GetAge() > max_age && count++ < max_people_;
                 });
    return result;
  }

 private:
  std::vector<Person> people_;
  int max_people_;
};

void Test10() {
  std::cout << "\nTest10 =======================================" << std::endl;

  People friends;
  friends.Add("Larry", 18);
  friends.Add("Curly", 25);
  friends.Add("Moe", 35);
  friends.Add("Frank", 28);
  friends.Add("James", 65);

  auto result = friends.GetPeople(17);
  std::cout << std::endl;
  for (const auto &person : result)
    std::cout << person << std::endl;  // All of them

  friends.SetMaxPeople(3);
  result = friends.GetPeople(17);
  std::cout << std::endl;
  for (const auto &person : result)
    std::cout << person << std::endl;  // Larry, Curly, Moe

  result = friends.GetPeople(50);
  std::cout << std::endl;
  for (const auto &person : result)
    std::cout << person << std::endl;  // James
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
  Test10();
  return 0;
}