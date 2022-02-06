#include "Dog.hpp"

Dog::Dog(){
    std::cout << "... A dog is born ..." << std::endl;
    type = "Dog";
    brain = new Brain();
}

Dog::Dog(const Dog& og): Animal(og), brain(new Brain(*og.brain)){
    //brain = og.brain;
    std::cout << "... A dog has been cloned ..." << std::endl;
}

Dog::~Dog(){
    delete brain;
    std::cout << "... A dog has been killed ..." << std::endl;
}

void Dog::makeSound() const{
    std::cout << "BAU, BAU... BAAAUUUUUAAAUUUU... GGRRRHH" << std::endl;
}

Dog& Dog::operator=(const Dog& og){
    Animal::operator=(og);
    *brain = *og.brain;
    return *this;
}

Brain& Dog::getBrain() const{
    return *brain;
}