#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <string>


class Movie {

private:
    std::string name;
    std::string rating;
    int watched_num;

public:
    // Constructor
    Movie(std::string, std::string, int);

    // Methods
    void increment_watched_num();
    std::string get_name() const;
    void display_info() const;

};


#endif