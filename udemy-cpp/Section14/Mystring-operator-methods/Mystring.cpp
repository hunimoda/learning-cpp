#include <iostream>
#include <cstring>
#include "Mystring.h"

using std::cout;
using std::endl;
using std::strlen;
using std::strcpy;
using std::strcpy;


Mystring::Mystring()
    : Mystring {""} {}


Mystring::Mystring(const char *str) {
    
    if (str == nullptr) str = "";

    this->str = new char[strlen(str) + 1];
    strcpy(this->str, str);

}


Mystring::Mystring(const Mystring &source)
    : Mystring {source.str} {}


Mystring::~Mystring() {

    delete [] str;

}


Mystring &Mystring::operator=(const Mystring &rhs) {

    cout << "Mystring::operator=(const Mystring &)" << endl;

    if (this == &rhs) return *this;

    return operator=(rhs.str);

}


Mystring &Mystring::operator=(const char *rhs) {

    cout << "Mystring::operator=(const char *): " 
        << rhs << endl;
        
    delete [] this->str;

    this->str = new char[strlen(rhs) + 1];
    strcpy(this->str, rhs);

    return *this;

}


Mystring &Mystring::operator=(Mystring &&rhs) {
    
    cout << "Mystring::operator=(Mystring &&)" << endl;

    if (this == &rhs) return *this;

    delete [] str;

    str = rhs.str;
    rhs.str = nullptr;

    return *this;

}


bool Mystring::operator==(const Mystring &rhs) const {

    return !strcmp(str, rhs.str);

}


Mystring Mystring::operator-() const {

    Mystring lowercase {str};

    for (int i {0}; i < strlen(lowercase.str); ++i) {
        lowercase.str[i] = tolower(lowercase.str[i]);
    }

    return lowercase;

    // char *buffer = new char[strlen(str) + 1];
    // strcpy(buffer, str);

    // for (size_t i {0}; i < strlen(buffer); ++i) {
    //     buffer[i] = tolower(buffer[i]);
    // }

    // delete [] buffer;

    // return Mystring {buffer};

}


Mystring Mystring::operator+(const Mystring &rhs) const {

    char *buffer = new char[strlen(this->str) + strlen(rhs.str) + 1];

    strcpy(buffer, this->str);
    strcat(buffer, rhs.str);

    Mystring concat {buffer};
    delete [] buffer;

    return concat;

}


void Mystring::display() const {

    cout << str << ": " << get_length() << endl;

}


int Mystring::get_length() const {

    return strlen(str);

}


const char *Mystring::get_str() const {

    return str;

}
