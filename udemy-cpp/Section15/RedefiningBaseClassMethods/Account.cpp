#include "Account.h"

std::ostream &operator<<(std::ostream &os, const Account &account) {
  os << "Account balance: " << account.balance_;
  return os;
}

Account::Account() : Account{0.0} {}

Account::Account(double balance) : balance_{balance} {}

void Account::Deposit(double amount) { balance_ += amount; }

void Account::Withdraw(double amount) {
  if (balance_ >= amount) {
    balance_ -= amount;
  } else {
    std::cout << "Insufficient funds" << std::endl;
  }
}
