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

  // // Accounts
  // std::vector<Account> accounts;
  // accounts.push_back(Account{});
  // accounts.push_back(Account{"Larry"});
  // accounts.push_back(Account{"Moe", 2000.0});
  // accounts.push_back(Account{"Curly", 5000.0});

  // Display(accounts);
  // Deposit(accounts, 1000.0);
  // Withdraw(accounts, 2000.0);

  std::vector<Account *> accounts;
  accounts.push_back(new SavingsAccount{});
  accounts.push_back(new SavingsAccount{"Superman"});
  accounts.push_back(new SavingsAccount{"Batman", 2000.0});
  accounts.push_back(new SavingsAccount{"Wonderwoman", 5000.0, 5.0});

  Display(accounts);
  Deposit(accounts, 1000.0);
  Withdraw(accounts, 2000.0);

  accounts.push_back(new CheckingAccount{});
  accounts.push_back(new CheckingAccount{"Kirk"});
  accounts.push_back(new CheckingAccount{"Spock", 2000.0});
  accounts.push_back(new CheckingAccount{"Bones", 5000.0});

  Display(accounts);
  Deposit(accounts, 1000.0);
  Withdraw(accounts, 2000.0);

  accounts.push_back(new TrustAccount{});
  accounts.push_back(new TrustAccount{"Athos", 10000.0, 5.0});
  accounts.push_back(new TrustAccount{"Porthos", 20000.0, 4.0});
  accounts.push_back(new TrustAccount{"Aramis", 30000.0});

  Display(accounts);
  Deposit(accounts, 1000.0);

  for (int i = 0; i < 4; i++)
    Withdraw(accounts, 1000.0);

  return 0;
}