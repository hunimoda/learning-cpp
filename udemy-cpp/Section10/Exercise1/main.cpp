#include <iostream>
#include <string>

using namespace std;

string FormatFullName(string);

int main() {
    cout << "Enter your full name with no spaces: ";
    
    string unformatted_full_name {};
    cin >> unformatted_full_name;

    string formatted_full_name {};
    formatted_full_name = FormatFullName(unformatted_full_name);

    cout << "Formatted name: " << formatted_full_name << endl;

    return 0;
}

string FormatFullName(string unformatted) {
    string formatted {};

    for (auto c: unformatted) {
        if (isupper(c)) {
            formatted += ' ';
        }
        formatted += c;
    }

    formatted = formatted.substr(1);

    return formatted;
}