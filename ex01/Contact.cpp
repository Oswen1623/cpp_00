#include "libs.hpp"

Contact::Contact()
{}

Contact::~Contact()
{}

//Setter
void Contact::setFirstName(std::string firstname) {
	this->firstname = firstname;
}
void Contact::setLastName(std::string lastname) {
	this->lastname = lastname;
}
void Contact::setNickName(std::string nickname) {
	this->nickname = nickname;
}
void Contact::setPhone(std::string phone) {
	this->phone = phone;
}
void Contact::setSecret(std::string secret) {
	this->secret = secret;
}

//Getter
std::string Contact::getFirstName() const {
	return firstname;
}
std::string Contact::getLastName() const {
	return lastname;
}
std::string Contact::getNickName() const {
	return nickname;
}
std::string Contact::getPhone() const {
	return phone;
}
std::string Contact::getSecret() const {
	return secret;
}