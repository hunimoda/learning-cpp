#include <iostream>
#include <vector>

using namespace std;


class Move {

private:
    int *data;

public:
    // Constructors
    Move(int);
    Move(const Move &);
    Move(Move &&) noexcept;
    
    // Methods
    void set_data_value(int);
    int get_data_value();

    // Destructor
    ~Move();

};


int main() {

    vector<Move> vec;

    vec.push_back(Move {10});
    vec.push_back(Move {20});
    vec.push_back(Move {30});
    vec.push_back(Move {40});
    vec.push_back(Move {50});
    vec.push_back(Move {60});
    vec.push_back(Move {70});
    vec.push_back(Move {80});

    cout << "----------------------------------------" << endl;

    return 0;

}


Move::Move(int _data) {

    data = new int;
    *data = _data;

    cout << "Created obj: " << data << endl;

}


Move::Move(const Move &src)
    : Move {*src.data} {

    cout << "(copied from " << src.data << " -> " << *src.data << endl;

}


Move::Move(Move &&src) noexcept
    : data {src.data} {

    src.data = nullptr;
    cout << "Moving: " << *data << endl;

}


void Move::set_data_value(int _data) {

    *data = _data;

}


int Move::get_data_value() {

    return *data;

}


Move::~Move() {

    if (data) {
        cout << "Destructor freeing data for: " << data << endl;
    } else {
        cout << "Destructor freeing data for nullptr" << endl;
    }

}