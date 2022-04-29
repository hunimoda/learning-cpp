#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <string>


class Player {

private:
    std::string name;
    int health;
    int xp;

public:
    // Constructors
    Player();
    Player(std::string);
    Player(std::string, int, int);

    void set_name(std::string);

    // Destructor
    ~Player();    

};


#endif