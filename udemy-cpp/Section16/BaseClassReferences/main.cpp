#include <iostream>

class Account {
 public:
  virtual void Withdraw(double amount) {
    std::cout << "Account -= " << amount << std::endl;
  }
};

class Savings : public Account {
 public:
  virtual void Withdraw(double amount) override {
    std::cout << "Savings -= " << amount << std::endl;
  }
};

class Checking : public Account {
 public:
  virtual void Withdraw(double amount) override {
    std::cout << "Checking -= " << amount << std::endl;
  }
};

class Trust : public Account {
 public:
  virtual void Withdraw(double amount) override {
    std::cout << "Trust -= " << amount << std::endl;
  }
};

void DoWithdraw(Account &account, double amount) {
  account.Withdraw(amount);
}

int main() {
  Account a;
  Account &ref1 = a;
  ref1.Withdraw(1000.0);

  Trust t;
  Account &ref2 = t;
  ref2.Withdraw(1000.0);

  Account a1;
  Savings s1;
  Checking c1;
  Trust t1;

  DoWithdraw(a1, 1000.0);
  DoWithdraw(s1, 1000.0);
  DoWithdraw(c1, 1000.0);
  DoWithdraw(t1, 1000.0);

  // Account my_account = t1;
  // my_account.Withdraw(2000.0);

  return 0;
}