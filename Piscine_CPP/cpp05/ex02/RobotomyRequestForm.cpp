#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): Form("RobotomyRequestForm", 72, 45){}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target): Form("RobotomyRequestForm", 72, 45), target(target){
    std::cout << "A RobotomyRequestForm has been created" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "RobotomyRequestForm Destructor" << std::endl;
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
    // TODO
}
