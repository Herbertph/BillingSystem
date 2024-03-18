#pragma once
#include <iostream>
#include <string>
#include <limits>

class InputUtils {
public:
    static std::string getString(const std::string& prompt) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);
        return input;
    }

    static double getDouble(const std::string& prompt) {
        std::cout << prompt;
        double value;
        while (!(std::cin >> value)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. " << prompt;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return value;
    }

    static char getChar(const std::string& prompt) {
        std::cout << prompt;
        char input;
        std::cin >> input;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return input;
    }
};

