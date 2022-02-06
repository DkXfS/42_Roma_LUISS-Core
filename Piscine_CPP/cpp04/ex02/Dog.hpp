#include "Animal.hpp"
#include "Brain.hpp"
#pragma once

class Dog: public Animal{
    Brain *brain;

    public:
    Dog();
    ~Dog();
    Dog(const Dog& og);
    void makeSound() const;
    Dog& operator=(const Dog& og);
    Brain& getBrain() const;
};