#include <sstream>
#include <iomanip>

#include "Account.h"

Account::Account(std::string name, double balance)
    : name_(name), balance_(balance) {}

std::string Account::ToString() const {
  std::ostringstream stream;
  stream << std::fixed << std::setprecision(2);
  stream << "name: " << name_ << ", balance: " << balance_;
  return stream.str();
}

bool Account::Deposit(double amount) {
  if (amount <= 0) return false;
  balance_ += amount;
  return true;
}

bool Account::Withdraw(double amount) {
  if (balance_ < amount) return false;
  balance_ -= amount;
  return true;
}