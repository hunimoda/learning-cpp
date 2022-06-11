#include <iostream>
#include <list>
#include <string>
#include <iomanip>
#include <cctype>

class Song {
 public:
  friend std::ostream &operator<<(std::ostream &os, const Song &song);
  Song(std::string title, std::string artist, int rating)
      : title_(title), artist_(artist), rating_(rating) {}

 private:
  std::string title_;
  std::string artist_;
  int rating_;
};

std::ostream &operator<<(std::ostream &os, const Song &song) {
  os << std::setw(20) << std::left << song.title_
     << std::setw(30) << std::left << song.artist_ << song.rating_;
  return os;
};

void DisplayMenu() {
  std::cout << std::endl;
  std::cout << "F - Play first song" << std::endl;
  std::cout << "N - Play next song" << std::endl;
  std::cout << "P - Play previous song" << std::endl;
  std::cout << "A - Add and play a new song" << std::endl;
  std::cout << "L - List the current playlist" << std::endl;
  std::cout << "==================================================="
            << std::endl;
  std::cout << "Enter a selection (Q to quit): ";
}

char GetChoice() {
  char choice;
  std::cin >> choice;
  return std::toupper(choice);
}

void DisplayCurrentSong(std::list<Song>::iterator &it) {
  std::cout << "Playing:" << std::endl;
  std::cout << *it << std::endl;
}

void PlayFirstSong(std::list<Song> &playlist, std::list<Song>::iterator &it) {
  it = playlist.begin();
  DisplayCurrentSong(it);
}

void PlayNextSong(std::list<Song> &playlist, std::list<Song>::iterator &it) {
  if (++it == playlist.end())
    it = playlist.begin();
  DisplayCurrentSong(it);
}

void PlayPreviousSong(std::list<Song> &playlist,
                      std::list<Song>::iterator &it) {
  if (it == playlist.begin())
    it = playlist.end();
  it--;
  DisplayCurrentSong(it);
}

void AddAndPlayNewSong(std::list<Song> &playlist,
                       std::list<Song>::iterator &it) {
  std::string title, artist;
  int rating;

  std::cout << "[Add New Song]" << std::endl;
  std::cout << "Title:  "; std::cin >> title;
  std::cout << "Artist: "; std::cin >> artist;
  std::cout << "Rating: "; std::cin >> rating;

  playlist.emplace(it, title, artist, rating);
  PlayPreviousSong(playlist, it);
}

void ListCurrentPlaylist(std::list<Song> &playlist,
                         std::list<Song>::iterator &it) {
  for (const Song &song : playlist)
    std::cout << song << std::endl;
  std::cout << std::endl;
  DisplayCurrentSong(it);
}

void UnknownChoice() {
  std::cout << "Sorry, unknown option. Try again!" << std::endl;
}

void DisplaySeparator() {
  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
            << std::endl;
}

void Quit() {
  std::cout << "See you again!" << std::endl;
  exit(0);
}

int main() {
  std::list<Song> playlist = {
      {"God's Plan", "Drake", 5},
      {"Never Be The Same", "Camila Cabello", 5},
      {"Pray For Me", "The Weekend and K. Lamar", 4},
      {"The Middle", "Zedd, Maren Morris & Grey", 5},
      {"Wait", "Maroon 5", 4},
      {"Whatever It Takes", "Imagine Dragons", 3}};
  auto current_song = playlist.begin();

  while (true) {
    DisplayMenu();
    char choice = GetChoice();
    std::cout << std::endl;
    DisplaySeparator();

    switch (choice) {
      case 'F': PlayFirstSong(playlist, current_song); break;
      case 'N': PlayNextSong(playlist, current_song); break;
      case 'P': PlayPreviousSong(playlist, current_song); break;
      case 'A': AddAndPlayNewSong(playlist, current_song); break;
      case 'L': ListCurrentPlaylist(playlist, current_song); break;
      case 'Q': Quit();
      default: UnknownChoice();
    }
    DisplaySeparator();
  }

  return 0;
}