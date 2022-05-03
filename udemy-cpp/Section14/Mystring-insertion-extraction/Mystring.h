#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <iostream>


class Mystring {

private:
    char *str;

public:
    // Constructor & destructor
    Mystring();
    Mystring(const char *);
    Mystring(const Mystring &);
    ~Mystring();

    // Operators overloading
    Mystring &operator=(const Mystring &);
    Mystring &operator=(const char *);
    Mystring &operator=(Mystring &&);
    friend bool operator==(const Mystring &, const Mystring &);
    friend Mystring operator-(const Mystring &);
    friend Mystring operator+(const Mystring &, const Mystring &);
    friend std::ostream &operator<<(std::ostream &, const Mystring &);
    friend std::istream &operator>>(std::istream &, Mystring &);

    // Methods
    void display() const;
    int get_length() const;
    const char *get_str() const;

};


#endif