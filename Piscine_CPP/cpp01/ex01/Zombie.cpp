#include "Zombie.hpp"

void Zombie::announce(){
        std::cout << "<" << this->name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name): name(name){}

Zombie::Zombie(): name("n/a"){}

Zombie::~Zombie(){
    std::cout << "Zombie '" << this->name << "' killed." << std::endl;
}

void Zombie::setName(std::string name){
    this->name = name;
}