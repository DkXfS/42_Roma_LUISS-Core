#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
    name = "null";
    hitPoints = 0;
    energyPoints = 0;
    attackDamage = 0;
    std::cout << "A default ScavTrap has been constructed. It has null properties." << std::endl;
}

ScavTrap::ScavTrap(std::string name){
    this->name = name;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "A ScavTrap named " << this->name << " has been constructed from the default ClapTrap" << std::endl;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap " << name << " destroyed" << std::endl;
}

void ScavTrap::attack(std::string const & target){
    if(energyPoints > 1){
        std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
        std::cout << "\tIt loses an energy point. It now has " << energyPoints << " energy points." << std::endl;
    }
    else
        std::cout << "Scavtrap " << name << " wants to attack but it has 0 energypoints." << std::endl;
}

void ScavTrap::guardGate(){
    std::cout << "ScavTrap " << name << " has entered Gate-keeper mode." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& from){
    *this = from;
    std::cout << "ScavTrap " << name << " has been duplicated." << std::endl;
}