#include <iostream>

using namespace std;

int main() {
    const double DOLLAR_PER_EURO {1.08};

    cout << "EUR: ";
    
    double euros {0.0};
    cin >> euros;

    double dollars {euros * DOLLAR_PER_EURO};
    cout << "= $" << dollars << endl;

    return 0;
}