#include "DiamondTrap.hpp"

int main(){
    ClapTrap a("Barry");
    ScavTrap b("Scavy");
    FragTrap c("Fragger");
    DiamondTrap d("Daemon");

    a.attack(c.getName());
    c.takeDamage(a.getDamageValue());
    b.beRepaired(5);
    b.guardGate();
    c.highFivesGuys();
    b.attack(c.getName());
    c.takeDamage(b.getDamageValue());
    d.attack(a.getName());
    a.takeDamage(d.getDamageValue());
    d.whoAmI();
}