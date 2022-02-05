#include "Animal.hpp"
#pragma once

class Cat: public Animal{
    public:
    Cat();
    ~Cat();
    Cat(const Cat& og);
    void makeSound() const;
    Cat& operator=(const Cat& og);
};