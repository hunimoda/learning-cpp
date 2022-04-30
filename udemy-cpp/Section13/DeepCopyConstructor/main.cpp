#include <iostream>

using namespace std;


class Deep {

private:
    int *data;

public:
    Deep(int);
    Deep(const Deep &);
    int get_data();
    ~Deep();
    
};


void show_deep_data(Deep s) {

    cout << s.get_data() << endl;

}


int main() {

    Deep src {123};

    show_deep_data(src);
    cout << "------------------------------" << endl;
    
    show_deep_data(src);

    return 0;

}


Deep::Deep(int _data) {

    data = new int;
    *data = _data;

    cout << "Create obj: " << data << " -> " << *data << endl;

}


//Deep::Deep(const Deep &src) {
//
//    data = new int;
//    *data = *src.data;
//
//    cout << "Create obj: " << data << " -> " << *data 
//        << " (by copying " << src.data << ')' << endl;
//
//}


// Delegating constructor
Deep::Deep(const Deep &src)
    : Deep {*src.data} {}


int Deep::get_data() {

    return *data;

}


Deep::~Deep() {

    cout << "Delete obj: " << data << " -> " << *data << endl;

    delete data;

}