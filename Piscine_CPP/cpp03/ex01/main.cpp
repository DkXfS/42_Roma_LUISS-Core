#include "ScavTrap.hpp"
//#include

int main(){
    ClapTrap a("Barry");
    ScavTrap b("Scavy");

    a.attack(b.getName());
    b.takeDamage(a.getDamageValue());
    b.beRepaired(5);
    b.guardGate();
    b.attack(a.getName());
    a.takeDamage(b.getDamageValue());
}