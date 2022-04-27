#include <iostream>
#include <vector>

using namespace std;

void show_menu();
void draw_horizontal_line();
bool is_list_empty(const vector<int> &);
char get_user_select();
void print_values(const vector<int> &);
void handle_print(const vector<int> &);
int read_int_from_user();
void add_number_to_list(vector<int> &, int);
void show_mean_value(const vector<int> &);
void show_min_value(const vector<int> &);
void show_max_value(const vector<int> &);

int main() {

    vector<int> list {};

    while (true) {
        // Show menu and get user selected option
        show_menu();
        char select = get_user_select();

        // Quit if selected option is 'Q' or 'q'
        if (select == 'Q') {
            cout << "Goodbye" << endl;
            break;
        }

        int read_number {};

        // =======================================
        draw_horizontal_line();

        switch (select) {
            // Print all list values
            case 'P':
                handle_print(list);
                break;
            // Add number to list
            case 'A':
                cout << "Enter a number: ";
                read_number = read_int_from_user();
                add_number_to_list(list, read_number);
                break;
            // Print mean value of list
            case 'M':
                show_mean_value(list);
                break;
            // print minimum value of list
            case 'S':
                show_min_value(list);
                break;
            // Print maximum value of list
            case 'L':
                show_max_value(list);
                break;
            default:
                cout << "Unknown selection, please try again" << endl;
        }

        // =======================================
        draw_horizontal_line();
    }

    return 0;

}

void show_menu() {
    cout << "P - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl;

    cout << "\nEnter your choice: ";
}

void draw_horizontal_line() {
    cout << "===============================" << endl;
}

bool is_list_empty(const vector<int> &list) {
    return list.size() <= 0;
}

char get_user_select() {
    char user_input {};
    cin >> user_input;

    return toupper(user_input);
}

void print_values(const vector<int> &list) {
    cout << '[';
    
    for (auto value: list) {
        cout << ' ' << value;
    }

    cout << " ]" << endl;
}

void handle_print(const vector<int> &list) {
    if (is_list_empty(list)) {
        cout << "[] - the list is empty" << endl;
    } else {
        print_values(list);
    }
}

int read_int_from_user() {
    int user_int {};
    cin >> user_int;

    return user_int;
}

void add_number_to_list(vector<int> &list, int number_to_add) {
    list.push_back(number_to_add);
    cout << number_to_add << " added" << endl;
}

void show_mean_value(const vector<int> &list) {
    if (is_list_empty(list)) {
        cout << "Unable to calculate the mean - no data" << endl;
        return;
    }

    int sum {};

    for (auto value: list) {
        sum += value;
    }

    double mean {static_cast<double>(sum) / list.size()};
    
    cout << "The mean value is " << mean << endl;
}

void show_min_value(const vector<int> &list) {
    if (is_list_empty(list)) {
        cout << "Unable to determine the smallest number - list is empty" << endl;
        return;
    }

    int min {list.at(0)};

    for (auto value: list) {
        if (value < min) {
            min = value;
        }
    }

    cout << "The min value is " << min << endl;
}

void show_max_value(const vector<int> &list) {
    if (is_list_empty(list)) {
        cout << "Unable to determine the largest number - list is empty" << endl;
        return;
    }

    int max {list.at(0)};

    for (auto value: list) {
        if (value > max) {
            max = value;
        }
    }

    cout << "The max value is " << max << endl;
}