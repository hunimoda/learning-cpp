#include <iostream>
#include <cstring>
#include "Mystring.h"


// Stream insertion operator overloading as non-member function
std::ostream &operator<<(std::ostream &os, const Mystring &obj) {

    os << obj.str;
    return os;

}


// Equality/Inequality operator overloading
bool operator==(const Mystring &lhs, const Mystring &rhs) {

    return !std::strcmp(lhs.str, rhs.str);

}


bool operator!=(const Mystring &lhs, const Mystring &rhs) {

    return !operator==(lhs, rhs);

}


// Compare operator overloading
bool operator<(const Mystring &lhs, const Mystring &rhs) {

    return std::strcmp(lhs.str, rhs.str) < 0;

}


bool operator>(const Mystring &lhs, const Mystring &rhs) {

    return std::strcmp(lhs.str, rhs.str) > 0;

}

// Unary negate operator overloading
Mystring operator-(const Mystring &obj) {

    const size_t str_length = std::strlen(obj.str);
    char *buffer = new char[str_length + 1];

    std::strcpy(buffer, obj.str);

    for (size_t i {}; i < str_length; i++) {
        buffer[i] = tolower(buffer[i]);
    }

    Mystring lower {buffer};
    delete [] buffer;

    return lower;

}


// Concat operator overloading
Mystring operator+(const Mystring &lhs, const Mystring &rhs) {

    const size_t new_size = 
        std::strlen(lhs.str) + std::strlen(rhs.str) + 1;
    char *buffer = new char[new_size];

    std::strcpy(buffer, lhs.str);
    std::strcat(buffer, rhs.str);

    Mystring concat {buffer};
    delete [] buffer;

    return concat;

}


Mystring &operator+=(Mystring &lhs, const Mystring &rhs) {

    return lhs.operator=(operator+(lhs, rhs));

}


// * operator overloading
Mystring operator*(const Mystring &lhs, const int rhs) {

    const size_t new_size = std::strlen(lhs.str) * rhs + 1;
    char *buffer = new char[new_size];

    buffer[0] = '\0';

    for (size_t i {}; i < rhs; i++) {
        std::strcat(buffer, lhs.str);
    }

    Mystring multi_concat {buffer};
    delete [] buffer;

    return multi_concat;

}


Mystring &operator*=(Mystring &lhs, const int rhs) {

    return lhs.operator=(operator*(lhs, rhs));

}

// Pre/Post increment operator overloading
Mystring operator++(Mystring &obj) {

    for (size_t i {}; i < std::strlen(obj.str); i++) {
        obj.str[i] = toupper(obj.str[i]);
    }

    return obj;

}


Mystring operator++(Mystring &obj, int) {

    Mystring return_obj {obj};
    ++obj;

    return return_obj;

}


Mystring::Mystring()
    : Mystring {""} {}


Mystring::Mystring(const char *str) {

    this->str = new char[std::strlen(str) + 1];
    std::strcpy(this->str, str);

}


Mystring::Mystring(const Mystring &source)
    : Mystring {source.str} {}


Mystring::~Mystring() {

    delete [] str;

}


// Move assignment operator overloading
Mystring &Mystring::operator=(Mystring &&rhs) {

    delete [] str;

    str = rhs.str;
    rhs.str = nullptr;

    return *this;

}