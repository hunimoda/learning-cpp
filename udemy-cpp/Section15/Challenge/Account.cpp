#include "Account.h"

Account::Account(std::string name, double balance)
    : name_{name}, balance_{balance} {}

bool Account::Deposit(double amount) {
  if (amount < 0) return false;
  balance_ += amount;
  return true;
}

bool Account::Withdraw(double amount) {
  if (amount > balance_) return false;
  balance_ -= amount;
  return true;
}

double Account::GetBalance() const { return balance_; }

std::ostream &operator<<(std::ostream &os, const Account &account) {
  return os << "[Account: " << account.name_ << ": " << account.balance_ << "]";
}