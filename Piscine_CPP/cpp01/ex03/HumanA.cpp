#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& w): name(name), weapon(w){}

void HumanA::attack() const{
    std::cout << this->name << " attacks with his " << this->weapon.getType() << std::endl;
};
