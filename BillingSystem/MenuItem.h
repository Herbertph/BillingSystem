#pragma once
#include <string>

class MenuItem {
public:
    std::string name;
    double price;

    MenuItem(std::string name, double price) : name(std::move(name)), price(price) {}
};