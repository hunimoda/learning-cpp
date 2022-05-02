#include <iostream>
#include <cstring>
#include "Mystring.h"

using std::cout;
using std::endl;
using std::strlen;


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

    if (this == &rhs) return *this;

    return operator=(rhs.str);

}


Mystring &Mystring::operator=(const char *str) {

    cout << "Mystring &Mystring::operator=(const char *): " 
        << str << endl;
        
    delete [] this->str;

    this->str = new char[strlen(str) + 1];
    strcpy(this->str, str);

    return *this;

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
