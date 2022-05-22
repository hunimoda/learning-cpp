#ifndef ACCOUNT_UTIL_H_
#define ACCOUNT_UTIL_H_

#include <vector>

#include "Account.h"

// Utility helper functions for Account class
void Display(const std::vector<Account *> &accounts);
void Deposit(std::vector<Account *> &accounts, double amount);
void Withdraw(std::vector<Account *> &accounts, double amount);

#endif  // ACCOUNT_UTIL_H_