#include <iostream>
#include "Player.h"

using namespace std;


Player::Player() {

    cout << "Player()" << endl;

}


Player::Player(std::string name) {

    cout << "Player(string)" << endl;
}


Player::Player(std::string name, int health, int xp) {

    cout << "Player(string, int, int)" << endl;

}


void Player::set_name(std::string _name) {

    name = _name;

}


Player::~Player() {

    cout << "~Player() for " << name << endl;

}