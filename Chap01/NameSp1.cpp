#include <iostream>

namespace BestCom {
    void SimpleFunc() {
        std::cout << "BestCom::SimpleFunc()" << std::endl;
    }
}

namespace ProgCom {
    void SimpleFunc() {
        std::cout << "ProgCom::SimpleFunc()" << std::endl;
    }
}

int main() {
    BestCom::SimpleFunc();
    ProgCom::SimpleFunc();
    return 0;
}