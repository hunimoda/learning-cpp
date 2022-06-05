#include <iostream>
#include <string>
#include <vector>

template <typename T>
class Item {
 public:
  Item(std::string name, T value) : name_(name), value_(value) {}
  std::string GetName() const { return name_; }
  T GetValue() const { return value_; }

 private:
  std::string name_;
  T value_;
};

template <typename T1, typename T2>
struct Pair {
  T1 first;
  T2 second;
};

int main() {
  Item<int> item1("Frank", 100);
  std::cout << item1.GetName() << " " << item1.GetValue() << std::endl;

  Item<std::string> item2("Frank", "Professor");
  std::cout << item2.GetName() << " " << item2.GetValue() << std::endl;

  Item<Item<std::string>> item3("C++", item2);
  std::cout << item3.GetName() << " " << item3.GetValue().GetName()
            << " " << item3.GetValue().GetValue() << std::endl;
  
  Item item4("Frank", 200);
  std::cout << item4.GetName() << " " << item4.GetValue() << std::endl;

  std::cout << "----------------------------------------" << std::endl;
  std::vector<Item<double>> v;
  v.push_back(Item<double>("Larry", 1.23));
  v.push_back(Item<double>("Moe", 4.56));
  v.push_back(Item<double>("Curly", 7.89));

  for (const auto &item : v)
    std::cout << item.GetName() << " " << item.GetValue() << std::endl;

  std::cout << "----------------------------------------" << std::endl;
  Pair<std::string, int> p1 = { "Frank", 100 };
  Pair<int, double> p2 = { 123, 4.56 };

  std::cout << p1.first << ", " << p1.second << std::endl;
  std::cout << p2.first << ", " << p2.second << std::endl;

  return 0;
}