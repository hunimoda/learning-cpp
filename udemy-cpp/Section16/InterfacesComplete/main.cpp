#include <iostream>

class IPrintable {
  friend std::ostream &operator<<(std::ostream &os,
                                  const IPrintable &i_printable);
 public:
  virtual ~IPrintable() {}
  virtual void Print(std::ostream &os) const = 0;
};

std::ostream &operator<<(std::ostream &os, const IPrintable &i_printable) {
  i_printable.Print(os);
  return os;
}

void DisplayAnyPrintable(const IPrintable &i_printable) {
  std::cout << "[Printable]: " << i_printable << std::endl;
}

class Account : public IPrintable {
 public:
  virtual ~Account() {}
  virtual void Print(std::ostream &os) const override {
    os << "Account display";
  }
  virtual void Withdraw(double amount) {
    std::cout << "In Account::Withdraw" << std::endl;
  }
};

class Checking : public Account {
 public:
  virtual ~Checking() {}
  virtual void Print(std::ostream &os) const override {
    os << "Checking display";
  }
  virtual void Withdraw(double amount) {
    std::cout << "In Checking::Withdraw" << std::endl;
  }
};

class Savings : public Account {
 public:
  virtual ~Savings() {}
  virtual void Print(std::ostream &os) const override {
    os << "Savings display";
  }
  virtual void Withdraw(double amount) {
    std::cout << "In Savings::Withdraw" << std::endl;
  }
};

class Trust : public Account {
 public:
  virtual ~Trust() {}
  virtual void Print(std::ostream &os) const override {
    os << "Trust display";
  }
  virtual void Withdraw(double amount) {
    std::cout << "In Trust::Withdraw" << std::endl;
  }
};

int main() {
  Account *a1 = new Account();
  Account *a2 = new Checking();
  Account *a3 = new Savings();
  Account *a4 = new Trust();
  Account *accounts[] = { a1, a2, a3, a4 };

  for (const Account *account: accounts)
    DisplayAnyPrintable(*account);

  return 0;
}