#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>


class Player {

private:
    static int num_players;

    std::string name;
    int health;
    int xp;

public:
    static int get_num_players();

    std::string get_name() const;
    int get_health() const;
    int get_xp() const;

    Player(std::string name = "None", int health = 0, int xp = 0);
    Player(const Player &);
    ~Player();

};


#endif  // _PLAYER_H_