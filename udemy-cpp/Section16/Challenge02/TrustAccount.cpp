#include <sstream>

#include "TrustAccount.h"

TrustAccount::TrustAccount(std::string name, double balance)
    : Account(name, balance), withdraw_count_(0) {}

std::string TrustAccount::ToString() const {
  std::ostringstream stream;
  stream << Account::ToString() << ", withdrew: "
         << withdraw_count_ << " times";
  return stream.str();
}

bool TrustAccount::Deposit(double amount) {
  return Account::Deposit(amount);
}

bool TrustAccount::Withdraw(double amount) {
  if (withdraw_count_ >= kMaxWithdrawCount ||
      amount > kMaxWithdrawRate * balance_) {
    return false;
  }
  ++withdraw_count_;
  return Account::Withdraw(amount);
}