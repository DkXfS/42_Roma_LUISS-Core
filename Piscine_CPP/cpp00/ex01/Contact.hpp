#pragma once
#include <string>

class Contact
{
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string darkSecret;
    std::string number;

    public :
        //Contact();
        //~Contact();
        std::string getFirstName() const;
        void setFirstName(std::string str);
        std::string getLastName() const;
        void setLastName(std::string str);
        std::string getNickname() const;
        void setNickname(std::string str);
        std::string getDarkSecret() const;
        void setDarkSecret(std::string str);
        std::string getNumber() const;
        void setNumber(std::string str);
};