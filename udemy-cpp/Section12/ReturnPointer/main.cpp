#include <iostream>

using namespace std;

int *create_array(size_t size, int init_value = 0) {
    int *new_storage {nullptr};
    new_storage = new int[size];

    for (size_t i = 0; i < size; ++i) {
        new_storage[i] = init_value;
    }

    return new_storage;
}

void display(const int *const arr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main() {
    int *my_array {nullptr};
    size_t size {};
    int init_value {};

    cout << "\nHow many integers to alloc? ";
    cin >> size;
    cout << "What value to init to? ";
    cin >> init_value;

    my_array = create_array(size, init_value);
    
    cout << "&my_array: " << &my_array << endl;
    cout << "my_array: " << my_array << endl;
    cout << "\n===============================" << endl;

    display(my_array, size);
    delete [] my_array;

    cout << endl;
    return 0;

}