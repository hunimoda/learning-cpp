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


bool operator==(const Mystring &lhs, const Mystring &rhs) {

    return !strcmp(lhs.str, rhs.str);

}


Mystring operator-(const Mystring &obj) {

    char *buffer = new char[strlen(obj.str) + 1];
    strcpy(buffer, obj.str);

    for (size_t i {0}; i < strlen(buffer); ++i) {
        buffer[i] = tolower(buffer[i]);
    }

    Mystring lowercase {buffer};
    delete [] buffer;

    return lowercase;

}


Mystring operator+(const Mystring &lhs, const Mystring &rhs) {

    const size_t new_string_len = 
            strlen(lhs.str) + strlen(rhs.str) + 1;
    char *buffer = new char[new_string_len];

    strcpy(buffer, lhs.str);
    strcat(buffer, rhs.str);

    Mystring concat {buffer};
    delete [] buffer;

    return concat;

}


std::ostream &operator<<(std::ostream &os, const Mystring &obj) {

    os << obj.str;

    return os;

}


std::istream &operator>>(std::istream &is, Mystring &obj) {

    char *buffer = new char[1024];
    is >> buffer;

    obj = Mystring {buffer};
    delete [] buffer;

    return is;

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
