#include "Intern.hpp"

Intern::Intern(){
    std::cout << "_- Intern constructed -_" << std::endl;
}

Intern::~Intern(){
    std::cout << "_- Intern destructed -_" << std::endl;
}

Intern::Intern(const Intern& og){
    (void)og;
    std::cout << "_- Intern cloned -_" << std::endl;
}

Intern& Intern::operator=(const Intern& og){
    (void)og;
    std::cout << "All interns are equal. All interns are replaceable" << std::endl;
    return *this;
}

Form* Intern::makeForm(std::string formName, std::string target){
    std::string formNames[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
    int i=0;
    for(; i < 3; i++){
        if(formName == formNames[i]){
            std::cout << "Intern creates a " << formName << " form"<< std::endl;
            break;
        }
    }
    switch(i){
        case 0: return new RobotomyRequestForm(target);
        case 1: return new PresidentialPardonForm(target);
        case 2: return new ShrubberyCreationForm(target);
        default: std::cout << "Error: Intern couldn't create the requested form. Entered form name is invalid" << std::endl;
                 return NULL;
    }
}