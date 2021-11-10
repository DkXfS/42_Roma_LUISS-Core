#include "Agenda.hpp"
#include <cctype>

bool alphaPresent(std::string str){
    int i=0;
    while(str[i])
        if(std::isalpha(str[i++]))
            return true;
    return false;
}

std::string getInput(){
    std::string str;
    while (str.empty()){
        std::getline(std::cin, str);
        if(str.empty())
            std::cout << "Line can't be empty. Retry" << std::endl << "\t";
    }
    return str;
}

void Agenda::addContact(){
    std::string input;
    static int i=0;

    if(i > 7)
        i=0;
    std::cout << "Enter the contact's first name :" << std::endl << "\t";
    input = getInput();
    this->contacts[i].setFirstName(input);
    std::cout << "Enter the contact's last name :" << std::endl << "\t";
    input = getInput();
    this->contacts[i].setLastName(input);
    std::cout << "Enter the contact's nickname :" << std::endl << "\t";
    input = getInput();
    this->contacts[i].setNickname(input);
    std::cout << "Enter the contact's dark secret :" << std::endl << "\t";
    input = getInput();
    this->contacts[i].setDarkSecret(input);
    std::cout << "Enter the contact's number :" << std::endl << "\t";
    while (1){
        input = getInput();
        if (alphaPresent(input))
            std::cout << "The number entered contains alphabetical characters. Retry" << std::endl << "\t";
        else break;
    }
    this->contacts[i].setNumber(input);
    i++;
}

Contact Agenda::getContact(int i) const{
    Contact ret;

    ret.setFirstName(this->contacts[i].getFirstName());
    ret.setLastName(this->contacts[i].getLastName());
    ret.setNickname(this->contacts[i].getNickname());
    ret.setDarkSecret(this->contacts[i].getDarkSecret());
    ret.setNumber(this->contacts[i].getNumber());
    return ret;
}