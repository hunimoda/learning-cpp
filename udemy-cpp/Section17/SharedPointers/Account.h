#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <iostream>
#include <string>

#include "IPrintable.h"

class Account : public IPrintable {
 public:
  Account(std::string name = kDefaultName, double balance = kDefaultBalance);
  virtual ~Account() = default;

  virtual bool Deposit(double amount) = 0;
  virtual bool Withdraw(double amount) = 0;

  double GetBalance() const;

 protected:
  std::string name_;
  double balance_;

 private:
  static constexpr const char *kDefaultName{"Unnamed Account"};
  static constexpr double kDefaultBalance{0.0};
};

#endif  // ACCOUNT_H_