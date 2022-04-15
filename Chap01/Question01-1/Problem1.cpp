#include <iostream>

int main() {
    int sum = 0;
    int inputNum;

    for (int i = 0; i < 5; i++) {
        std::cout << "Integer [" << i + 1 << "]: ";
        std::cin >> inputNum;

        sum += inputNum;
    }

    std::cout << "Sum: " << sum << std::endl;
    return 0;
}