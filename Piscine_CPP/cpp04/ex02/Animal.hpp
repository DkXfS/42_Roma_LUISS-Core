#include<iostream>
#include<string>
#pragma once

class Animal{
    protected:
    std::string type;

    public:
    Animal();
    Animal(const Animal& og);
    virtual ~Animal();
    std::string getType() const;
    virtual void makeSound() const = 0;
    Animal& operator=(const Animal& og);
};