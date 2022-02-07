#include <string>
#include "ICharacter.hpp"
#include <iostream>
#pragma once

class AMateria{
    protected:
        std::string type;

    public:
        AMateria(std::string const &type);
        AMateria();
        virtual ~AMateria();
        AMateria& operator=(const AMateria& og);
        AMateria(const AMateria& og);
        std::string const &getType() const; // Returns the materia type
        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);
};