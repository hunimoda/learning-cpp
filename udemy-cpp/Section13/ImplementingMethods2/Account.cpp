#include "Account.h"

using std::string;


void Account::set_name(string _name) {

    name = _name;

}


string Account::get_name() {

    return name;

}


bool Account::deposit(double amount) {

    balance += amount;
    return true;

}


bool Account::withdraw(double amount) {

    if (amount > balance) {
        return false;
    }

    balance -= amount;
    return true;

}