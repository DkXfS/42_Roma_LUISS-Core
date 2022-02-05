#include "Animal.hpp"
#pragma once

class Dog: public Animal{
    public:
    Dog();
    ~Dog();
    Dog(const Dog& og);
    void makeSound() const;
    Dog& operator=(const Dog& og);
};