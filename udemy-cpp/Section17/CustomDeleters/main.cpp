#include <iostream>
#include <memory>

class Test {
 public:
  Test() : data_(0) { std::cout << "\tTest Constructor" << std::endl; }
  Test(int data) : data_(data) {
    std::cout << "\tTest Constructor(" << data << ")" << std::endl;
  }
  ~Test() { std::cout << "\tTest Destructor" << std::endl; }
  int GetData() const { return data_; }

 private:
  int data_;
};

void MyDeleter(Test *ptr) {
  std::cout << "\tUsing my custom function deleter" << std::endl;
  delete ptr;
}

int main() {
  {
    std::shared_ptr<Test> ptr_1(new Test(100), MyDeleter);
  }
  std::cout << "------------------------------" << std::endl;

  {
    std::shared_ptr<Test> ptr_2(
        new Test(200),
        [](Test *ptr) {
          std::cout << "\tUsing my custom lambda deleter" << std::endl;
          delete ptr;
        });
  }
  return 0;
}