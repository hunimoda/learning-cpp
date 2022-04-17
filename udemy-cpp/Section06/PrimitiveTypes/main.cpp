#include <iostream>

using namespace std;

int main() {
    /******************************************
     * Character type
     ******************************************/
    char middleInitial {'J'};
    cout << "My middle initial is " << middleInitial << endl;

    /******************************************
     * Integer type     
     ******************************************/
    unsigned short int examScore {55};
    cout << "My exam score was " << examScore << endl;

    int representedCoutries {65};
    cout << "There were " << representedCoutries 
        << " countries represented in my meeting" << endl;

    long int peopleInFlorida {20610000};
    cout << "There are about " << peopleInFlorida
        << " people in Florida" << endl;
    
    long long int peopleOnEarth {7'600'000'000};
    cout << "There are about " << peopleOnEarth << 
        " people on Earth" << endl;

    long long int distanceToAlphaCentauri {9'461'000'000'000};
    cout << "The distance to Alpha-Centauri is "
        << distanceToAlphaCentauri << "km" << endl;

    /******************************************
     * Floating point type
     ******************************************/
    float carPayment {401.23};
    cout << "My car payment is " << carPayment << endl;

    double pi {3.1415};
    cout << "PI is " << pi << endl;

    long double largeAmount {2.7e120};
    cout << largeAmount << " is a very big number" << endl;

    /******************************************
     * Boolean type
     ******************************************/
    bool gameOver {false};
    cout << "The value of gameOver is " << gameOver << endl;

    /******************************************
     * Overflow example
     ******************************************/
    short value1 {30'000};
    short value2 {1'000};
    int product {value1 * value2};

    cout << "The sum of " << value1 << " and "
        << value2 << " is " << product << endl;

    return 0;
}