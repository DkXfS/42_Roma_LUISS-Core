#include "Weapon.hpp"
#include <string>
#include <iostream>
#pragma once

class HumanA{
    std::string name;
    Weapon& weapon;

    public:
    HumanA(std::string, Weapon&);
    void attack() const;
};