#include <iostream>

class Account {
 public:
  virtual ~Account() {
    std::cout << "Account::~Account()" << std::endl;
  }
  virtual void Withdraw(double amount) {
    std::cout << "In Account::Withdraw" << std::endl;
  }
};

class Checking : public Account {
 public:
  virtual ~Checking() {
    std::cout << "Checking::~Checking()" << std::endl;
  }
  virtual void Withdraw(double amount) {
    std::cout << "In Checking::Withdraw" << std::endl;
  }
};

class Savings : public Account {
 public:
  virtual ~Savings() {
    std::cout << "Savings::~Savings()" << std::endl;
  }
  virtual void Withdraw(double amount) {
    std::cout << "In Savings::Withdraw" << std::endl;
  }
};

class Trust : public Account {
 public:
  virtual ~Trust() {
    std::cout << "Trust::~Trust()" << std::endl;
  }
  virtual void Withdraw(double amount) {
    std::cout << "In Trust::Withdraw" << std::endl;
  }
};

int main() {
  std::cout << "\n ==== Pointers ====" << std::endl;
  Account *p1 = new Account();
  Account *p2 = new Savings();
  Account *p3 = new Checking();
  Account *p4 = new Trust();

  p1->Withdraw(1000.0);
  p2->Withdraw(1000.0);
  p3->Withdraw(1000.0);
  p4->Withdraw(1000.0);

  std::cout << "\n ==== Clean up ====" << std::endl;
  delete p1;
  delete p2;
  delete p3;
  delete p4;

  return 0;
}