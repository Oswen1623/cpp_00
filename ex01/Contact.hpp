#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "libs.hpp"

class Contact{
	public :
		Contact();
	private :
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string phone;
		std::string secret;

};

#endif