#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): Form("RobotomyRequestForm", 72, 45){}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target): Form("RobotomyRequestForm", 72, 45), target(target){
    std::cout << "_- A RobotomyRequestForm has been created -_" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "_- RobotomyRequestForm Destructor -_" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& og): Form(og), target(og.target){
    std::cout << "A RobotomyRequestForm has been cloned" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& og){
    target = og.target;
    return *this;
}

void RobotomyRequestForm::action()const{
    std::cout << "*some drilling noises*" << std::endl;
    srand(time(NULL));
    if(rand() % 2)
        std::cout << target << " has been robotomized successfully" << std::endl;
    else 
        std::cout << "Error: Robotomization of " << target << " failed unexpectedly" << std::endl;
}
