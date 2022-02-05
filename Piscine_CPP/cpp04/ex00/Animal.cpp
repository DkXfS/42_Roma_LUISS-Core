#include "Animal.hpp"

Animal::Animal(): type("Animal"){
    std::cout << "... An animal is born ..." << std::endl;
}

Animal::Animal(const Animal& og): type(og.type){
    std::cout << "... An animal is cloned ..." << std::endl;
}

Animal::~Animal(){
    std::cout << "... An animal is being killed ..." << std::endl;
}

std::string Animal::getType() const{
    return type;
}

void Animal::makeSound() const{
    std::cout << "*Generic animal noises*" << std::endl;
}

Animal& Animal::operator=(const Animal& og){
    type = og.type;
    return *this;
}