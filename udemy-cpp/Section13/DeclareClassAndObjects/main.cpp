#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player {

    // Attributes
    string name;
    int health;
    int xp;

    // Methods
    void talk(string);
    bool is_dead();

};

class Account {

    // Attributes
    string name;
    double balance;

    // Methods
    bool deposit(double);
    bool withdraw(double);

};

int main() {

    Account frank_account;
    Account jim_account;

    Player frank;
    Player hero;

    //cout << frank.name << endl;
    //cout << frank.health << endl;
    //cout << frank.xp << endl;

    Player players[] {frank, hero};
    vector<Player> player_vec {frank};
    
    cout << player_vec.size() << endl;
    player_vec.push_back(hero);
    cout << player_vec.size() << endl;
    
    Player *enemy {nullptr};
    enemy = new Player;

    delete enemy;

    cout << endl;
    return 0;

}