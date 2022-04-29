#include <iostream>
#include <string>

using namespace std;


class Player {

private:
    string name {"Player"};
    int health;
    int xp;

public:
    void talk(string);
    bool is_dead();

};

int main() {

    Player frank;
    //cout << frank.name << endl;
    //frank.name = "Frank";

    frank.talk("Hello there!");

    cout << endl;
    return 0;

}

void Player::talk(string text_to_say) {

    cout << name << " says, \"" << text_to_say << '"' << endl;

}


bool Player::is_dead() {

    return health <= 0;

}