#include "Weapon.hpp"

std::string const &Weapon::getType() const{
    return this->type;
}

void Weapon::setType(std::string t){
    this->type = t;
}

Weapon::Weapon(std::string t): type(t){}

Weapon::Weapon(){}