#include <vector>
#include <iostream>
#include <string>

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

std::string getClientName() {
	std::cout << "*************************************\n";
	std::cout << "RESTAURANT AT THE END OF THE UNIVERSE\n";
	std::cout << "*************************************\n";
	std::string clientName;
	std::cout << "Enter the client name: ";
	std::getline(std::cin, clientName);
	return clientName;
}

int main()
{
	getClientName();
}

