#include <iomanip>
#include <sstream>

#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(std::string name, double balance,
                               double interest_rate)
    : Account(name, balance), interest_rate_(interest_rate) {}

std::string SavingsAccount::ToString() const {
  std::ostringstream stream;
  stream << std::fixed << std::setprecision(2);
  stream << Account::ToString() << ", interest rate: "
         << 100 * interest_rate_ << "%";
  return stream.str();
}

bool SavingsAccount::Deposit(double amount) {
  return Account::Deposit((1 + interest_rate_) * amount);
}

bool SavingsAccount::Withdraw(double amount) {
  return Account::Withdraw(amount);
}