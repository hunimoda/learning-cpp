#include <iostream>
using namespace std;

// This program will calculate the area of a room in square feet

int main() {
    cout << "Enter the width & height: ";

    int roomWidth {0};
    int roomHeight {0};

    cin >> roomWidth >> roomHeight;

    int roomArea = roomWidth * roomHeight;
    
    cout << "The area of the room is " << roomArea << "ft^2" << endl;
    
    return 0;
}