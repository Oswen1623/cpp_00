#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "libs.hpp"

class PhoneBook{
	public :
		PhoneBook();
	private :
		const int max_contacts;
		Contact id[8];
};

#endif