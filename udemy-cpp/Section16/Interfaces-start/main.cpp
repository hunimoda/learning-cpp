#include <iostream>

class Account {
  friend std::ostream &operator<<(std::ostream &os, const Account &account);
 public:
  virtual ~Account() {}
  virtual void Withdraw(double amount) {
    std::cout << "In Account::Withdraw" << std::endl;
  }
};

std::ostream &operator<<(std::ostream &os, const Account &account) {
  return os << "Account display";
}

class Checking : public Account {
  friend std::ostream &operator<<(std::ostream &os, const Checking &checking);
 public:
  virtual ~Checking() {}
  virtual void Withdraw(double amount) {
    std::cout << "In Checking::Withdraw" << std::endl;
  }
};

std::ostream &operator<<(std::ostream &os, const Checking &checking) {
  return os << "Checking display";
}

class Savings : public Account {
  friend std::ostream &operator<<(std::ostream &os, const Savings &savings);
 public:
  virtual ~Savings() {}
  virtual void Withdraw(double amount) {
    std::cout << "In Savings::Withdraw" << std::endl;
  }
};

std::ostream &operator<<(std::ostream &os, const Savings &savings) {
  return os << "Savings display";
}

class Trust : public Account {
  friend std::ostream &operator<<(std::ostream &os, const Trust &trust);
 public:
  virtual ~Trust() {}
  virtual void Withdraw(double amount) {
    std::cout << "In Trust::Withdraw" << std::endl;
  }
};

std::ostream &operator<<(std::ostream &os, const Trust &trust) {
  return os << "Trust display";
}

int main() {
  Account *a1 = new Account();
  Account *a2 = new Checking();
  Account *a3 = new Savings();
  Account *a4 = new Trust();
  Account *accounts[] = { a1, a2, a3, a4 };

  for (const Account *account: accounts)
    std::cout << *account << std::endl;

  return 0;
}