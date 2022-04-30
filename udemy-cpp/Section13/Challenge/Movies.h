#ifndef _MOVIES_H_
#define _MOVIES_H_

#include <string>
#include <vector>
#include "Movie.h"


class Movies {

private:
    std::vector<Movie> collection;

public:
    bool add_new_movie(std::string, std::string, int);
    bool watch_movie(std::string);
    void display_all() const;

};


#endif