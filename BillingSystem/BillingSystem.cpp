#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include <cstdlib> 

class MenuItem {
public:
    std::string name;
    double price;

    MenuItem(std::string name, double price) : name(std::move(name)), price(price) {}
};

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

int main() {
    while (true) {
        std::string clientName = InputUtils::getString("Enter the client name: ");
        Receipt receipt(clientName);

        OrderManager orderManager;
        MenuItem item = orderManager.selectItem();
        while (item.name != "Exit") {
            receipt.addItem(item);

            char addMore = InputUtils::getChar("Add another item? (y/n) ");
            if (addMore == 'n' || addMore == 'N') {
                break;
            }
            item = orderManager.selectItem();
        }

        double tip = InputUtils::getDouble("Enter the tip: ");
        receipt.setTip(tip);
        receipt.calculateTotal();
        receipt.print();

        char saveOption = InputUtils::getChar("\nDo you want to save the receipt to a file? (y/n): ");
        if (saveOption == 'y' || saveOption == 'Y') {
            receipt.saveToFile("receipt.txt");
            char printOption = InputUtils::getChar("Do you want to print the receipt? (y/n): ");
            if (printOption == 'y' || printOption == 'Y') {
                Receipt::printReceiptDirectly("receipt.txt");
            }
        }

        char newOrder = InputUtils::getChar("\nDo you want to start a new order? (y/n): ");
        if (newOrder == 'n' || newOrder == 'N') {
            break;
        }
    }
    return 0;
}
