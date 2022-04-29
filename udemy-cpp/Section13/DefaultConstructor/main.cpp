#include <iostream>
#include <string>

using namespace std;


class Player {

private:
    std::string name;
    int health;
    int xp;

public:
    //Player() {
        //name = "None";
        //health = 100;
        //xp = 3;
    //}
    Player(std::string _name, int _health, int _xp) {
        name = _name;
        health = _health;
        xp = _xp;
    }
    void set_name(std::string _name) { name = _name; }
    std::string get_name() { return name; }
    
};


int main() {

    //Player frank;
    Player frank("Frank", 100, 13);

    frank.set_name("Frank");
    cout << frank.get_name() << endl;

    return 0;

}