# Restaurant Order System

A simple Command-Line Interface (CLI) application developed in C++ for managing restaurant orders.

## Overview

This system allows users to select items from a predefined menu, add a tip, and print or save the final receipt. All interactions occur via the command line, making it accessible and easy to use.

## Structures

### Items

Stores individual menu items.

- `name`: (string) Name of the item.
- `price`: (double) Price of the item.

### Receipt

Stores the entire order and calculates the total.

- `clientName`: (string) Name of the client.
- `items`: (vector<Items>) Vector of Items structures, representing ordered items.
- `tip`: (double) Amount of tip.
- `total`: (double) Total cost.

## Core Functions

- `selectItem()`: Displays the menu and allows the user to select an item. Returns the selected item as an Items structure.
- `getTip()`: Prompts the user to input the tip amount and returns it as a double.
- `printReceipt(Receipt receipt)`: Displays the complete order, itemized with the final total.
- `getClientName()`: Asks the user for the client name and returns it as a string.
- `askToAddAnotherItem()`: Prompts the user whether they want to add another item to the order. Returns 'y' or 'Y' if yes, and 'n' or 'N' if no.
- `clearScreen()`: Clears the console screen, providing a clean view for new inputs/outputs.
- `saveReceiptToFile(const Receipt& receipt, const std::string& filename)`: Saves the receipt to a specified file.

## Workflow

1. **Client Name**: The application begins by asking for the client's name.
![Client Name](https://i.ibb.co/YLNrWVf/Name.png)
2. **Select Items**: Users select items from the menu until they choose to exit this step.
3. **Add Tip**: Users are prompted to add a tip to the order.
4. **View Receipt**: The receipt, containing all selected items, the tip, and the total cost, is displayed on the screen.
5. **Print Receipt**: Users are asked if they want to print the receipt. If yes, the receipt is saved to a temporary file and printed using the system's default text editor print command.
6. **New Order**: Finally, users are asked if they want to start a new order. If yes, the process repeats; if no, the application ends.
