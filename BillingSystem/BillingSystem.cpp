#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include <cstdlib> 
#include "MenuItem.h"
#include "Receipt.h"
#include "InputUtils.h"
#include "OrderManager.h"


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
