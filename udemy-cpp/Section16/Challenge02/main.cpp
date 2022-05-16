#include "TrustAccount.h"

int main() {
  TrustAccount t{"Hunimoda", 5000.0};
  std::cout << t << std::endl;
  t.Deposit(10000.0);
  std::cout << t << std::endl;
  t.Withdraw(4000.0);
  std::cout << t << std::endl;
  return 0;
}