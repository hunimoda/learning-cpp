#include <iostream>
#include <string>

using namespace std;


class Player {

private:
    std::string name;
    int health;
    int xp;

public:
    // Constructor
    Player(std::string _name = "None", int _health = 0, int _xp = 0);

    // Copy constructor
    Player(const Player &);
    
    // Methods
    std::string get_name();
    int get_health();
    int get_xp();

    // Destructor
    ~Player();

};


void display_player(Player p) {

    cout << "Name: " << p.get_name() << endl;
    cout << "Health: " << p.get_health() << endl;
    cout << "XP: " << p.get_xp() << endl;

}


int main() {

    Player empty {"xxxxx", 100, 50};
    Player my_new_object {empty};

    display_player(empty);

    Player frank {"Frank"};
    Player hero {"Hero", 100};
    Player villain {"Villain", 100, 55};

    cout << endl;
    return 0;

}


Player::Player(std::string _name, int _health, int _xp)
    :   name {_name}, health {_health}, xp {_xp} {
}


//Player::Player(const Player &src)
//    : name {src.name}, health {src.health}, xp {src.xp} {
//                              
//    cout << "Copy constructor - made copy of " << src.name << endl;
//
//}
Player::Player(const Player &src)
    : Player {src.name, src.health, src.xp } {

    cout << "Copy constructor - made copy of " << src.name << endl;

}


std::string Player::get_name() {

    return name;

}


int Player::get_health() {

    return health;

}


int Player::get_xp() {

    return xp;

}


Player::~Player() {

    cout << "Destructor called for: " << name << endl;

}