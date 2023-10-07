# Restaurant Order System
Simple CLI (Command-Line Interface) application developed in C++ to manage restaurant orders.

# Overview
This system allows users to select items from a predefined menu, add a tip, and print or save the final receipt. All interactions happen via the command line, making it accessible and easy to use.

# Structures
- Itens
Stores individual menu items.

name: (string) Name of the item.
price: (double) Price of the item.

- Receipt
Stores the entire order and calculates the total.

clientName: (string) Name of the client.
itens: (vector<Itens>) Vector of Itens structures, representing ordered items.
tip: (double) Amount of tip.
total: (double) Total cost.

# Core Functions
selectItem()
Displays the menu and allows the user to select an item. Returns the selected item as an Itens structure.

getTip()
Prompts the user to input the tip amount and returns it as a double.

printReceipt(Receipt receipt)
Displays the complete order, itemized with the final total.

getClientName()
Asks the user for the client name and returns it as a string.

askToAddAnotherItem()
Prompts the user whether they want to add another item to the order. Returns 'y' or 'Y' if yes, and 'n' or 'N' if no.

clearScreen()
Clears the console screen, providing a clean view for new inputs/outputs.

saveReceiptToFile(const Receipt& receipt, const std::string& filename)
Saves the receipt to a specified file.

# Workflow
Client Name: The application begins by asking for the client's name.

Select Items: Users select items from the menu until they choose to exit this step.

Add Tip: Users are prompted to add a tip to the order.

View Receipt: The receipt, containing all selected items, the tip, and the total cost, is displayed on the screen.

Print Receipt: Users are asked if they want to print the receipt. If yes, the receipt is saved to a temporary file and printed using the system's default text editor print command.

New Order: Finally, users are asked if they want to start a new order. If yes, the process repeats; if no, the application ends.
