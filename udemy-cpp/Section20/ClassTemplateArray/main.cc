#include <iostream>
#include <string>

template <typename T, int N>
class Array {
 public:
  friend std::ostream &operator<<(std::ostream &os, const Array &arr) {
    os << "[ ";
    for (const auto &value : arr.values_)
      os << value << " ";
    os << "]" << std::endl;
    return os;
  }

  Array() = default;
  Array(T init_value) {
    for (auto &value : values_)
      value = init_value;
  }

  void Fill(T fill) {
    for (auto &value : values_)
      value = fill;
  }

  size_t GetSize() const {
    return size_;
  }

  T &operator[](int index) {
    return values_[index];
  }

 private:
  const size_t size_ = N;
  T values_[N];
};

int main() {
  Array<int, 5> nums;
  std::cout << "The size of nums is: " << nums.GetSize() << std::endl;
  std::cout << nums << std::endl;

  nums.Fill(0);
  std::cout << "The size of nums is: " << nums.GetSize() << std::endl;
  std::cout << nums << std::endl;

  nums.Fill(123);
  std::cout << "The size of nums is: " << nums.GetSize() << std::endl;
  std::cout << nums << std::endl;

  nums[0] = 1000;
  nums[3] = 2000;
  std::cout << nums << std::endl;

  Array<int, 100> nums2(1);
  std::cout << "The size of nums2 is: " << nums.GetSize() << std::endl;
  std::cout << nums2 << std::endl;

  Array<std::string, 10> s("Hello");
  std::cout << "The size of s is: " << s.GetSize() << std::endl;
  std::cout << s << std::endl;

  s[0] = "World";
  s[3] = "Brother";
  std::cout << s << std::endl;

  s.Fill("X");
  std::cout << s << std::endl;

  return 0;
}