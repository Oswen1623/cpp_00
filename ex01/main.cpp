#include "libs.hpp"

int main()
{
	PhoneBook PhoneBook;

	std::string input;

	system("clear");
	std::cout << "Welcome to the Evil PhoneBook! The phonebook made for villains!" << std::endl;

	while(1)
	{
		std::cout << "Please enter an option : ADD, SEARCH, EXIT." << std::endl;
		if (!getline(std::cin, input))
			exit(1);

		//Add
		if (!input.compare("ADD") || !input.compare("add") || !input.compare("Add"))
			PhoneBook.add_contact();

		//Search
		else if (!input.compare("SEARCH") || !input.compare("search") || !input.compare("Search"))
			PhoneBook.search_contact();

		//Exit
		else if (!input.compare("EXIT") || !input.compare("exit") || !input.compare("Exit"))
		{
			std::cout << "Bye, have an awful day!" << std::endl;
			break;
		}
		system("clear");
	}
	// sleep(1);
	return 0;
}
