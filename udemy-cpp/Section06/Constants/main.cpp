#include <iostream>

using namespace std;

const int PRICE_PER_SMALL_ROOM {25};
const int PRICE_PER_LARGE_ROOM {35};
const double TAX_RATE {0.06};
const int VALID_DAYS = {30};

int main() {
    cout << "Estimate for carpet cleaning service:" << endl;
    cout << "Number of small rooms: ";

    int numOfSmallRooms {0};
    cin >> numOfSmallRooms;

    cout << "Number of large rooms: ";

    int numOfLargeRooms {0};
    cin >> numOfLargeRooms;

    int cost = PRICE_PER_SMALL_ROOM * numOfSmallRooms
        + PRICE_PER_LARGE_ROOM * numOfLargeRooms;
    double tax = (double) cost * TAX_RATE;

    cout << "Price per small room: $" 
        << PRICE_PER_SMALL_ROOM << endl;
    cout << "Price per large room: $" 
        << PRICE_PER_LARGE_ROOM << endl;
    cout << "Cost: $" << cost << endl;
    cout << "Tax: $" << tax << endl;
    cout << "=================================" << endl;
    cout << "Total estimate: $" << cost + tax << endl;
    cout << "This estimate is valid for " << VALID_DAYS << " days" << endl;
    
    return 0;
}