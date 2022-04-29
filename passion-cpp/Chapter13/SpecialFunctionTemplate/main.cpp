#include <iostream>
#include <cstring>

using std::cout;
using std::endl;


template <class T>
T max(T val1, T val2) {

    return (val1 > val2) ? val1 : val2;

}


template <>
char *max(char *s1, char *s2) {

    cout << "char *max<char *>(char *s1, char *s2)" << endl;
    return strlen(s1) > strlen(s2) ? s1 : s2;

}


template <>
const char *max(const char *s1, const char *s2) {

    cout << "const char *max(const char *s1, const char *s2)" << endl;
    return strcmp(s1, s2) > 0 ? s1 : s2;

}


int main() {

    cout << max(11, 15) << endl;
    cout << max('T', 'Q') << endl;
    cout << max(3.5, 7.5) << endl;
    cout << max("simple", "best") << endl;

    char str1[] {"simple"};
    char str2[] {"best"};
    cout << max(str1, str2) << endl;

    cout << endl;
    return 0;

}