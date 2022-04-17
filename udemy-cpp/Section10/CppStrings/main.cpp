#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    string s0;
    string s1 {"Apple"};
    string s2 {"Banana"};
    string s3 {"Kiwi"};
    string s4 {"apple"};
    string s5 {s1};
    string s6 {s1, 0, 3};
    string s7 (10, 'X');

    cout << s0 << endl;
    cout << s0.length() << endl;

    //// Initialization
    //cout << "\nInitialization";
    //cout << "\n----------------------------------" << endl;
    //cout << "s1: " << s1 << endl;
    //cout << "s2: " << s2 << endl;
    //cout << "s3: " << s3 << endl;
    //cout << "s4: " << s4 << endl;
    //cout << "s5: " << s5 << endl;
    //cout << "s6: " << s6 << endl;
    //cout << "s7: " << s7 << endl;

    //// Comparison
    //cout << "\nComparison";
    //cout << "\n----------------------------------" << endl;
    //cout << boolalpha;
    //cout << s1 << " == " << s5 << ": " << (s1 == s5) << endl;
    //cout << s1 << " == " << s2 << ": " << (s1 == s2) << endl;
    //cout << s1 << " != " << s2 << ": " << (s1 != s2) << endl;
    //cout << s1 << " < " << s2 << ": " << (s1 < s2) << endl;
    //cout << s2 << " > " << s1 << ": " << (s2 > s1) << endl;
    //cout << s4 << " < " << s5 << ": " << (s4 < s5) << endl;
    //cout << s1 << " == " << "Apple" << ": " << (s1 == "Apple") << endl;

    //// Assignment
    //cout << "\nAssignment";
    //cout << "\n----------------------------------" << endl;

    //s1 = "Watermelon";
    //cout << "s1 is now " << s1 << endl;

    //s2 = s1;
    //cout << "s2 is now " << s2 << endl;

    //s3 = "Frank";
    //cout << "s3 is now " << s3 << endl;

    //s3[0] = 'C';
    //cout << "s3 change first letter to 'C': " << s3 << endl;
    //s3.at(0) = 'P';
    //cout << "s3 change first letter to 'P': " << s3 << endl;

    //// Concatenation
    //cout << "\nConcatenation";
    //cout << "\n----------------------------------" << endl;

    //s3 = s5 + " and " + s2 + " juice";
    //cout << "s3 is now: " << s3 << endl;

    //// for loop
    //cout << "\nLooping";
    //cout << "\n----------------------------------" << endl;

    //s1 = "Apple";

    //for (size_t i {0}; i < s1.length(); i++) {
    //    cout << s1.at(i);
    //}
    //cout << endl;

    //// Range-based for loop
    //for (char c: s1) {
    //    cout << c;
    //}
    //cout << endl;

    //// Substring
    //cout << "\nSubstring";
    //cout << "\n----------------------------------" << endl;

    //s1 = "This is a test";

    //cout << s1.substr(0, 4) << endl;
    //cout << s1.substr(5, 2) << endl;
    //cout << s1.substr(10, 4) << endl;

    //// Erase
    //cout << "\nErase";
    //cout << "\n----------------------------------" << endl;

    //s1 = "This is a test";
    //s1.erase(0, 5);

    //cout << "s1 is now " << s1 << endl;

    //// getline
    //cout << "\ngetline";
    //cout << "\n----------------------------------" << endl;

    //string full_name {};

    //cout << "Enter your full name: ";
    //getline(cin, full_name);

    //cout << "Your full name is " << full_name << endl;

    // Find
    cout << "\nFind";
    cout << "\n----------------------------------" << endl;

    s1 = "The secret word is Boo";

    string word {};

    cout << "Enter the word to find: ";
    cin >> word;

    size_t position = s1.find(word);

    if (position != string::npos) {
        cout << "Found " << word << " at position: " 
            << position << endl;
    } else {
        cout << "Sorry, " << word << " not found" << endl;
    }

    return 0;
}