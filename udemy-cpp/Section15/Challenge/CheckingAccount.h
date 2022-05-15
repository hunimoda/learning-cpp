#ifndef CHECKING_ACCOUNT_H_
#define CHECKING_ACCOUNT_H_

#include <string>

#include "Account.h"

class CheckingAccount : public Account {
 public:
  CheckingAccount(std::string name = kDefaultName,
                  double balance = kDefaultBalance);
  bool Withdraw(double amount);

 private:
  static constexpr const char *kDefaultName{"Unnamed Checking Account"};
  static constexpr double kDefaultBalance{0.0};
  static constexpr double kFeePerWithdrawal{1.5};
  friend std::ostream &operator<<(std::ostream &os,
                                  const CheckingAccount &account);
};

#endif  // CHECKING_ACCOUNT_H_