#include <iostream>

int getSalary(int sales) {
    return 50 + sales * 0.12;
}

int main() {
    int sales;

    while (true) {
        std::cout << "Sales? ";
        std::cin >> sales;

        if (sales == -1) break;

        std::cout << "Salary => " << getSalary(sales) << std::endl;
    }

    std::cout << "[END]" << std::endl;

    return 0;
}