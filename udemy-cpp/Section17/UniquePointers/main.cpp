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

int main() {
  // Test *t1 = new Test(1000);
  // delete t1;
  std::unique_ptr<Test> t2(new Test(100));
  std::unique_ptr<Test> t3 = std::make_unique<Test>(1000);
  std::unique_ptr<Test> t4;
  t4 = std::move(t2);
  if (!t2)
    std::cout << "t2 is nullptr" << std::endl;

  std::unique_ptr<Account> a1 =
      std::make_unique<CheckingAccount>("Moe", 5000.0);
  std::cout << *a1 << std::endl;
  a1->Deposit(5000.0);
  std::cout << *a1 << std::endl;

  std::vector<std::unique_ptr<Account>> accounts;
  accounts.push_back(std::make_unique<CheckingAccount>("James", 1000.0));
  accounts.push_back(std::make_unique<SavingsAccount>("Billy", 4000.0, 5.2));
  accounts.push_back(std::make_unique<TrustAccount>("Bobby", 5000.0, 4.5));

  for (const auto &account : accounts) {
    std::cout << *account << std::endl;
  }

  return 0;
}