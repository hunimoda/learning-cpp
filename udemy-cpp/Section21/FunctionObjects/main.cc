#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

struct SquareFunctor {
  void operator()(int x) {
    std::cout << x * x << " ";
  }
};

template <typename T>
struct Displayer {
  void operator()(const T &data) {
    std::cout << data << " ";
  }
};

class Multiplier {
 public:
  Multiplier(int m) : m_(m) {}
  int operator()(int x) const {
    return m_ * x;
  }

 private:
  int m_;
};

int main() {
  std::cout << "\nTest1 ========================================" << std::endl;
  SquareFunctor square;
  square(4);

  Displayer<int> d1;
  Displayer<std::string> d2;

  d1(100);
  d2("Frank");
  std::cout << std::endl;

  std::cout << "\nTest2 ========================================" << std::endl;
  std::vector<int> v1{1, 2, 3, 4, 5};
  std::vector<std::string> v2{"Larry", "Moe", "Curly"};

  std::for_each(v1.begin(), v1.end(), square);
  std::cout << std::endl;

  std::for_each(v1.begin(), v1.end(), Displayer<int>());
  std::cout << std::endl;

  std::for_each(v1.begin(), v1.end(), d1);
  std::cout << std::endl;

  std::for_each(v2.begin(), v2.end(), Displayer<std::string>());
  std::cout << std::endl;

  std::for_each(v2.begin(), v2.end(), d2);
  std::cout << std::endl;

  std::cout << "\nTest3 ========================================" << std::endl;
  std::for_each(v1.begin(), v1.end(),
                [](int x) { std::cout << x * x << " "; });
  std::cout << std::endl;

  std::for_each(v1.begin(), v1.end(),
                [](int x) { std::cout << 10 * x << " "; });
  std::cout << std::endl;

  std::for_each(v1.begin(), v1.end(),
                [](int x) { std::cout << x << " "; });
  std::cout << std::endl;

  std::for_each(v2.begin(), v2.end(),
                [](std::string s) { std::cout << s << " "; });
  std::cout << std::endl;

  std::cout << "\nTest4 ========================================" << std::endl;
  Multiplier mult(100);
  v1 = {1, 2, 3, 4};

  std::for_each(v1.begin(), v1.end(), [](int x) { std::cout << x << " "; });
  std::cout << std::endl;

  std::transform(v1.begin(), v1.end(), v1.begin(), mult);
  std::for_each(v1.begin(), v1.end(), [](int x) { std::cout << x << " "; });
  std::cout << std::endl;

  v1 = {1, 2, 3, 4};
  std::for_each(v1.begin(), v1.end(), [](int x) { std::cout << x << " "; });
  std::cout << std::endl;

  std::transform(v1.begin(), v1.end(), v1.begin(),
                 [](int x) { return 100 * x; });
  std::for_each(v1.begin(), v1.end(), [](int x) { std::cout << x << " "; });
  std::cout << std::endl;

  return 0;
}