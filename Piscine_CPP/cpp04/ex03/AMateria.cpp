#include "AMateria.hpp"

AMateria::AMateria(): type("N/A"){
    //std::cout << "__- AMateria default constructor -__" << std::endl;
}

AMateria::~AMateria(){
    //std::cout << "__- AMateria destructor -__" << std::endl;
}

AMateria::AMateria(const AMateria& og): type(og.type){
}

AMateria& AMateria::operator=(const AMateria& og){
    type = og.type;
    return *this;
}

AMateria::AMateria(std::string const &type): type(type){
}

std::string const& AMateria::getType() const{
    return type;
}

void AMateria::use(ICharacter& target){
    std::cout << "*Uses some materia on " << target.getName() << "*" << std::endl;
}