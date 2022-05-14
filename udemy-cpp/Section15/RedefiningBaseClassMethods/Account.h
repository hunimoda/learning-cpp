#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <iostream>

class Account {
  friend std::ostream &operator<<(std::ostream &os, const Account &account);

 public:
  Account();
  Account(double balance);
  void Deposit(double amount);
  void Withdraw(double amount);

 protected:
  double balance_;
};

#endif  // ACCOUNT_H_