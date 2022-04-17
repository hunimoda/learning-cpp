#include <iostream>

using namespace std;

int main() {
    int num {};
    const int kLower {10};
    const int kUpper {20};

    cout << boolalpha;
    //cout << "Enter an integer between " 
    //    << kLower << " and " << kUpper << ": ";
    //cin >> num;

    //bool is_within_bounds {false};

    //is_within_bounds = (kLower < num) && (num < kUpper);
    //cout << num << " is between " << kLower << " and " 
    //    << kUpper << ": " << is_within_bounds << endl;

    //cout << "\nEnter an integer outside of bound (" 
    //    << kLower << ", " << kUpper << "): ";
    //cin >> num;
    
    //bool is_outside_bounds {false};

    //is_outside_bounds = (num < kLower) || (kUpper < num);
    //cout << num << " outside " << kLower << " and " 
    //    << kUpper << ": " << is_outside_bounds << endl;

    cout << "\nEnter an integer either " << kLower 
        << " or " << kUpper << ": ";
    cin >> num;

    bool is_on_bound {false};

    is_on_bound = (num == kLower) || (num == kUpper);
    cout << num << " is " << kLower << " or " 
        << kUpper << ": " << is_on_bound << endl;
    
    return 0;
}