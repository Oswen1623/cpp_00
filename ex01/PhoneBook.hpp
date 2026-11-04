#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "libs.hpp"

class PhoneBook{
	public :
		PhoneBook();

		void add_contact();
		void search_contact();

	private :
		const int max_contacts;
		int contact_nb;
		int contact_idx;
		Contact id[8];
};

#endif