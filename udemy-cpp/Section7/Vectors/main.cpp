#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector <int> testScores {100, 95};
    cout << "Hello" << endl;
    cin >> testScores.at(5);
    cout << "World" << endl;

    return 0;
}