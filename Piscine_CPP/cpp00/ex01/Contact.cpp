#include "Contact.hpp"

std::string Contact::getFirstName() const{
    return this->firstName;
}

std::string Contact::getLastName() const{
    return this->lastName;
}

std::string Contact::getNickname() const{
    return this->nickname;
}

std::string Contact::getDarkSecret() const{
    return this->darkSecret;
}

std::string Contact::getNumber() const{
    return this->number;
}

void Contact::setFirstName(std::string name){
    this->firstName = name;
}

void Contact::setLastName(std::string surname){
    this->lastName = surname;
}

void Contact::setNickname(std::string nick){
    this->nickname = nick;
}

void Contact::setDarkSecret(std::string secret){
    this->darkSecret = secret;
}

void Contact::setNumber(std::string number){
    this->number = number;
}