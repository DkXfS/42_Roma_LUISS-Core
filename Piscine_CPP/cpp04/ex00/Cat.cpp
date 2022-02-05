#include "Cat.hpp"

Cat::Cat(){
    std::cout << "... A cat is born ..." << std::endl;
    type = "Cat";
}

Cat::Cat(const Cat& og){
    std::cout << "... A cat is cloned ..." << std::endl;
    type = og.type;
}

Cat::~Cat(){
    std::cout << "... A cat is being killed ..." << std::endl;
}

void Cat::makeSound() const{
    std::cout << "MEOW. MEEEOOOWW. MAO." << std::endl;
}

Cat& Cat::operator=(const Cat& og){
    this->Animal::operator=(og);
    return *this;
}