#include <iostream>
#include <string>

using namespace std;


class Account {

private:
    string name;
    double balance;

public:
    // Implemented inline
    void set_balance(double bal) { balance = bal; }
    double get_balance() { return balance; }

    // Implemented outside the class
    void set_name(string);
    string get_name();

    bool deposit(double);
    bool withdraw(double);

};


int main() {

    Account frank_account;
    frank_account.set_name("Frank's account");
    frank_account.set_balance(1000.0);

    if (frank_account.deposit(200.0)) {
        cout << "Deposit OK" << endl;
    } else {
        cout << "Deposit not allowed" << endl;
    }

    if (frank_account.withdraw(500.0)) {
        cout << "Withdrawal OK" << endl;
    } else {
        cout << "Not sufficient funds" << endl;
    }

    if (frank_account.withdraw(1500.0)) {
        cout << "Withdrawal OK" << endl;
    } else {
        cout << "Not sufficient funds" << endl;
    }

    cout << endl;
    return 0;

}


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