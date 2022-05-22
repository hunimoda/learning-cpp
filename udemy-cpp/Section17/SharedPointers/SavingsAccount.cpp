#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(std::string name, double balance,
                               double interest_rate)
    : Account{name, balance}, interest_rate_{interest_rate} {}

bool SavingsAccount::Deposit(double amount) {
  return Account::Deposit((1 + interest_rate_ / 100) * amount);
}

bool SavingsAccount::Withdraw(double amount) {
  return Account::Withdraw(amount);
}

void SavingsAccount::Print(std::ostream &os) const {
  os << "[Savings Account: " << name_ << ": " << balance_ << ", "
     << interest_rate_ << "%]";
}