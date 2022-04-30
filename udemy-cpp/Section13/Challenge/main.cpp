#include <iostream>
#include <string>
#include "Movies.h"

using namespace std;

void display_menu();
void display_farewell();
char get_choice();

void handle_add_movie(Movies &);
void handle_display_movie(const Movies &);
void handle_watch_movie(Movies &);
void handle_unknown(char);


int main() {

    Movies movies;
    char choice {};

    do {

        display_menu();
        choice = get_choice();

        cout << "*******************************" << endl;

        switch (choice) {
            case 'A': handle_add_movie(movies); break;
            case 'D': handle_display_movie(movies); break;
            case 'W': handle_watch_movie(movies); break;
            case 'Q': display_farewell(); break;
            default : handle_unknown(choice);
        }

    } while (choice != 'Q');

    return 0;

}


void display_menu() {

    cout << "***** MENU ********************" << endl;
    cout << "  A. Add a new movie" << endl;
    cout << "  D. Display collection" << endl;
    cout << "  W. Watch a movie" << endl;
    cout << "  Q. Quit" << endl;
    cout << "*******************************" << endl;
    cout << " Your choice: ";

}


void display_farewell() {

    cout << "** Good Bye" << endl;

}


char get_choice() {

    char choice {};
    cin >> choice;

    return toupper(choice);

}


void handle_add_movie(Movies &movies) {
    
    string name {};
    string rating {};
    int watch_num {};

    cout << "Enter name, rating, watch_num: ";
    cin >> name >> rating >> watch_num;

    if (movies.add_new_movie(name, rating, watch_num)) {
        cout << "\n>> Movie '" << name << "' was added successfully!" << endl;
    } else {
        cout << "\n>> Movie '" << name << "' already exists!" << endl;
    }

}


void handle_display_movie(const Movies &movies) {

    movies.display_all();

}


void handle_watch_movie(Movies &movies) {

    string name {};
    cout << "Enter name: ";
    cin >> name;

    if (movies.watch_movie(name)) {
        cout << "\n>> You've watched '" << name << "'" << endl;
    } else {
        cout << "\n>> Movie '" << name << "' doesn't exist!" << endl;
    }

}


void handle_unknown(char choice) {

    cout << "\n[!!] Unknown option '" << choice << "'! Try again..." << endl;

}