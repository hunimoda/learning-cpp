#include <iostream>
#include "SavingsAccount.h"

int main() {
  std::cout << "\n===== Account class ========================" << std::endl;
  Account a1{1000.0};
  std::cout << a1 << std::endl;

  a1.Deposit(500.0);
  std::cout << a1 << std::endl;

  a1.Withdraw(1000.0);
  std::cout << a1 << std::endl;
  a1.Withdraw(5000.0);
  std::cout << a1 << std::endl;

  std::cout << "\n===== SavingsAccount class =================" << std::endl;
  SavingsAccount s1{1000.0, 5.0};
  std::cout << s1 << std::endl;

  s1.Deposit(1000.0);
  std::cout << s1 << std::endl;

  s1.Withdraw(2000.0);
  std::cout << s1 << std::endl;
  s1.Withdraw(1000.0);
  std::cout << s1 << std::endl;

  std::cout << "\n============================================" << std::endl;
  return 0;
}