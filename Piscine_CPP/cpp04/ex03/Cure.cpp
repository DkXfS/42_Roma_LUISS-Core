#include "Cure.hpp"

Cure::Cure(): AMateria("cure"){
    //std::cout << "__- Cure default constructor -__" << std::endl;
}

Cure::~Cure(){
    //std::cout << "__- Cure destructor -__" << std::endl;
}

Cure::Cure(const Cure& og): AMateria(og.type){
}

AMateria* Cure::clone() const{
    return new Cure(*this);
}

void Cure::use(ICharacter& target){
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}