#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    int random_number {};
    size_t count {10};
    int min {1};
    int max {6};

    cout << "RAND_MAX: " << RAND_MAX << endl;
    cout << "time(nullptr): " << time(nullptr) << endl;
    srand(time(nullptr));   // Seeding random number

    for (size_t i {1}; i <= count; ++i) {
        random_number = rand() % max + min;
        cout << random_number << endl;
    }

    cout << endl;

    return 0;

}