#include <iostream>
#include <vector>

#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"
#include "AccountUtil.h"

int main() {
  std::cout.precision(2);
  std::cout << std::fixed;

  // Accounts
  std::vector<Account> accounts;
  accounts.push_back(Account{});
  accounts.push_back(Account{"Larry"});
  accounts.push_back(Account{"Moe", 2000.0});
  accounts.push_back(Account{"Curly", 5000.0});

  Display(accounts);
  Deposit(accounts, 1000.0);
  Withdraw(accounts, 2000.0);

  // Savings
  std::vector<SavingsAccount> savings_accounts;
  savings_accounts.push_back(SavingsAccount{});
  savings_accounts.push_back(SavingsAccount{"Superman"});
  savings_accounts.push_back(SavingsAccount{"Batman", 2000.0});
  savings_accounts.push_back(SavingsAccount{"Wonderwoman", 5000.0, 5.0});

  Display(savings_accounts);
  Deposit(savings_accounts, 1000.0);
  Withdraw(savings_accounts, 2000.0);

  // Checking
  std::vector<CheckingAccount> checking_accounts;
  checking_accounts.push_back(CheckingAccount{});
  checking_accounts.push_back(CheckingAccount{"Krik"});
  checking_accounts.push_back(CheckingAccount{"Spock", 2000.0});
  checking_accounts.push_back(CheckingAccount{"Bones", 5000.0});

  Display(checking_accounts);
  Deposit(checking_accounts, 1000.0);
  Withdraw(checking_accounts, 2000.0);

  // Trust
  std::vector<TrustAccount> trust_accounts;
  trust_accounts.push_back(TrustAccount{});
  trust_accounts.push_back(TrustAccount{"Athos", 10000.0, 5.0});
  trust_accounts.push_back(TrustAccount{"Porthos", 20000.0, 4.0});
  trust_accounts.push_back(TrustAccount{"Aramis", 30000.0});

  Display(trust_accounts);
  Deposit(trust_accounts, 1000.0);
  Withdraw(trust_accounts, 2000.0);

  for (size_t i{0}; i < 5; i++)
    Withdraw(trust_accounts, 1000.0);

  return 0;
}