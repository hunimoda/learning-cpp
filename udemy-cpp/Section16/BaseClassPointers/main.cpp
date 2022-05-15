#include <iostream>
#include <vector>

class Account {
 public:
  void Withdraw(double amount) {
    std::cout << "Withdrawing from Account: " << amount << std::endl;
  }
};

class Checking : public Account {
 public:
  void Withdraw(double amount) {
    std::cout << "Withdrawing from Checking: " << amount << std::endl;
  }
};

class Savings : public Account {
 public:
  void Withdraw(double amount) {
    std::cout << "Withdrawing from Savings: " << amount << std::endl;
  }
};

class Trust : public Account {
 public:
  void Withdraw(double amount) {
    std::cout << "Withdrawing from Trust: " << amount << std::endl;
  }
};

int main() {
  std::cout << "\n==== Pointers ==============" << std::endl;
  Account *p1 = new Account();
  Account *p2 = new Savings();
  Account *p3 = new Checking();
  Account *p4 = new Trust();

  p1->Withdraw(1000.0);
  p2->Withdraw(1000.0);
  p3->Withdraw(1000.0);
  p4->Withdraw(1000.0);

  std::cout << "\n==== Array =================" << std::endl;
  Account *array[] = {p1, p2, p3, p4};
  for (size_t i{0}; i < 4; i++)
    array[i]->Withdraw(1000.0);

  std::cout << "\n==== Vector ================" << std::endl;
  std::vector<Account *> accounts{p1, p2, p3, p4};
  for (Account *account: accounts)
    account->Withdraw(1000.0);

  std::cout << "\n==== Clean up ==============" << std::endl;
  delete p1;
  delete p2;
  delete p3;
  delete p4;

  return 0;
}