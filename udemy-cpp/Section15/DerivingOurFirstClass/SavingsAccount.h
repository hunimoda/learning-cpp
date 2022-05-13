#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_

#include "Account.h"


class SavingsAccount: public Account {

public:
    SavingsAccount();
    ~SavingsAccount();
    void Deposit(double);
    void Withdraw(double);

};


#endif