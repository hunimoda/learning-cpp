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

void TrustAccount::Print(std::ostream &os) const {
  os << "[Trust Account: " << name_ << ": " << balance_ << ", withdraw counts: "
     << withdraw_counts_ << " times]";
}