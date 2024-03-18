#pragma once
#include <iostream>
#include <vector>
#include "InputUtils.h"
#include "MenuItem.h"

class OrderManager {
    std::vector<MenuItem> menuItems{
        {"Hamburger", 10},
        {"Hamburger with cheese", 11},
        {"Double Cheese", 15},
        {"French Fries", 5},
        {"Soda", 3},
        {"Beer", 7},
        {"Water", 2},
        {"Ice Cream", 4}
    };

public:
    MenuItem selectItem() {
        while (true) {
            std::cout << "Select an item:\n";
            for (size_t i = 0; i < menuItems.size(); ++i) {
                std::cout << i + 1 << " - " << menuItems[i].name << " ($" << menuItems[i].price << ")\n";
            }
            std::cout << menuItems.size() + 1 << " - Exit\n";

            int option = static_cast<int>(InputUtils::getDouble("Option: ")) - 1;
            if (option >= 0 && option < static_cast<int>(menuItems.size())) {
                return menuItems[option];
            }
            else if (option == static_cast<int>(menuItems.size())) {
                return { "Exit", 0 };
            }
            else {
                std::cout << "Invalid selection. Please enter a number between 1 and " << menuItems.size() + 1 << ".\n";
            }
        }
    }
};

