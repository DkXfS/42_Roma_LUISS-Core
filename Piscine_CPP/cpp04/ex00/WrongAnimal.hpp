#include<iostream>
#include<string>
#pragma once

class WrongAnimal{

    protected:
    std::string type;

    public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& og);
    virtual ~WrongAnimal();
    std::string getType() const;
    void makeSound() const;
};