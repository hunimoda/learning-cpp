#ifndef _MYSTRING_H_
#define _MYSTRING_H_


class Mystring {

private:
    char *str;

public:
    Mystring();
    Mystring(const char *);
    Mystring(const Mystring &);
    ~Mystring();

    Mystring &operator=(const Mystring &);
    Mystring &operator=(const char *);
    Mystring &operator=(Mystring &&);

    void display() const;
    int get_length() const;
    const char *get_str() const;

};


#endif