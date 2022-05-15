#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(std::string name, double balance,
                               double interest_rate)
    : Account{name, balance}, interest_rate_{interest_rate} {}

bool SavingsAccount::Deposit(double amount) {
  return Account::Deposit((1 + interest_rate_ / 100) * amount);
}

std::ostream &operator<<(std::ostream &os, const SavingsAccount &account) {
  return os << "[SavingsAccount: " << account.name_ << ": " << account.balance_
            << ", " << account.interest_rate_ << "%]";
}