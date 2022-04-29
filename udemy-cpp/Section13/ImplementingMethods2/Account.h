#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <string>


class Account {

private:
    std::string name;
    double balance;

public:
    // Implemented inline
    void set_balance(double bal) { balance = bal; }
    double get_balance() { return balance; }

    // Implemented outside the class
    void set_name(std::string);
    std::string get_name();

    bool deposit(double);
    bool withdraw(double);

};


#endif  // __ACCOUNT_H__