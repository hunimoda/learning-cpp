#include "Player.h"

int Player::num_players {0};


// Static
int Player::get_num_players() {

    return num_players;

}


std::string Player::get_name() const {

    return name;
}


int Player::get_health() const {

    return health;

}


int Player::get_xp() const {

    return xp;

}


Player::Player(std::string name, int health, int xp)
    : name {name}, health {health}, xp {xp} {

    ++num_players;

}


Player::Player(const Player &src)
    : Player {src.name, src.health, src.xp} {}


Player::~Player() {

    --num_players;

}