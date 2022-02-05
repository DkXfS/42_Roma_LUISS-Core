#include "Dog.hpp"

Dog::Dog(){
    std::cout << "... A dog is born ..." << std::endl;
    type = "Dog";
}

Dog::Dog(const Dog& og){
    std::cout << "... A dog is cloned ..." << std::endl;
    type = og.type;
}

Dog::~Dog(){
    std::cout << "... A dog is being killed ..." << std::endl;
}

void Dog::makeSound() const{
    std::cout << "BAU, BAU... BAAAUUUUUAAAUUUU... GGRRRHH" << std::endl;
}

Dog& Dog::operator=(const Dog& og){
    Animal::operator=(og);
    return *this;
}