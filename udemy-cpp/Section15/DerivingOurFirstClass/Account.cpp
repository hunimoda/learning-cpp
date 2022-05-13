#include <iostream>
#include "Account.h"


Account::Account() {}


Account::~Account() {}


void Account::Deposit(double amount) {

    std::cout << "Account deposit called with " << amount << std::endl;

}


void Account::Withdraw(double amount) {

    std::cout << "Account withdraw called with " << amount << std::endl;

}