#include <string>
#include <vector>
#include "MenuItem.h"
#include <iostream>
#include <fstream>



class Receipt {
    std::string clientName;
    std::vector<MenuItem> items;
    double tip;
    double total;

public:
    Receipt(std::string clientName) : clientName(std::move(clientName)), tip(0), total(0) {}

    void addItem(const MenuItem& item) {
        items.push_back(item);
    }

    void setTip(double tipAmount) {
        tip = tipAmount;
    }

    void calculateTotal() {
        total = tip;
        for (const auto& item : items) {
            total += item.price;
        }
    }

    void print() const {
        std::cout << "*************************************\n";
        std::cout << "RESTAURANT AT THE END OF THE UNIVERSE\n";
        std::cout << "*************************************\n";
        std::cout << "Client: " << clientName << "\n";

        for (const auto& item : items) {
            std::cout << item.name << " - $" << item.price << "\n";
        }
        std::cout << "-------------------------\n";
        std::cout << "Tip: $" << tip << "\n";
        std::cout << "-------------------------\n";
        std::cout << "Total: $" << total << "\n";
    }

    void saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file for writing.\n";
            return;
        }

        file << "*************************************\n";
        file << "RESTAURANT AT THE END OF THE UNIVERSE\n";
        file << "*************************************\n";
        file << "Client: " << clientName << "\n";

        for (const auto& item : items) {
            file << item.name << " - $" << item.price << "\n";
        }
        file << "-------------------------\n";
        file << "Tip: $" << tip << "\n";
        file << "-------------------------\n";
        file << "Total: $" << total << "\n";

        file.close();
    }

    static void printReceiptDirectly(const std::string& filename) {
        std::string command = "notepad.exe /p " + filename;
        std::system(command.c_str());
    }
};