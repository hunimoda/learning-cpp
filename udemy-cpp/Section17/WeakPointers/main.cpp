#include <iostream>
#include <memory>

class B;

class A {
 public:
  A() { std::cout << "A Constructor" << std::endl; }
  ~A() { std::cout << "A Destructor" << std::endl; }
  void SetB(std::shared_ptr<B> &b) {
    b_ptr_ = b;
  }

 private:
  std::shared_ptr<B> b_ptr_;
};

class B {
 public:
  B() { std::cout << "B Constructor" << std::endl; }
  ~B() { std::cout << "B Destructor" << std::endl; }
  void SetA(std::shared_ptr<A> &a) {
    a_ptr_ = a;
  }

 private:
  // std::shared_ptr<A> a_ptr_;
  std::weak_ptr<A> a_ptr_;
};

int main() {
  std::shared_ptr<A> a = std::make_shared<A>();
  std::shared_ptr<B> b = std::make_shared<B>();
  a->SetB(b);
  b->SetA(a);
  return 0;
}