#include <iostream>
#include <memory>

#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "TrustAccount.h"
#include "AccountUtil.h"

int main() {
  Account *ptr = new TrustAccount("Leo", 10'000.0, 2.6);
  std::cout << *ptr << std::endl;
  ptr->Withdraw(500.0);
  std::cout << *ptr << std::endl;
  ptr->Withdraw(600.0);
  std::cout << *ptr << std::endl;
  ptr->Withdraw(1000.0);
  std::cout << *ptr << std::endl;
  tr->Withdraw(1000.0);
  std::cout << *ptr << std::endl;

  return 0;
}