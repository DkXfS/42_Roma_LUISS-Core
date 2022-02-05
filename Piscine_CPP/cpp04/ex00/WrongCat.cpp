#include "WrongCat.hpp"

WrongCat::WrongCat(){
    std::cout << "... A WrongCat is born ..." << std::endl;
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& og){
    std::cout << "... A WrongCat is cloned ..." << std::endl;
    type = og.type;
}

WrongCat::~WrongCat(){
    std::cout << "... A WrongCat is being killed ..." << std::endl;
}

void WrongCat::makeSound() const{
    std::cout << "*wrong* MEOW. MEEEOOOWW. MAO. *wrong*" << std::endl;
}