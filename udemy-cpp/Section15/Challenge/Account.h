#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <iostream>
#include <string>

class Account {
 public:
  Account(std::string name = kDefaultName, double balance = kDefaultBalance);
  bool Deposit(double amount);
  bool Withdraw(double amount);
  double GetBalance() const;

 protected:
  std::string name_;
  double balance_;

 private:
  static constexpr const char *kDefaultName{"Unnamed Account"};
  static constexpr double kDefaultBalance{0.0};
  friend std::ostream &operator<<(std::ostream &os, const Account &account);
};

#endif  // ACCOUNT_H_