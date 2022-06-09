#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

void Display(const std::array<int, 5> &arr) {
  std::cout << "[";
  for (const int num : arr)
    std::cout << " " << num;
  std::cout << " ]" << std::endl;
}

void Test1() {
  std::cout << "\nTest1 ----------------------------------------" << std::endl;
  std::array<int, 5> arr1{1, 2, 3, 4, 5};
  std::array<int, 5> arr2;

  Display(arr1);
  Display(arr2);

  arr2 = {10, 20, 30, 40, 50};

  Display(arr1);
  Display(arr2);

  std::cout << "Size of arr1: " << arr1.size() << std::endl;
  std::cout << "Size of arr2: " << arr2.size() << std::endl;

  arr1[0] = 1000;
  arr1.at(1) = 2000;
  Display(arr1);

  std::cout << "Front of arr2: " << arr2.front() << std::endl;
  std::cout << "Back of arr2: " << arr2.back() << std::endl;
}

void Test2() {
  std::cout << "\nTest2 ----------------------------------------" << std::endl;
  std::array<int, 5> arr1{1, 2, 3, 4, 5};
  std::array<int, 5> arr2{10, 20, 30, 40, 50};

  Display(arr1);
  Display(arr2);

  arr1.fill(0);

  Display(arr1);
  Display(arr2);

  arr1.swap(arr2);

  Display(arr1);
  Display(arr2);
}

void Test3() {
  std::cout << "\nTest3 ----------------------------------------" << std::endl;
  std::array<int, 5> arr{1, 2, 3, 4, 5};

  int *ptr = arr.data();
  std::cout << ptr << std::endl;

  for (int i = 0; i < 5; i++)
    std::cout << ptr[i] << " ";
  std::cout << std::endl;

  *ptr = 10;
  ptr[4] = 50;

  Display(arr);
}

void Test4() {
  std::cout << "\nTest4 ----------------------------------------" << std::endl;
  std::array<int, 5> arr{2, 1, 4, 5, 3};
  Display(arr);

  std::sort(arr.begin(), arr.end());
  Display(arr);
}

void Test5() {
  std::cout << "\nTest5 ----------------------------------------" << std::endl;
  std::array<int, 5> arr{2, 1, 4, 5, 3};
  std::array<int, 5>::iterator min_value =
      std::min_element(arr.begin(), arr.end());
  auto max_value = std::max_element(arr.begin(), arr.end());
  std::cout << "min: " << *min_value << ", max: " << *max_value << std::endl;
}

void Test6() {
  std::cout << "\nTest6 ----------------------------------------" << std::endl;
  std::array<int, 5> arr{2, 1, 3, 3, 5};
  auto adjacent = std::adjacent_find(arr.begin(), arr.end());
  if (adjacent != arr.end()) {
    std::cout << "Adjacent element found with value: "
              << *adjacent << std::endl;
  } else {
    std::cout << "No adjacent element found" << std::endl;
  }
}

void Test7() {
  std::cout << "\nTest7 ----------------------------------------" << std::endl;
  std::array<int, 5> arr{1, 2, 3, 4, 5};
  int sum = std::accumulate(arr.begin(), arr.end(), 0);
  std::cout << "Sum of the elements in arr: " << sum << std::endl;
}

void Test8() {
  std::cout << "\nTest8 ----------------------------------------" << std::endl;
  std::array<int, 10> arr{1, 2, 3, 1, 2, 3, 3, 3, 3, 3};
  int count = std::count(arr.begin(), arr.end(), 3);
  std::cout << "Found 3: " << count << " times" << std::endl;
}

void Test9() {
  std::cout << "\nTest9 ----------------------------------------" << std::endl;
  std::array<int, 10> arr{1, 2, 3, 50, 60, 70, 80, 200, 300, 400};
  int count = std::count_if(arr.begin(), arr.end(),
                            [](int x) { return 10 < x && x < 200; });
  std::cout << "Found " << count << " matches" << std::endl;
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

  return 0;
}