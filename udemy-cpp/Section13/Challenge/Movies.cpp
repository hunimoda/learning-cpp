#include <iostream>
#include "Movies.h"

using std::cout;
using std::endl;


// Returns -1 if movie wasn't found by name
int get_movie_index_by_name(const std::vector<Movie> &collection, std::string name) {

    for (int i {0}; i < collection.size(); ++i) {
        if (collection.at(i).get_name() == name) {
            return i;
        }
    }

    return -1;

}


// Returns true if movie exists in collection, false otherwise
bool movie_exists(const std::vector<Movie> &collection, std::string name) {

    return (get_movie_index_by_name(collection, name) != -1);

}


// Add movie if it doesn't exist in collection
bool Movies::add_new_movie(std::string name, std::string rating, int watched_num) {

    if (movie_exists(collection, name)) {
        return false;
    } else {
        collection.push_back(Movie {name, rating, watched_num});
        return true;
    }

}


// Increment watch_num if movie exists
bool Movies::watch_movie(std::string name) {

    int movie_idx {};
    movie_idx = get_movie_index_by_name(collection, name);

    if (movie_idx != -1) {
        collection.at(movie_idx).increment_watched_num();
        return true;
    }

    return false;

}


void Movies::display_all() const {

    if (collection.size() <= 0) {
        cout << "No movies were found" << endl;
    } else {
        cout << "---------- Collection --------------------" << endl;

        for (const Movie &movie: collection) {
            movie.display_info();
        }

        cout << "------------------------------------------" << endl;
    }

}