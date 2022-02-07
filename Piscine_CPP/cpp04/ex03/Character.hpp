#pragma once
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

class Character: public ICharacter{
    AMateria* materia[4];
    std::string name;
    int count;
    void clearMaterias();

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