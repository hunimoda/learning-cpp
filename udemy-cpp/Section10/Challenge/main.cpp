#include <iostream>
#include <string>

using namespace std;

string EncryptString(string original, bool is_encrypt_mode = true);

int main() {

    cout << "Enter any sentence: ";

    string input_string {};
    getline(cin, input_string);

    cout << "Encrypted: " << EncryptString(input_string) << endl;
    cout << "Decrypted: " << EncryptString(EncryptString(input_string), false) << endl;

    return 0;
}

string EncryptString(string original, bool is_encrypt_mode) {
    string alphabets {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
    string encrypted {"dtNuMgpVUjRqYQabTlWBykhODxweJzCLZHIcGmfoSnFvAXPrsEKi"};

    string from_set {};
    string to_set {};

    from_set = (is_encrypt_mode) ? alphabets : encrypted;
    to_set = (is_encrypt_mode) ? encrypted : alphabets;

    string processed_string {};

    for (auto c: original) {
        const size_t kIndexOfChar = from_set.find(c);

        if (kIndexOfChar == string::npos) {
            processed_string += c;
        } else {
            processed_string += to_set.at(kIndexOfChar);
        }
    }

    return processed_string;
}