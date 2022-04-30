#include <iostream>
#include <string>

using namespace std;


class Player {

private:
    std::string name;
    int health;
    int xp;

public:
    std::string get_name() const;
    void set_name(std::string);

    Player();
    Player(std::string);
    Player(std::string, int, int);

};


void display_player_name(const Player &p) {

    cout << p.get_name() << endl;

}


int main() {

    const Player villain {"Villain", 100, 55};
    Player hero {"Hero", 100, 15};

    cout << villain.get_name() << endl;
    cout << hero.get_name() << endl;
    
    display_player_name(villain);
    display_player_name(hero);

    return 0;

}


Player::Player()
    : Player {"None", 0, 0} {}


Player::Player(std::string name)
    : Player {name, 0, 0} {}


Player::Player(std::string name, int health, int xp)
    : name {name}, health {health}, xp {xp} {}


std::string Player::get_name() const {

    return name;

}


void Player::set_name(std::string name) {

    this->name = name;

}