#ifndef SAVINGS_ACCOUNT_H_
#define SAVINGS_ACCOUNT_H_

#include "Account.h"

class SavingsAccount : public Account {
 public:
  SavingsAccount(std::string name, double balance, double interest_rate);
  virtual ~SavingsAccount() = default;

  virtual std::string ToString() const override;
  virtual bool Deposit(double amount) override;
  virtual bool Withdraw(double amount) override;

 protected:
  double interest_rate_;
};

#endif  // SAVINGS_ACCOUNT_H_