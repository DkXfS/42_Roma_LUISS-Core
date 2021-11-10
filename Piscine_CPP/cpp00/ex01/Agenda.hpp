#pragma once
#include <iostream>
#include "Contact.hpp"

class Agenda
{
    Contact contacts[8];

    public:
        //Agenda();
        //~Agenda();
        void    addContact();
        Contact getContact(int i) const;
};