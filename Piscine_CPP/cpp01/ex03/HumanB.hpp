#include "Weapon.hpp"
#include <string>
#include <iostream>
#pragma once

class HumanB{
    std::string name;
    Weapon* weapon;

    public:
    HumanB(std::string);
    void setWeapon(Weapon&);
    void attack() const;
};