#include "Cat.hpp"

Cat::Cat(){
    std::cout << "... A cat is born ..." << std::endl;
    type = "Cat";
    brain = new Brain();
}

Cat::Cat(const Cat& og): Animal(og), brain(new Brain(*og.brain)){
    //brain = og.brain;
    std::cout << "... A cat has been cloned ..." << std::endl;
}

Cat::~Cat(){
    delete brain;
    std::cout << "... A cat has been killed ..." << std::endl;
}

void Cat::makeSound() const{
    std::cout << "MEOW. MEEEOOOWW. MAO." << std::endl;
}

Cat& Cat::operator=(const Cat& og){
    this->Animal::operator=(og);
    *brain = *og.brain;
    return *this;
}

Brain& Cat::getBrain() const{
    return *brain;
}