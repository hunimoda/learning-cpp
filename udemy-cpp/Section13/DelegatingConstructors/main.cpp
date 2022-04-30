#include <iostream>
#include <string>

using namespace std;


class Player {

private:
    std::string name;
    int health;
    int xp;

public:
    Player();
    Player(std::string);
    Player(std::string, int, int);

};


int main() {
    
    Player hero;
    cout << "-----------------------------------" << endl;

    Player frank {"Frank"};
    cout << "-----------------------------------" << endl;

    Player villain {"Villain", 100, 55};

    return 0;

}


Player::Player(std::string _name, int _health, int _xp)
    : name {_name}, health {_health}, xp {_xp} {

    cout << "Player(" << _name << ", " << _health << ", " 
        << _xp << ')' << endl;

}


Player::Player()
    : Player {"None", 0, 0} {

    cout << "Player()" << endl;

}


Player::Player(std::string _name)
    : Player {_name, 0, 0} {

    cout << "Player(" << _name << ')' << endl;

}