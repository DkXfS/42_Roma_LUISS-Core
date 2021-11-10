#include <iostream>
#include "Agenda.hpp"
#include "Contact.hpp"
#include <iomanip>
#include <cctype>

bool nonNumPresent(std::string str){
    int i=0;
    while(str[i])
        if(!std::isdigit(str[i++]))
            return true;
    return false;
}

int toInt(std::string str){
    int i=0, temp=0;

    while(str[i]){
        temp *= 10;
        temp += str[i++]-48;
    }
    return temp;
}

void search(Agenda agenda){
    int i=0;
    Contact peer;
    std::string temp;

    std::cout << std::endl << "---------------------------------------------" << std::endl;
    std::cout << "|" << std::setw(10) << "index" << "|" << std::setw(10) << "first name" << "|" \
                << std::setw(10) << "last name" << "|" << std::setw(10) << "nickname" << "|" << std::endl\
                << "|==========|==========|==========|==========|" << std::endl;
    while(i<8 && !(peer=agenda.getContact(i)).getFirstName().empty()){
        std::cout << "|" << std::setw(10) << i++;
        if(peer.getFirstName().size() > 10)
            temp = peer.getFirstName().substr(0, 9) + '.';
        else temp = peer.getFirstName();
        std::cout << "|" << std::setw(10) << temp;
        if(peer.getLastName().size() > 10)
            temp = peer.getLastName().substr(0, 9) + '.';
        else temp = peer.getLastName();
        std::cout << "|" << std::setw(10) << temp;
        if(peer.getNickname().size() > 10)
            temp = peer.getNickname().substr(0, 9) + '.';
        else temp = peer.getNickname();
        std::cout << "|" << std::setw(10) << temp << "|" << std::endl;
    }
    std::cout << "---------------------------------------------" << std::endl << std::endl;
    if(!i){
        std::cout << ">- Empty Phonebook ! -<" << std::endl;
        return;
    }
    std::cout << "Enter an index to show the whole details of :" << std::endl << "\t";
    while(1){
        std::getline(std::cin, temp);
        i = toInt(temp);
        if (nonNumPresent(temp) || i>7 || (peer = agenda.getContact(i)).getFirstName().empty())
            std::cout << "Invalid index. Retry" << std::endl << "\t";
        else{
            std::cout << std::endl << "First Name :\t" << peer.getFirstName() << std::endl\
                        << "Last Name :\t" << peer.getLastName() << std::endl << "Nickname :\t"\
                        << peer.getNickname() << std::endl << "Dark Secret:\t" << peer.getDarkSecret()\
                        << std::endl << "Phone Number:\t" << peer.getNumber() << std::endl;
            break;
        }
    }
}

int main(){
    std::string input;
    Agenda agenda;

    std::cout << "Welcome to the Crappy Awesome Phonebook Software !" << std::endl;
    while(1){
        std::cout << std::endl << "Choose a comand to execute : SEARCH, ADD, EXIT" << std::endl << "> ";
        std::getline(std::cin, input);
        if(!input.compare("ADD"))
            agenda.addContact();
        else if(!input.compare("SEARCH"))
            search(agenda);
        else if(!input.compare("EXIT"))
            break;
        else
            std::cout << std::endl << "Invalid comand entered. Retry" << std::endl;
    }
}