#include <iostream>
#include <cstring>
#include "Mystring.h"


// Stream insertion operator overloading as non-member function
std::ostream &operator<<(std::ostream &os, const Mystring &obj) {

    os << obj.str;
    return os;

}


// Constructor
Mystring::Mystring()
    : Mystring {""} {}


Mystring::Mystring(const char *str) {

    std::cout << "Constructor Mystring(const char *) called for: "
            << str << std::endl;

    this->str = new char[std::strlen(str) + 1];
    std::strcpy(this->str, str);

}


// Copy constructor
Mystring::Mystring(const Mystring &source)
    : Mystring {source.str} {

    std::cout << "Copy constructor body after delegated constructor" << std::endl;

}


// Destructor
Mystring::~Mystring() {

    if (str == nullptr) {
        std::cout << "Destructor called for: nullptr" << std::endl;
    } else {
        std::cout << "Destructor called for: " << str << std::endl;
        delete [] str;
    }

}


// Equality/Inequality operator overloading
bool Mystring::operator==(const Mystring &rhs) const {

    return !std::strcmp(this->str, rhs.str);

}


bool Mystring::operator!=(const Mystring &rhs) const {

    return !operator==(rhs);

}


Mystring &Mystring::operator=(Mystring &&rhs) {

    std::cout << "Move assignment called for: " << rhs.str << std::endl;

    delete [] this->str;
    this->str = rhs.str;

    rhs.str = nullptr;

    return *this;

}


bool Mystring::operator<(const Mystring &rhs) const {

    return strcmp(this->str, rhs.str) < 0;

}


bool Mystring::operator>(const Mystring &rhs) const {

    return strcmp(this->str, rhs.str) > 0;

}


Mystring Mystring::operator-() const {

    const size_t str_length = std::strlen(str);
    char *buffer = new char[str_length + 1];

    std::strcpy(buffer, str);

    for (size_t i {0}; i < str_length; i++) {
        buffer[i] = tolower(buffer[i]);
    }
    
    Mystring lower {buffer};
    delete [] buffer;

    return lower;

}


Mystring Mystring::operator+(const Mystring &rhs) const {

    const size_t new_size = 
            std::strlen(str) + std::strlen(rhs.str) + 1;
    char *buffer = new char[new_size];

    std::strcpy(buffer, str);
    std::strcat(buffer, rhs.str);

    Mystring concat {buffer};
    delete [] buffer;
    
    return concat;

}


Mystring &Mystring::operator+=(const Mystring &rhs) {

    return operator=(operator+(rhs));

}


Mystring Mystring::operator*(const int iter) const {

    const size_t new_size = std::strlen(str) * iter + 1;
    char *buffer = new char[new_size];

    buffer[0] = '\0';

    for (size_t i {}; i < iter; i++) {
        std::strcat(buffer, str);
    }

    Mystring new_string {buffer};
    delete [] buffer;

    return new_string;

}


Mystring &Mystring::operator*=(const int iter) {

    return operator=(operator*(iter));

}


Mystring Mystring::operator++() {

    for (size_t i {}; i < std::strlen(str); i++) {
        str[i] = toupper(str[i]);
    }
    
    return *this;

}


Mystring Mystring::operator++(int) {

    Mystring obj {*this};
    operator++();

    return obj;

}