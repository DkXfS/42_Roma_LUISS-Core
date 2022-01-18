#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(){
    ClapTrap a("Barry");
    ScavTrap b("Scavy");
    FragTrap c("Fragger");

    a.attack(c.getName());
    c.takeDamage(a.getDamageValue());
    b.beRepaired(5);
    b.guardGate();
    c.highFivesGuys();
    b.attack(c.getName());
    c.takeDamage(b.getDamageValue());
}