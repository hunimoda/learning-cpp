#include <iostream>

int main() {
    int dan;

    std::cout << "Which dan? ";
    std::cin >> dan;

    for (int num = 1; num <= 9; num++) {
        std::cout << dan << " x " << num 
            << " = " << dan * num << std::endl;
    }
    return 0;
}