#pragma once
#include "ICharacter.hpp"

class Character: public ICharacter{
    AMateria* materia[4];
    std::string name;

    public:
        Character();
        Character(std::string name);
        ~Character();
        Character(const Character& og);
        Character& operator=(const Character& og);
        virtual std::string const &getName() const;
        virtual void equip(AMateria *m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter &target);
};