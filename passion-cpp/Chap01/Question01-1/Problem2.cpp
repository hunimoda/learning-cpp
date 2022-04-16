#include <iostream>

int main() {
    char name[100];
    char phone[100];

    std::cout << "What's your name? ";
    std::cin >> name;

    std::cout << "What's your phone number? ";
    std::cin >> phone;

    std::cout << "NAME: " << name << std::endl;
    std::cout << "PHONE: " << phone << std::endl;
    return 0;
}