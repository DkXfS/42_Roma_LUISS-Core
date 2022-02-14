#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): Form("ShrubberyCreationForm", 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("ShrubberyCreationForm", 145, 137), target(target){
    std::cout << "A ShrubberyCreationForm has been created" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "SHRUBBERY DESTRUCTOR" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& og): Form(og), target(og.target){
    std::cout << "A ShrubberyCreationForm has been cloned" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& og){
    target = og.target;
    return *this;
}

void ShrubberyCreationForm::action()const{
    std::ofstream file;
    file.open(target + "_shrubbery", std::ios::trunc);
    if(file.is_open()){
        file << "   _____        _____" << std::endl;
        file << "  (     )      (     )" << std::endl;
        file << " (       )    (       )" << std::endl;
        file << "(         )  (         )" << std::endl;
        file << " ( \\\\ // )    ( \\\\ // )" << std::endl;
        file << "  --| |--      --| |--" << std::endl;
        file << "    | |          | |" << std::endl;
        file << "____| |__________| |____" << std::endl;
        file.close();
        std::cout << "ShrubberyCreationForm executed." << std::endl;
    }
    else std::cout << "Couldn't execute ShrubberyCreationForm. File open error" << std::endl;
}