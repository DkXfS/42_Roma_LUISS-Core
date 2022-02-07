#include "AMateria.hpp"
#pragma once

class Cure: public AMateria{
    public:
        Cure();
        ~Cure();
        Cure(const Cure& og);
        virtual AMateria *clone() const;
        virtual void use(ICharacter &target);
};