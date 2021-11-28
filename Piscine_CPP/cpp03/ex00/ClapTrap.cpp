#include "ClapTrap.hpp"

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
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << "points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
    std::cout << "ClapTrap " << name << " takes " << amount << " damage." << std::endl;
    hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount){
    std::cout << "ClapTrap " << name << " gets repaired. Gains " << amount << " hitpoints." << std::endl;
    hitPoints += amount;
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