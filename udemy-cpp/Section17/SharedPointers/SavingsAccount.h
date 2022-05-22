#ifndef SAVINGS_ACCOUNT_H_
#define SAVINGS_ACCOUNT_H_

#include "Account.h"

class SavingsAccount : public Account {
 public:
  SavingsAccount(std::string name = kDefaultName,
                 double balance = kDefaultBalance,
                 double interest_rate = kDefaultInterestRate);
  virtual ~SavingsAccount() = default;
  virtual bool Deposit(double amount) override;
  virtual bool Withdraw(double amount) override;
  virtual void Print(std::ostream &os) const override;

 protected:
  double interest_rate_;

 private:
  static constexpr const char *kDefaultName{"Unnamed Savings Account"};
  static constexpr double kDefaultBalance{0.0};
  static constexpr double kDefaultInterestRate{0.0};
};

#endif  // SAVINGS_ACCOUNT_H_