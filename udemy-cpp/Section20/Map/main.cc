#include <iostream>
#include <map>
#include <set>
#include <sstream>

void Display(const std::map<std::string, std::set<int>> &map) {
  if (map.size() == 0) {
    std::cout << "{ }" << std::endl;
    return;
  }

  std::cout << "{" << std::endl;
  for (const auto &[key, set] : map) {
    std::cout << "  " << key << ": ";
    if (set.size() == 0) {
      std::cout << "{ }" << std::endl;
      continue;
    }

    std::string s = "{ ";
    for (const int &elem : set)
      s += std::to_string(elem) + ", ";
    std::cout << s.substr(0, s.length() - 2) << " }" << std::endl;
  }
  std::cout << "}" << std::endl;
}

template <typename T1, typename T2>
void Display(const std::map<T1, T2> &map) {
  if (map.size() == 0) {
    std::cout << "{ }" << std::endl;
    return;
  }

  std::ostringstream oss;
  oss << "{ ";
  for (const auto &[key, value] : map)
    oss << key << ": " << value << ", ";
  std::string s = oss.str();
  std::cout << s.substr(0, s.length() - 2) << " }" << std::endl;
}

void Test1() {
  std::cout << "\nTest1 ========================================" << std::endl;
  std::map<std::string, int> map{{"Larry", 3}, {"Moe", 1}, {"Curly", 2}};
  Display(map);

  map.insert(std::pair<std::string, int>("Anna", 10));
  Display(map);

  map.insert(std::make_pair("Joe", 5));
  Display(map);

  map["Frank"] = 18;
  Display(map);

  map["Frank"] += 10;
  Display(map);

  map.erase("Frank");
  Display(map);

  std::cout << "map.count(\"Joe\"): " << map.count("Joe") << std::endl;
  std::cout << "map.count(\"Frank\"): " << map.count("Frank") << std::endl;

  auto it = map.find("Larry");
  if (it != map.end()) {
    std::cout << "Found { " << it->first << ": " << it->second << " }"
              << std::endl;
  }

  map.clear();
  Display(map);
}

void Test2() {
  std::cout << "\nTest2 ========================================" << std::endl;
  std::map<std::string, std::set<int>> grades{
      {"Larry", {100, 90}},
      {"Moe", {94}},
      {"Curly", {80, 90, 100}}};
  Display(grades);

  grades["Larry"].insert(95);
  Display(grades);

  auto it = grades.find("Moe");
  if (it != grades.end())
    it->second.insert(98);
  Display(grades);
}

int main() {
  // Test1();
  Test2();
  return 0;
}