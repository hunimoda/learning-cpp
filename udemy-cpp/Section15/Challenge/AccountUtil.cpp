#include <iostream>

#include "AccountUtil.h"

void Display(const std::vector<Account> &accounts) {
  std::cout << "\n==== Accounts ==============================" << std::endl;
  for (const Account &account: accounts)
    std::cout << account << std::endl;
}

void Deposit(std::vector<Account> &accounts, double amount) {
  std::cout << "\n==== Depositing to Accounts ================" << std::endl;
  for (Account &account: accounts) {
    if (account.Deposit(amount)) {
      std::cout << "Deposited " << amount << " to " << account << std::endl;
    } else {
      std::cout << "Failed Deposit of " << amount << " to " << account
                << std::endl;
    }
  }
}

void Withdraw(std::vector<Account> &accounts, double amount) {
  std::cout << "\n==== Withdrawing from Accounts =============" << std::endl;
  for (Account &account: accounts) {
    if (account.Withdraw(amount)) {
      std::cout << "Withdrew " << amount << " from " << account << std::endl;
    } else {
      std::cout << "Failed Withdrawal of " << amount << " from " << account
                << std::endl;
    }
  }
}

void Display(const std::vector<SavingsAccount> &accounts) {
  std::cout << "\n==== Savings Account =======================" << std::endl;
  for (const SavingsAccount &account: accounts)
    std::cout << account << std::endl;
}

void Deposit(std::vector<SavingsAccount> &accounts, double amount) {
  std::cout << "\n==== Depositing to Savings Accounts ========" << std::endl;
  for (SavingsAccount &account: accounts) {
    if (account.Deposit(amount)) {
      std::cout << "Deposited " << amount << " to " << account << std::endl;
    } else {
      std::cout << "Failed Deposit of " << amount << " to " << account
                << std::endl;
    }
  }
}

void Withdraw(std::vector<SavingsAccount> &accounts, double amount) {
  std::cout << "\n==== Withdrawing from Savings Accounts =====" << std::endl;
  for (SavingsAccount &account: accounts) {
    if (account.Withdraw(amount)) {
      std::cout << "Withdrew " << amount << " from " << account << std::endl;
    } else {
      std::cout << "Failed Withdrawal of " << amount << " from " << account
                << std::endl;
    }
  }
}

void Display(const std::vector<CheckingAccount> &accounts) {
  std::cout << "\n==== Checking Account ======================" << std::endl;
  for (const CheckingAccount &account: accounts)
    std::cout << account << std::endl;
}

void Deposit(std::vector<CheckingAccount> &accounts, double amount) {
  std::cout << "\n==== Depositing to Checking Accounts =======" << std::endl;
  for (CheckingAccount &account: accounts) {
    if (account.Deposit(amount)) {
      std::cout << "Deposited " << amount << " to " << account << std::endl;
    } else {
      std::cout << "Failed Deposit of " << amount << " to " << account
                << std::endl;
    }
  }
}

void Withdraw(std::vector<CheckingAccount> &accounts, double amount) {
  std::cout << "\n==== Withdrawing from Checking Accounts ====" << std::endl;
  for (CheckingAccount &account: accounts) {
    if (account.Withdraw(amount)) {
      std::cout << "Withdrew " << amount << " from " << account << std::endl;
    } else {
      std::cout << "Failed Withdrawal of " << amount << " from " << account
                << std::endl;
    }
  }
}

void Display(const std::vector<TrustAccount> &accounts) {
  std::cout << "\n==== Trust Account =========================" << std::endl;
  for (const TrustAccount &account: accounts)
    std::cout << account << std::endl;
}

void Deposit(std::vector<TrustAccount> &accounts, double amount) {
  std::cout << "\n==== Depositing to Trust Accounts ==========" << std::endl;
  for (TrustAccount &account: accounts) {
    if (account.Deposit(amount)) {
      std::cout << "Deposited " << amount << " to " << account << std::endl;
    } else {
      std::cout << "Failed Deposit of " << amount << " to " << account
                << std::endl;
    }
  }
}

void Withdraw(std::vector<TrustAccount> &accounts, double amount) {
  std::cout << "\n==== Withdrawing from Trust Accounts =======" << std::endl;
  for (TrustAccount &account: accounts) {
    if (account.Withdraw(amount)) {
      std::cout << "Withdrew " << amount << " from " << account << std::endl;
    } else {
      std::cout << "Failed Withdrawal of " << amount << " from " << account
                << std::endl;
    }
  }
}