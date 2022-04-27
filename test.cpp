#include <iostream>

int main() {
    while (std::cin.peek() != EOF) {
        std::cout << std::cin.peek() << std::endl;
        char c;
        std::cin >> c;
    }
}
