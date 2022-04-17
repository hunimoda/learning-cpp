#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    ////int scores[] {100, 90, 97};

    ////for (auto score: scores) {
    ////    cout << score << endl;
    ////}

    //vector<double> temps {87.2, 77.1, 80.0, 72.5};
    //double average_temp {};
    //double running_sum {};

    //cout << "=============================" << endl;

    //for (auto temp: temps) {
    //    running_sum += temp;
    //}

    //average_temp = running_sum / temps.size();

    //cout << "Sum: " << running_sum << endl;
    //cout << "Avg: " << average_temp << endl;
    //cout << "=============================" << endl;

    //for (auto test: {1, 2, 3, 4, 5}) {
    //    cout << test << endl;
    //}

    //cout << "=============================" << endl;

    //for (auto ch: "Hunimoda") {
    //    cout << ch << endl;
    //}

    //int scores[] {10, 20, 30};

    //// for (int score: scores) {
    ////     cout << score << endl;
    //// }
    //for (auto score: scores) {
    //    cout << score << endl;
    //}

    //vector<double> temps {87.9, 77.9, 80.0, 72.5};
    //double average_temp {};
    //double running_sum {};

    //for (auto temp: temps) {
    //    running_sum += temp;
    //}

    //if (temps.size()) {
    //    average_temp = running_sum / temps.size();
    //    cout << fixed << setprecision(1);
    //    cout << "Average temperature: " << average_temp << endl;
    //} else {
    //    cout << "Empty dataset!" << endl;
    //}

    //for (auto value: {1, 2, 3, 4, 5}) {
    //    cout << value << endl;
    //}

    for (auto c: "This is a test") {
        if (c == ' ') {
            cout << '.';
        } else {
            cout << c;
        }
    }
    cout << endl;

    return 0;
}