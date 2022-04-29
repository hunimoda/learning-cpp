#include <iostream>
#include "dog.h"

using namespace std;


int main() {

    Dog spot;

    spot.name = "Spot";
    spot.age = 5;

    spot.introduce();

    cout << endl;
    return 0;

}