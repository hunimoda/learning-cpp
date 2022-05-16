#ifndef TRUST_ACCOUNT_H_
#define TRUST_ACCOUNT_H_

#include "Account.h"

class TrustAccount : public Account {
 public:
  TrustAccount(std::string name, double balance);
  virtual ~TrustAccount() = default;

  virtual std::string ToString() const override;
  virtual bool Deposit(double amount) override;
  virtual bool Withdraw(double amount) override;

 protected:
  unsigned int withdraw_count_;

 private:
  static constexpr double kMaxWithdrawRate = 0.20;
  static constexpr unsigned int kMaxWithdrawCount = 3;
};

#endif