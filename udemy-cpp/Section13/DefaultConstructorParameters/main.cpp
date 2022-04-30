#include <iostream>
#include <string>

using namespace std;


class Player {

private:
    std::string name;
    int health;
    int xp;

public:
    Player(std::string _name = "None", int _health = 0, int _xp = 0);

};


int main() {
    
    Player empty;
    cout << "-----------------------------------" << endl;

    Player frank {"Frank"};
    cout << "-----------------------------------" << endl;

    Player hero {"Hero", 100};
    cout << "-----------------------------------" << endl;

    Player villain {"Villain", 100, 55};

    return 0;

}


Player::Player(std::string _name, int _health, int _xp)
    : name {_name}, health {_health}, xp {_xp} {

    cout << "Player(" << _name << ", " << _health << ", " 
        << _xp << ')' << endl;

}