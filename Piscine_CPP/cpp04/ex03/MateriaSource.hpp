#include "IMateriaSource.hpp"
#include <iostream>
#pragma once

class MateriaSource: public IMateriaSource{
    AMateria* materias[4];
    int count;

    public:
        MateriaSource();
        ~MateriaSource();
        MateriaSource& operator=(const MateriaSource& og);
        MateriaSource(const MateriaSource& og);
        virtual void learnMateria(AMateria *);
        virtual AMateria* createMateria(std::string const &type);
};