#include "libs.hpp"

PhoneBook::PhoneBook() : max_contacts(8), contact_nb(0), contact_idx(0)
{
}

void PhoneBook::add_contact()
{
	std::string buffer;

	system("clear");

	std::cout << "Please enter your ennemy's informations:" << std::endl;
	
	//Save infos
	std::cout << "Enter first name:" << std::endl;
	while(buffer.empty()){
		if(!getline(std::cin, buffer))
			exit(1);}
	this->id[contact_idx].setFirstName(buffer);
	buffer.clear();

	std::cout << "Enter last name:" << std::endl;
	while(buffer.empty()){
		if(!getline(std::cin, buffer))
			exit(1);}
	this->id[contact_idx].setLastName(buffer);
	buffer.clear();

	std::cout << "Enter nickname:" << std::endl;
	while(buffer.empty()){
		if (!getline(std::cin, buffer))
			exit(1);}
	this->id[contact_idx].setNickName(buffer);
	buffer.clear();

	std::cout << "Enter phone number:" << std::endl;
	while(buffer.empty()){
		if (!getline(std::cin, buffer))
			exit(1);}
	this->id[contact_idx].setPhone(buffer);
	buffer.clear();

	std::cout << "Enter their darkest secret:" << std::endl;
	while(buffer.empty()){
		if (!getline(std::cin, buffer))
			exit(1);}
	this->id[contact_idx].setSecret(buffer);
	buffer.clear();

	//Show new contact infos before returning
	system("clear");
	std::cout << "You added this new enemy to your evil PhoneBook:" << std::endl;
	std::cout << std::endl;
	std::cout << "First name: " << this->id[contact_idx].getFirstName() << std::endl;
	std::cout << "Last name: " << this->id[contact_idx].getLastName() << std::endl;
	std::cout << "Nick name: " << this->id[contact_idx].getNickName() << std::endl;
	std::cout << "Phone number: " << this->id[contact_idx].getPhone() << std::endl;
	std::cout << "Darkest secret: " <<this->id[contact_idx].getSecret() << std::endl;
	std::cout << std::endl;
	std::cout << "Press any key to return to menu." << std::endl;
	getchar();
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

	system("clear");

	int contact_count = this->contact_nb;
	if (contact_count > this->max_contacts)
		contact_count = this->max_contacts;

	if (this->contact_nb == 0){
		std::cout << "You don't have any ennemy saved... are you really a villain?" << std::endl; sleep(2); return;
	}
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "Firstname" << "|";
	std::cout << std::setw(10) << "Lastname" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	for (int i = 1; i <= contact_count ; i++)
	{
		std::cout << std::setw(10) << i << "|";

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
	std::cout << std::endl;
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
	system("clear");
	std::cout << "First name: " << this->id[index -1].getFirstName() << std::endl;
	std::cout << "Last name: " << this->id[index - 1].getLastName() << std::endl;
	std::cout << "Nick name: " << this->id[index - 1].getNickName() << std::endl;
	std::cout << "Phone number: " << this->id[index - 1].getPhone() << std::endl;
	std::cout << "Darkest secret: " << this->id[index - 1].getSecret() << std::endl;
	std::cout << std::endl;
	std::cout << "Press any key to return to menu." << std::endl;
	getchar();
	return;
}