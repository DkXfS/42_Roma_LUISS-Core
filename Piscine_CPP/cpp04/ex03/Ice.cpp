#include "Ice.hpp"

Ice::Ice(): AMateria("ice"){
    //std::cout << "__- Ice default constructor -__" << std::endl;
}

Ice::~Ice(){
    //std::cout << "__- Ice destructor -__" << std::endl;
}

Ice::Ice(const Ice& og): AMateria(og.type){
}

AMateria* Ice::clone() const{
    return new Ice(*this);
}

void Ice::use(ICharacter& target){
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}