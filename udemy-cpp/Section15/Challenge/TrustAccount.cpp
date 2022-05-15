#include "TrustAccount.h"

TrustAccount::TrustAccount(std::string name, double balance,
                           double interest_rate)
    : SavingsAccount{name, balance, interest_rate}, withdraw_counts_{0} {}

bool TrustAccount::Deposit(double amount) {
  if (amount >= kBonusThreshold)
    amount += kBonusAmount;
  return SavingsAccount::Deposit(amount);
}

bool TrustAccount::Withdraw(double amount) {
  if (withdraw_counts_ >= kMaxWithdrawCount || 
      amount >= kMaxWithdrawRatio * balance_) {
    return false;
  }
  ++withdraw_counts_;
  return SavingsAccount::Withdraw(amount);
}

std::ostream &operator<<(std::ostream &os, const TrustAccount &account) {
  return os << "[Trust Account: " << account.name_ << ": "
            << account.balance_ << ", " << account.interest_rate_
            << "%, withdrawals: " << account.withdraw_counts_ << "]";
}