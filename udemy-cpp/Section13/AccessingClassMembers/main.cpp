#include <iostream>
#include <string>

using namespace std;


class Player {

public:
    // Attributes
    string name;
    int health;
    int xp;

    // Methods
    void talk(string);
    bool is_dead();

};


class Account {

public:
    // Attributes
    string name;
    double balance;

    // Methods
    bool deposit(double);
    bool withdraw(double);

};


int main() {

    Account frank_account;

    frank_account.name = "Frank's account";
    frank_account.balance = 5000.0;
    frank_account.deposit(1000.0);
    frank_account.withdraw(500.0);

    Player frank;

    frank.name = "Frank";
    frank.health = 100;
    frank.xp = 12;
    frank.talk("Hi there");

    cout << "------------------------------" << endl;

    Player *enemy = new Player;

    (*enemy).name = "Enemy";
    (*enemy).health = 100;
    enemy->xp = 15;
    enemy->talk("I will destroy you!");

    cout << endl;
    return 0;

}


void Player::talk(string comment) {

    cout << name << " says, \"" << comment << '"' << endl;

}


bool Account::deposit(double amount) {

    balance += amount;
    cout << "In deposit" << endl;

    return true;

}


bool Account::withdraw(double amount) {

    balance -= amount;
    cout << "In withdraw" << endl;

    return true;

}