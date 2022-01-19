#include "Zombie.hpp"

void Zombie::announce(){
        std::cout << "<" << this->name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(){}

Zombie::Zombie(std::string name): name(name){} 

Zombie::~Zombie(){
    std::cout << "Zombie '" << this->name << "' killed." << std::endl;
}