#include <iostream>

using namespace std;


class Shallow {

private:
    int *data;

public:
    Shallow(int);
    Shallow(const Shallow &);
    int get_data();
    ~Shallow();
    
};


void show_shallow_data(Shallow s) {

    cout << s.get_data() << endl;

}


int main() {

    Shallow src {123};

    show_shallow_data(src);
    cout << "------------------------------" << endl;
    
    show_shallow_data(src);

    return 0;

}


Shallow::Shallow(int _data) {

    data = new int;
    *data = _data;

    cout << "Create obj: " << data << " -> " << *data << endl;

}


Shallow::Shallow(const Shallow &src)
    : data {src.data} {

    cout << "Create obj: " << data << " -> " << *data 
        << "(by copying " << src.data << ')' << endl;

}


int Shallow::get_data() {

    return *data;

}


Shallow::~Shallow() {

    cout << "Delete obj: " << data << " -> " << *data << endl;

    delete data;

}