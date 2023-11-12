#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cout << "Enter an expression: ";
    std::cin >> input;

    char firstChar = input[0];
    char secondChar = input[1];

    if (input.size() == 1) {
        std::cout << "Invalid input. Please enter a valid expression." << std::endl;
    } else if (input.size() == 2) {
        if (firstChar == '<' && secondChar == '=') {
            std::cout << "<= Less than or equal to" << std::endl;
        } else if (firstChar == '>' && secondChar == '=') {
            std::cout << ">= Greater than or equal to" << std::endl;
        } else if (firstChar == '=' && secondChar == '=') {
            std::cout << "== Equal to" << std::endl;
        } else if (firstChar == '!' && secondChar == '=') {
            std::cout << "!= Not equal to" << std::endl;
        } else if (firstChar == '<') {
            std::cout << "< Less than" << std::endl;
        } else if (firstChar == '>') {
            std::cout << "> Greater than" << std::endl;
        } else {
            std::cout << "Invalid input. Please enter a valid expression." << std::endl;
        }
    } else {
        std::cout << "Invalid input. Please enter a valid expression." << std::endl;
    }

    return 0;
}

