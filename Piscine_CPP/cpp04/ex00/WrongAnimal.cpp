#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("WrongAnimal"){
    std::cout << "... A WrongAnimal is born ..." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& og): type(og.type){
    std::cout << "... A WrongAnimal is cloned ..." << std::endl;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "... A WrongAnimal is being killed ..." << std::endl;
}

std::string WrongAnimal::getType() const{
    return type;
}

void WrongAnimal::makeSound() const{
    std::cout << "*Wrong generic animal noises*" << std::endl;
}