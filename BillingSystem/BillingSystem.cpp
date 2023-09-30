#include <vector>
#include <iostream>
#include <string>
#include <fstream>

struct Itens {
	std::string name;
	double price;
};

struct Receipt {
	std::string clientName;
	std::vector<Itens> itens;
	double tip;
	double total;
};

/// <summary>
/// Lets the user select an item from the menu and returns the selected item.
/// </summary>
/// <returns>
/// An Itens structure containing the name and price of the selected item.
/// </returns>
Itens selectItem() {
	while (true) { // Loop until a valid input is received
		std::cout << "Select an item:\n";
		std::cout << "1 - Hamburger ($10)\n";
		std::cout << "2 - Hamburguer with cheese ($11)\n";
		std::cout << "3 - Double Cheese ($15)\n";
		std::cout << "4 - French Fries ($5)\n";
		std::cout << "5 - Soda ($3)\n";
		std::cout << "6 - Beer ($7)\n";
		std::cout << "7 - Water ($2)\n";
		std::cout << "8 - Ice Cream ($4)\n";
		std::cout << "9 - Exit\n";

		int option;
		std::cin >> option;

		// Clear the error flag on cin
		std::cin.clear();

		// Discard invalid input
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		switch (option) {
		case 1:
			return { "Hamburger", 10 };
		case 2:
			return { "Hamburger with cheese", 11 };
		case 3:
			return { "Double Cheese", 15 };
		case 4:
			return { "French Fries", 5 };
		case 5:
			return { "Soda", 3 };
		case 6:
			return { "Beer", 7 };
		case 7:
			return { "Water", 2 };
		case 8:
			return { "Ice Cream", 4 };
		case 9:
			return { "Exit", 0 };
		default:
			std::cout << "Invalid selection. Please enter a number between 1 and 9.\n";
			continue;
		}
	}
}


/// <summary>
/// Prompts the user to enter the tip amount.
/// </summary>
/// <returns>
/// The tip amount entered by the user.
/// </returns>
double getTip() {
	std::cout << "Enter the tip: ";
	double tip;
	std::cin >> tip;
	return tip;
}

/// <summary>
/// Prints the complete receipt to the console.
/// </summary>
/// <param name="receipt">
/// The receipt structure containing all the information to be printed.
/// </param>
void printReceipt(Receipt receipt) {
	std::cout << "*************************************\n";
	std::cout << "RESTAURANT AT THE END OF THE UNIVERSE\n";
	std::cout << "*************************************\n";
	std::cout << "Client: " << receipt.clientName << "\n";

	for (auto item : receipt.itens) {
		std::cout << item.name << " - $" << item.price << "\n";
	}
	std::cout << "-------------------------\n";
	std::cout << "Tip: $" << receipt.tip << "\n";
	std::cout << "-------------------------\n";
	std::cout << "Total: $" << receipt.total << "\n";
}

/// <summary>
/// Prompts the user to enter the client name.
/// </summary>
/// <returns>
/// The name of the client as entered by the user.
/// </returns>
std::string getClientName() {
	std::cout << "*************************************\n";
	std::cout << "RESTAURANT AT THE END OF THE UNIVERSE\n";
	std::cout << "*************************************\n";
	std::string clientName;
	std::cout << "Enter the client name: ";
	std::getline(std::cin, clientName);
	return clientName;
}

/// <summary>
/// Prompts the user to decide if they want to add another item.
/// This function continuously prompts the user until a valid input (y, Y, n, N) is provided.
/// </summary>
/// <returns>
/// Returns 'y' or 'Y' if the user wants to add another item, and 'n' or 'N' otherwise.
/// </returns>
char askToAddAnotherItem() {
	char response;
	while (true) {
		std::cout << "Add another item? (y/n) ";
		std::cin >> response;

		// Clear the error flag on cin
		std::cin.clear();

		// Discard invalid input
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (response == 'y' || response == 'Y' || response == 'n' || response == 'N') {
			return response;
		}
		else {
			std::cout << "Invalid input. Please enter 'y', 'Y', 'n', or 'N'.\n";
		}
	}
}

/// <summary>
/// Clears the console screen. Works for both Windows and other operating systems.
/// </summary>
void clearScreen() {
#ifdef _WIN32
	std::system("cls");
#else
	std::system("clear");
#endif
}

/// <summary>
/// Saves the complete receipt to a file.
/// </summary>
/// <param name="receipt">
/// The receipt structure containing all the information to be saved.
/// </param>
/// <param name="filename">
/// The name of the file where the receipt will be saved.
/// </param>
void saveReceiptToFile(const Receipt& receipt, const std::string& filename) {
	std::ofstream file(filename);
	file << "*************************************\n";
	file << "RESTAURANT AT THE END OF THE UNIVERSE\n";
	file << "*************************************\n";
	file << "Client: " << receipt.clientName << "\n";

	for (auto item : receipt.itens) {
		file << item.name << " - $" << item.price << "\n";
	}
	file << "-------------------------\n";
	file << "Tip: $" << receipt.tip << "\n";
	file << "-------------------------\n";
	file << "Total: $" << receipt.total << "\n";
	file.close();
}

int main() {
	while (true) {
		Receipt receipt;
		receipt.clientName = getClientName();
		clearScreen();

		// Inicialmente, adicione um item sem perguntar.
		Itens item = selectItem();
		while (item.name != "Exit") {
			receipt.itens.push_back(item);

			char goAhead = askToAddAnotherItem();
			if (goAhead == 'n' || goAhead == 'N') {
				break;
			}

			clearScreen();
			item = selectItem();
		}

		receipt.tip = getTip();

		receipt.total = receipt.tip;
		for (auto item : receipt.itens) {
			receipt.total += item.price;
		}

		clearScreen();
		printReceipt(receipt);

		char printOption;
		std::cout << "\nDo you want to print the receipt? (y/n): ";
		std::cin >> printOption;

		if (printOption == 'y' || printOption == 'Y') {
			const std::string filename = "temp_receipt.txt";
			saveReceiptToFile(receipt, filename);
			std::system(("notepad.exe /p " + filename).c_str());
		}

		char newOrderOption;
		std::cout << "\nDo you want to start a new order? (y/n): ";
		std::cin >> newOrderOption;

		// Limpar o buffer de entrada aqui.
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (newOrderOption == 'n' || newOrderOption == 'N') {
			break;
		}

		clearScreen();
	}

	return 0;
}
