#include "FragTrap.hpp"

FragTrap::FragTrap(){
    std::cout << "The default ClapTrap has become a FragTrap." << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name){
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "ClapTrap " << this->name << " has become a FragTrap." << std::endl;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap " << name << " has been destroyed." << std::endl;
}

FragTrap::FragTrap(FragTrap const & og){
    *this = og;
    std::cout << "FragTrap " << name << " has been duplicated." << std::endl;
}

void FragTrap::highFivesGuys(){
    std::cout << "FragTrap "  << name << " wants to high five everyone. * awkward silence ensues *" << std::endl;
}