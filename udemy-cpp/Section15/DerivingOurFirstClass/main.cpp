#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"


int main() {

    std::cout << "\n=== Account =========================" << std::endl;
    Account acc {};
    acc.Deposit(2000.0);
    acc.Withdraw(500.0);

    std::cout << std::endl;

    Account *p_acc { nullptr };
    p_acc = new Account();
    p_acc->Deposit(1000.0);
    p_acc->Withdraw(500.0);
    delete p_acc;

    std::cout << "\n=== Savings Account =================" << std::endl;
    SavingsAccount sav_acc {};
    sav_acc.Deposit(2000.0);
    sav_acc.Withdraw(500.0);

    std::cout << std::endl;

    SavingsAccount *p_sav_acc { nullptr };
    p_sav_acc = new SavingsAccount();
    p_sav_acc->Deposit(1000.0);
    p_sav_acc->Withdraw(500.0);
    delete p_sav_acc;

    std::cout << "\n=====================================" << std::endl;

    return 0;

}