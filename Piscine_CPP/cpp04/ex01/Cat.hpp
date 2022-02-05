#include "Animal.hpp"
#include "Brain.hpp"
#pragma once

class Cat: public Animal{
    Brain *brain;

    public:
    Cat();
    ~Cat();
    Cat(const Cat& og);
    void makeSound() const;
    Cat& operator=(const Cat& og);
    Brain& getBrain() const;
};