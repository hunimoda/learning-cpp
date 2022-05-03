#include <iostream>
#include "Mystring.h"

using namespace std;

void display_title(const char *);


int main() {

    cout << boolalpha << endl;
    
    display_title("Overload constructor");
    Mystring a {"frank"};
    Mystring b {"frank"};

    display_title("Equal/Not Equal");
    cout << (a == b) << endl;   // true
    cout << (a != b) << endl;   // false

    b = "george";   // Move assignment operator
    cout << (a == b) << endl;   // false
    cout << (a != b) << endl;   // true
    
    display_title("Compare");
    cout << (a < b) << endl;    // true
    cout << (a > b) << endl;    // false

    Mystring s1 {"FRANK"};

    display_title("Unary Negate");
    s1 = -s1;
    cout << s1 << endl; // frank

    display_title("Concat");
    s1 = s1 + "*****";
    cout << s1 << endl; // frank*****

    display_title("Concat & Assign");
    s1 += "-----";
    cout << s1 << endl; // frank*****-----

    Mystring s2 {"12345"};
    
    display_title("Multiple");
    s1 = s2 * 3;
    cout << s1 << endl; // 123451234512345

    Mystring s3 {"abcdef"};
    
    display_title("Multiple & Assign");
    s3 *= 5;
    cout << s3 << endl; // abcdefabcdefabcdefabcdefabcdef

    Mystring s = "Frank";
    
    display_title("Pre-increment");
    ++s;
    cout << s << endl;  // FRANK

    s = -s;
    cout << s << endl;  // frank

    // No-args constructor
    Mystring result;
    result = ++s;
    cout << s << endl;  // FRANK
    cout << result << endl; // FRANK

    s = "Frank";

    display_title("Post-increment");
    s++;
    cout << s << endl;  // FRANK

    s = -s;
    cout << s << endl;  // frank
    result = s++;
    cout << s << endl;  // FRANK
    cout << result << endl; // frank

    display_title("END of program");

    return 0;

}


void display_title(const char *title) {

    std::cout << "\n----- " << title 
            << " ------------------------------" << std::endl;

}