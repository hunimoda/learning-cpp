#include <iostream>
#include "Movie.h"

using std::cout;
using std::endl;


Movie::Movie(std::string name, std::string rating, int watched_num)
    : name {name}, rating {rating}, watched_num {watched_num} {}


void Movie::increment_watched_num() {

    watched_num++;

}


std::string Movie::get_name() const {

    return name;

}


void Movie::display_info() const {

    cout << "{ name: " << name << ", rating: " << rating
        << ", watched: " << watched_num << " }" << endl;

}