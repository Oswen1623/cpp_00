#include "libs.hpp"

PhoneBook::PhoneBook() : max_contacts(8), contact_nb(0), contact_idx(0)
{
}

void PhoneBook::add_contact()
{
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phone;
	std::string secret;
	std::string buffer;

	system("clear");
	std::cout << "Enter first name:" << std::endl;
	getline(std::cin, firstname);
	this->id[contact_idx].setFirstName(firstname);


	std::cout << "Enter last name:" << std::endl;
	getline(std::cin, lastname);
	this->id[contact_idx].setLastName(lastname);

	std::cout << "Enter nickname:" << std::endl;
	getline(std::cin, nickname);
	this->id[contact_idx].setNickName(nickname);

	std::cout << "Enter phone number:" << std::endl;
	getline(std::cin, phone);
	this->id[contact_idx].setPhone(phone);

	std::cout << "Enter their darkest secret:" << std::endl;
	getline(std::cin, secret);
	this->id[contact_idx].setSecret(secret);
	system("clear");
	std::cout << "You added this new enemy to your evil PhoneBook:" << std::endl;
	std::cout << "First name: " << this->id[contact_idx].getFirstName() << std::endl;
	std::cout << "Last name: " << this->id[contact_idx].getLastName() << std::endl;
	std::cout << "Nick name: " << this->id[contact_idx].getNickName() << std::endl;
	std::cout << "Phone number: " << this->id[contact_idx].getPhone() << std::endl;
	std::cout << "Darkest secret: " <<this->id[contact_idx].getSecret() << std::endl;
	std::cout << "Confirm ennemy? Yes/Restart" << std::endl;

	//Handle restart !!! Change idx incrementation ?
	if (!getline(std::cin, buffer))
		exit(1);
	else if (buffer == "Restart" || buffer == "restart" || buffer == "RESTART")
		return;
	else if (buffer == "yes" || buffer == "Yes" || buffer == "YES")
		std::cout << "Saving..." << std::endl ;
	sleep(1);
	contact_idx++;
	//Replacing the oldest contact with the new one when book is full
	if (contact_idx >= max_contacts)
		contact_idx = 0;
	if (this->contact_nb < this->max_contacts)
		this->contact_nb++;
}


void PhoneBook::search_contact()
{
	std::string buffer;
	int contact_count = this->contact_nb;
	if (contact_count > this->max_contacts)
		contact_count = this->max_contacts;

	if (this->contact_nb == 0){
		std::cout << "You don't have any ennemy saved... are you really a villain?" << std::endl; sleep(2); return;
	}
	std::cout << std::setw(5) << "Index" << "|";
	std::cout << std::setw(10) << "Firstname" << "|";
	std::cout << std::setw(10) << "Lastname" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	for (int i = 1; i <= contact_count ; i++)
	{
		std::cout << std::setw(5) << i << "|";

		//Formatting output depending on string lengths (10 char max per column)
		if (this->id[i - 1].getFirstName().length() > 9)
			std::cout << std::setw(10) << this->id[i - 1].getFirstName().substr(0, 9) + "." << "|";
		else
			std::cout << std::setw(10) << this->id[i - 1].getFirstName() << "|";

		if (this->id[i - 1].getLastName().length() > 9)
			std::cout << std::setw(10) << this->id[i - 1].getLastName().substr(0, 9) + "." << "|";
		else
			std::cout << std::setw(10) << this->id[i - 1].getLastName() << "|";

		if (this->id[i - 1].getNickName().length() > 9)
			std::cout << std::setw(10) << this->id[i - 1].getNickName().substr(0, 9) + "." << std::endl;
		else
			std::cout << std::setw(10) << this->id[i - 1].getNickName() << std::endl;
	}
	std::cout << "Enter the index of the contact to display:" << std::endl;
	if (!getline(std::cin, buffer))
		exit(1);
	int index = atoi(buffer.c_str());
	if (index < 1 || index > contact_count)
	{
		std::cout << "Please enter a valid index. Returning to menu..." << std::endl ;
		sleep(2);
		return;
	}

	std::cout << "First name: " << this->id[index -1].getFirstName() << std::endl;
	std::cout << "Last name: " << this->id[index - 1].getLastName() << std::endl;
	std::cout << "Nick name: " << this->id[index - 1].getNickName() << std::endl;
	std::cout << "Phone number: " << this->id[index - 1].getPhone() << std::endl;
	std::cout << "Darkest secret: " << this->id[index - 1].getSecret() << std::endl;
	std::cout << "Press a enter to return to menu." << std::endl;
	getchar();
	return;
}