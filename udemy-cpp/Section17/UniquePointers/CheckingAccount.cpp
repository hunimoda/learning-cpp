#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(std::string name, double balance)
    : Account{name, balance} {}
  
bool CheckingAccount::Deposit(double amount) {
  return Account::Deposit(amount);
}

bool CheckingAccount::Withdraw(double amount) {
  return Account::Withdraw(amount + kFeePerWithdrawal);
}

void CheckingAccount::Print(std::ostream &os) const {
  os << "[Checking Account: " << name_ << ": " << balance_ << "]";
}