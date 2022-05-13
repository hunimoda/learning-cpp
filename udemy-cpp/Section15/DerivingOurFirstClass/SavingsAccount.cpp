#include <iostream>
#include "SavingsAccount.h"


SavingsAccount::SavingsAccount() {}


SavingsAccount::~SavingsAccount() {}


void SavingsAccount::Deposit(double amount) {

    std::cout << "Savings Account deposit called with " << amount << std::endl;

}


void SavingsAccount::Withdraw(double amount) {

    std::cout << "Savings Account withdraw called with " << amount << std::endl;

}