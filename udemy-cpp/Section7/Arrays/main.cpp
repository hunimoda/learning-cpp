#include <iostream>

using namespace std;

int main() {
    char vowels [] {'a', 'e', 'i', 'o', 'u'};
    cout << "\nThe first vowel is " << vowels[0] << endl;
    cout << "The last vowel is " << vowels[4] << endl;

    // cin >> vowels[5];   // Out-of-bounds

    double hiTemps [] {90.1, 89.8, 77.5, 81.6};
    
    cout << "\nThe first high temperature is " << hiTemps[0] << endl;

    hiTemps[0] = 100.7;
    cout << "The first high temperature is now " << hiTemps[0] << endl;

    int testScores [5] {};
    for (int i = 0; i < 5; i++) {
        cout << testScores[i] << endl;
    }
    for (int i = 0; i < 5; i++) {
        cin >> testScores[i];
    }
    for (int i = 0; i < 5; i++) {
        cout << testScores[i] << endl;
    }

    cout << "\nName of the array testScores: " << testScores << endl;

    return 0;
}