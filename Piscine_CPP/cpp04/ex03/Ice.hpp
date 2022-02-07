#include "AMateria.hpp"
#pragma once

class Ice: public AMateria{
    public:
        Ice();
        ~Ice();
        Ice(const Ice& og);
        virtual AMateria *clone() const;
        virtual void use(ICharacter &target);
};