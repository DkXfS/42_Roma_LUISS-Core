//#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(){
    Bureaucrat b1("Bob", 150);
    Bureaucrat b2("Marge", 1);
    Form *form = new ShrubberyCreationForm("Home");
    //ShrubberyCreationForm form("Home");

    std::cout << "----------------------------" << std::endl;
    b1.executeForm(*form);
    b2.executeForm(*form);
    std::cout << "----------------------------" << std::endl;
    std::cout << *form <<std::endl;
    std::cout << "----------------------------" << std::endl;
    b1.signForm(*form);
    b2.signForm(*form);
    std::cout << "----------------------------" << std::endl;
    std::cout << *form <<std::endl;
    std::cout << "----------------------------" << std::endl;
    b1.executeForm(*form);
    b2.executeForm(*form);
    std::cout << "----------------------------" << std::endl;
    delete form;

    // TODO
}