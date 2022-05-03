#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <iostream>


class Mystring {

    // Stream insertion operator overloading as non-member function
    friend std::ostream &operator<<(std::ostream &, const Mystring &);

    // Equality/Inequality operator overloading
    friend bool operator==(const Mystring &, const Mystring &);
    friend bool operator!=(const Mystring &, const Mystring &);

    // Compare operator overloading
    friend bool operator<(const Mystring &, const Mystring &);
    friend bool operator>(const Mystring &, const Mystring &);

    // Unary negate operator overloading
    friend Mystring operator-(const Mystring &);

    // Concat operator overloading
    friend Mystring operator+(const Mystring &, const Mystring &);
    friend Mystring &operator+=(Mystring &, const Mystring &);

    // * operator overloading
    friend Mystring operator*(const Mystring &, const int);
    friend Mystring &operator*=(Mystring &, const int);

    // Pre/Post increment operator overloading
    friend Mystring operator++(Mystring &);
    friend Mystring operator++(Mystring &, int);

private:
    char *str;

public:
    // Constructor / Destructor
    Mystring();
    Mystring(const char *);
    Mystring(const Mystring &);
    ~Mystring();

    // Move assignment operator overloading
    Mystring &operator=(Mystring &&);

};

#endif