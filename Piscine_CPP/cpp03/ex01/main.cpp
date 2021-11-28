#include "ClapTrap.hpp"

int main(){
    ClapTrap a("Barry"), b(a);

    a.attack(b.getName());
    b.takeDamage(a.getDamageValue());
    b.beRepaired(5);
}