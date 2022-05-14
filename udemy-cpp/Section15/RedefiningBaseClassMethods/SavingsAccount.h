#ifndef SAVINGS_ACCOUNT_H_
#define SAVINGS_ACCOUNT_H_

#include "Account.h"

class SavingsAccount : public Account {
  friend std::ostream &operator<<(std::ostream &os,
                                  const SavingsAccount &account);
 public:
  SavingsAccount();
  SavingsAccount(double balance, double int_rate);
  void Deposit(double amount);

 protected:
  double int_rate_;
};

#endif  // SAVINGS_ACCOUNT_H_