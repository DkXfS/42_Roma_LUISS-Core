#include "WrongAnimal.hpp"
#pragma once

class WrongCat: public WrongAnimal{
    public:
    WrongCat();
    ~WrongCat();
    WrongCat(const WrongCat& og);
    void makeSound() const;
};