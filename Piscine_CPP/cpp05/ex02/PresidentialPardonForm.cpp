#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("PresidentialPardonForm", 25, 5){}

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("PresidentialPardonForm", 25, 5), target(target){
    std::cout << "_- A PresidentialPardonForm has been created -_" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "_- PresidentialPardonForm Destructor -_" << std::endl;    
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& og): Form(og), target(og.target){
    std::cout << "A PresidentialPardonForm has been cloned" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& og){
    target = og.target;
    return *this;
}

void PresidentialPardonForm::action()const{
    std::cout << target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}