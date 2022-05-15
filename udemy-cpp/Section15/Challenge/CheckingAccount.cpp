#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(std::string name, double balance)
    : Account{name, balance} {}
  
bool CheckingAccount::Withdraw(double amount) {
  return Account::Withdraw(amount + kFeePerWithdrawal);
}

std::ostream &operator<<(std::ostream &os, const CheckingAccount &account) {
  return os << "[CheckingAccount: " << account.name_ << ": "
            << account.balance_ << "]";
}