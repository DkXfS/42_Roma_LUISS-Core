#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name+"_clap_name"), FragTrap(name+"_frag_name"), ScavTrap(name+"_clap_name"), name(name){
    //ClapTrap::name = name+"_clap_name";
    this->hitPoints = FragTrap::hitPoints;
    this->attackDamage = FragTrap::attackDamage;
    this->energyPoints = ScavTrap::energyPoints;
    std::cout << "DiamondTrap " << this->name << " has been created." << std::endl;
}

DiamondTrap::DiamondTrap(): FragTrap(), ScavTrap(), name("null"){
    ClapTrap::name = name+"_clap_name";
    this->hitPoints = FragTrap::hitPoints;
    this->attackDamage = FragTrap::attackDamage;
    this->energyPoints = ScavTrap::energyPoints;
    std::cout << "Default DiamondTrap constructor called" << std::endl;
}

void DiamondTrap::attack(std::string const & target){
    ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& og): ClapTrap(og.name+"_clap_name"){
    std::cout << "Diamond Trap copy constructor called" << std::endl;
    *this = og;
}

void DiamondTrap::whoAmI(){
    std::cout << "DiamondTrap name: " << this->name << "\tClapTrap name: " << ClapTrap::name << std::endl;
    std::cout << "\twHo aM i ?" << std::endl;
}