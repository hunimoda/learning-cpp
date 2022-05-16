#include <iostream>

#include "AccountUtil.h"

void Display(const std::vector<Account *> &accounts) {
  std::cout << "\n==== Accounts ==============================" << std::endl;
  for (const Account *account: accounts)
    std::cout << *account << std::endl;
}

void Deposit(std::vector<Account *> &accounts, double amount) {
  std::cout << "\n==== Depositing to Accounts ================" << std::endl;
  for (Account *account: accounts) {
    if (account->Deposit(amount)) {
      std::cout << "Deposited " << amount << " to " << *account << std::endl;
    } else {
      std::cout << "Failed Deposit of " << amount << " to " << *account
                << std::endl;
    }
  }
}

void Withdraw(std::vector<Account *> &accounts, double amount) {
  std::cout << "\n==== Withdrawing from Accounts =============" << std::endl;
  for (Account *account: accounts) {
    if (account->Withdraw(amount)) {
      std::cout << "Withdrew " << amount << " from " << *account << std::endl;
    } else {
      std::cout << "Failed Withdrawal of " << amount << " from " << *account
                << std::endl;
    }
  }
}