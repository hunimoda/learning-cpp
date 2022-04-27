#include <iostream>

using namespace std;

double a_penny_doubled_everyday(int num_of_days, double start_penny = 0.01) {
    if (num_of_days <= 1) {
        return start_penny;
    }

    return 2 * a_penny_doubled_everyday(num_of_days - 1, start_penny);
}

int main() {

    cout << a_penny_doubled_everyday(18) << endl;

    return 0;

}