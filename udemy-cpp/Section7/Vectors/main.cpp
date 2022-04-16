#include <iostream>
#include <vector>

using namespace std;

int main() {
    // vector <char> vowels;
    // vector <char> vowels (5);
    // vector <char> vowels {'a', 'e', 'i', 'o', 'u'};

    // cout << vowels[0] << endl;
    // cout << vowels[4] << endl;

    // vector<int> testScores(3);
    // vector<int> testScores(3, 100);
    //vector<int> testScores {100, 98, 89};

    //for (int i = 0; i < 3; i++) {
        //cout << testScores[i] << ' ' << testScores.at(i) << endl;
    //}

    //cout << testScores.size() << endl;
    //cout << testScores[3] << endl;
    // cout << testScores.at(3) << endl;

    //vector<int> testScores(3);

    //for (int i = 0; i < 3; i++) {
    //    cin >> testScores.at(i);
    //}
    //for (int i = 0; i < 3; i++) {
    //    cout << testScores.at(i) << endl;
    //}

    // vector<int> testScores {100, 98, 89};
    
    // cout << "Enter a test score: ";

    // int scoreToAdd;
    // cin >> scoreToAdd;

    // testScores.push_back(scoreToAdd);

    // cout << "\nTest scores are now: " << endl;
    // for (int i = 0; i < testScores.size(); i++) {
    //     cout << testScores.at(i) << endl;
    // }

    // try {
    //     vector<int> testScores(3);
    //     cout << "This should cause an exception!!" << testScores.at(10);
    // } catch (std::out_of_range oor) {
    //     cout << oor.what() << endl;
    // }

    // vector<vector<int>> movieRatings {
    //     {1, 2, 3, 4}, 
    //     {1, 2, 4, 4}, 
    //     {1, 3, 4, 5}
    // };

    // for (int i = 0; i < movieRatings.size(); i++) {
    //     for (int j = 0; j < movieRatings.at(i).size(); j++) {
    //         cout << movieRatings.at(i).at(j) << ' ';
    //     }
    //     cout << endl;
    // }

    // Challenge problem
    vector<int> vector1;
    vector<int> vector2;

    vector1.push_back(10);
    vector1.push_back(20);

    // Display vector1
    cout << "-------- vector1 --------" << endl;
    for (int i = 0; i < vector1.size(); i++) {
        cout << vector1.at(i) << endl;
    }

    vector2.push_back(100);
    vector2.push_back(200);

    // Display vector2
    cout << "-------- vector2 --------" << endl;
    for (int i = 0; i < vector2.size(); i++) {
        cout << vector2.at(i) << endl;
    }

    vector<vector<int>> vector2D;

    vector2D.push_back(vector1);
    vector2D.push_back(vector2);

    // Display vector2D
    cout << "-------- vector2D --------" << endl;
    for (int i = 0; i < vector2D.size(); i++) {
        for (int j = 0; j < vector2D.at(i).size(); j++) {
            cout << vector2D.at(i).at(j) << ' ';
        }
        cout << endl;
    }

    vector1.at(0) = 1000;

    // Display vector2D
    cout << "-------- vector2D --------" << endl;
    for (int i = 0; i < vector2D.size(); i++) {
        for (int j = 0; j < vector2D.at(i).size(); j++) {
            cout << vector2D.at(i).at(j) << ' ';
        }
        cout << endl;
    }

    // Display vector1
    cout << "-------- vector1 --------" << endl;
    for (int i = 0; i < vector1.size(); i++) {
        cout << vector1.at(i) << endl;
    }

    return 0;
}