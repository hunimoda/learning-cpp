#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <iostream>


class Mystring {

    // Stream insertion operator overloading as non-member function
    friend std::ostream &operator<<(std::ostream &, const Mystring &);

private:
    char *str;

public:
    // Constructor / Destructor
    Mystring();
    Mystring(const char *);
    Mystring(const Mystring &);
    ~Mystring();

    // Equality/Inequality operator overloading
    bool operator==(const Mystring &) const;
    bool operator!=(const Mystring &) const;

    // Move assignment operator overloading
    Mystring &operator=(Mystring &&);

    // Compare operator overloading
    bool operator<(const Mystring &) const;
    bool operator>(const Mystring &) const;

    // Unary negate operator overloading
    Mystring operator-() const;

    // Concat operator overloading
    Mystring operator+(const Mystring &) const;
    Mystring &operator+=(const Mystring &);

    // * operator overloading
    Mystring operator*(const int) const;
    Mystring &operator*=(const int);

    // Pre/Post increment operator overloading
    Mystring operator++();
    Mystring operator++(int);

};

#endif