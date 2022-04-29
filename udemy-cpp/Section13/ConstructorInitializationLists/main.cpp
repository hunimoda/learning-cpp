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

    Player empty;
    Player frank {"Frank"};
    Player villain {"Villain", 100, 55};

    return 0;

}


Player::Player()
    : name {"None"}, health {0}, xp {0} {}


Player::Player(std::string _name)
    : name {_name}, health {0}, xp {0} {}


Player::Player(std::string _name, int _health, int _xp)
    : name {_name}, health {_health}, xp {_xp} {}