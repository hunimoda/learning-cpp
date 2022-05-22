#ifndef TRUST_ACCOUNT_H_
#define TRUST_ACCOUNT_H_

#include <string>

#include "SavingsAccount.h"

class TrustAccount : public SavingsAccount {
 public:
  TrustAccount(std::string name = kDefaultName,
               double balance = kDefaultBalance,
               double interest_rate = kDefaultInterestRate);
  virtual ~TrustAccount() = default;
  virtual bool Deposit(double amount) override;
  virtual bool Withdraw(double amount) override;
  virtual void Print(std::ostream &os) const override;

 protected:
  int withdraw_counts_;

 private:
  static constexpr const char *kDefaultName{"Unnamed Trust Account"};
  static constexpr double kDefaultBalance{0.0};
  static constexpr double kDefaultInterestRate{0.0};
  static constexpr double kBonusAmount{50.0};
  static constexpr double kBonusThreshold{5000.0};
  static constexpr int kMaxWithdrawCount{3};
  static constexpr double kMaxWithdrawRatio{0.2};
};

#endif  // TRUST_ACCOUNT_H_