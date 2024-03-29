#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("null"), hitPoints(0), energyPoints(0), attackDamage(0)
{
    std::cout << "A default ClapTrap has been constructed. It has null properties." << std::endl;
}

ClapTrap::ClapTrap(std::string name): name(name), hitPoints(10), energyPoints(10), attackDamage(0){
    std::cout << "A ClapTrap named " << this->name << " has been constructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& a): name(a.name), hitPoints(a.hitPoints), energyPoints(a.energyPoints), attackDamage(a.attackDamage){
    std::cout << "ClapTrap named " << this->name << " got duplicated" << std::endl;
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap " << name << " destroyed" << std::endl;
}

void ClapTrap::attack(std::string const & target){
    if(energyPoints > 1){
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
        std::cout << "It loses an energy point. It now has " << energyPoints << " energy points." << std::endl;
    }
    else
        std::cout << "Claptrap " << name << " wants to attack but it has 0 energypoints." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
    hitPoints -= amount;
    if(hitPoints < 0)
        hitPoints = 0;
    std::cout << "ClapTrap " << name << " takes " << amount << " damage. Now has " << hitPoints << " hitpoints."<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
    std::cout << "ClapTrap " << name << " gets repaired. Gains " << amount << " hitpoints. ";
    hitPoints += amount;
    std::cout << "It now has " << hitPoints << " hitpoints total."<< std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& a){
    this->name = a.name;
    this->hitPoints = a.hitPoints;
    this->attackDamage = a.attackDamage;
    this->energyPoints = a.energyPoints;
    return *this;
}

std::string ClapTrap::getName() const{
    return name;
}

int ClapTrap::getDamageValue() const{
    return attackDamage;
}