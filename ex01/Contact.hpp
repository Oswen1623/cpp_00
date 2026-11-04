#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "libs.hpp"

class Contact{
	public :
		Contact();
		~Contact();
		//Setter
		void setFirstName(std::string firstname);
		void setLastName(std::string lastname);
		void setNickName(std::string nickname);
		void setPhone(std::string phone);
		void setSecret(std::string secret);

		//Getter
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;
		std::string getPhone() const;
		std::string getSecret() const;

	private :
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string phone;
		std::string secret;

};

#endif