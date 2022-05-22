#include <iostream>
#include <memory>
#include <vector>

#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "TrustAccount.h"

class Test {
 public:
  Test() : data(0) {
    std::cout << "Test Constructor (" << data << ")" << std::endl;
  }
  Test(int data) : data(data) {
    std::cout << "Test Constructor (" << data << ")" << std::endl;
  }
  ~Test() {
    std::cout << "Test Destructor (" << data << ")" << std::endl;
  }
  int GetData() const { return data; }

 private:
  int data;
};

void Func(std::shared_ptr<Test> p) {
  std::cout << "Use count: " << p.use_count() << std::endl;
}

int main() {
  // std::shared_ptr<int> p1(new int(100));
  // std::cout << "Use count: " << p1.use_count() << std::endl;
  // std::shared_ptr<int> p2 = p1;
  // std::cout << "Use count: " << p1.use_count() << std::endl;
  // p1.reset();
  // std::cout << "Use count: " << p1.use_count() << std::endl;
  // std::cout << "Use count: " << p2.use_count() << std::endl;
  // std::shared_ptr<int> p3;
  // std::cout << "Use count: " << p2.use_count() << std::endl;
  // p3 = p2;
  // std::cout << "Use count: " << p2.use_count() << std::endl;

  // std::shared_ptr<Test> ptr = std::make_shared<Test>(100);
  // Func(ptr);
  // std::cout << "Use count: " << ptr.use_count() << std::endl;
  // {
  //   std::shared_ptr<Test> ptr1 = ptr;
  //   std::cout << "Use count: " << ptr.use_count() << std::endl;
  //   {
  //     std::shared_ptr<Test> ptr2 = ptr;
  //     std::cout << "Use count: " << ptr.use_count() << std::endl;
  //     ptr.reset();
  //   }
  //   std::cout << "Use count: " << ptr.use_count() << std::endl;
  // }
  // std::cout << "Use count: " << ptr.use_count() << std::endl;

  std::shared_ptr<Account> a1 =
      std::make_shared<TrustAccount>("Larry", 10000.0, 3.1);
  std::shared_ptr<Account> a2 =
      std::make_shared<CheckingAccount>("Moe", 5000.0);
  std::shared_ptr<Account> a3 =
      std::make_shared<SavingsAccount>("Curly", 6000.0);

  std::vector<std::shared_ptr<Account>> accounts;
  accounts.push_back(a1);
  accounts.push_back(a2);
  accounts.push_back(a3);

  for (const auto &account : accounts) {
    std::cout << *account << std::endl;
    std::cout << "Use count: " << account.use_count() << std::endl;
  }

  return 0;
}