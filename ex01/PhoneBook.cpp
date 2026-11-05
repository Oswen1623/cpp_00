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

	//Replacing the oldest contact with the new one when book is full
	if (contact_idx >= max_contacts)
		contact_idx = 0;

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
		this->add_contact();
	else if (buffer == "yes" || buffer == "Yes" || buffer == "YES")
		std::cout << "Saving..." << std::endl ;
	sleep(1);
	this->contact_idx++;
	this->contact_nb++;
}
void PhoneBook::search_contact()
{
	if (this->contact_nb == 0){
		std::cout << "No contact avalaible ! Abort..." << std::endl; sleep(1); return;
	}
	std::cout << std::setw(5) << "Index" << "|";
	std::cout << std::setw(10) << "Firstname" << "|";
	std::cout << std::setw(10) << "Lastname" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	for (int i = 1; i <= contact_idx ; i++)
	{
		std::cout << std::setw(5) << i << "|";
		std::cout << std::setw(10) << this->id[i - 1].getFirstName().substr(0, 9) << "|";
		std::cout << std::setw(10) << this->id[i - 1].getLastName().substr(0, 9) << "|";
		std::cout << std::setw(10) << this->id[i - 1].getNickName().substr(0, 9) << std::endl;
	}
	// sleep(1);
	return;
}