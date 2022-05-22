#ifndef CHECKING_ACCOUNT_H_
#define CHECKING_ACCOUNT_H_

#include <string>

#include "Account.h"

class CheckingAccount : public Account {
 public:
  CheckingAccount(std::string name = kDefaultName,
                  double balance = kDefaultBalance);
  virtual ~CheckingAccount() = default;
  virtual bool Deposit(double amount) override;
  virtual bool Withdraw(double amount) override;
  virtual void Print(std::ostream &os) const override;

 private:
  static constexpr const char *kDefaultName{"Unnamed Checking Account"};
  static constexpr double kDefaultBalance{0.0};
  static constexpr double kFeePerWithdrawal{1.5};
};

#endif  // CHECKING_ACCOUNT_H_