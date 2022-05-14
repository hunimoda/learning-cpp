#include "SavingsAccount.h"

std::ostream &operator<<(std::ostream &os, const SavingsAccount &account) {
  os << "Savings account balance: " << account.balance_ << 
        ", Interest rate: " << account.int_rate_;
  return os;
}
SavingsAccount::SavingsAccount() : SavingsAccount{0.0, 0.0} {}

SavingsAccount::SavingsAccount(double balance, double int_rate)
    : Account{balance}, int_rate_{int_rate} {}

void SavingsAccount::Deposit(double amount) {
  amount += amount * int_rate_ / 100;
  Account::Deposit(amount);
}