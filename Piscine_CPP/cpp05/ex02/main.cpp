#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){
    Bureaucrat b1("Bob", 150);
    Bureaucrat b2("Marge", 25);
    Bureaucrat b3("Boss", 1);
    Form *form = new ShrubberyCreationForm("Office");
    RobotomyRequestForm form2("Boss");
    PresidentialPardonForm form3("Marge");

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
    try{ b2.gradeDecrement(); }
    catch(std::exception& e) { std::cout << e.what() << std::endl; }
    try{ b1.gradeDecrement(); }
    catch(std::exception& e) { std::cout << e.what() << std::endl; }
    try{ b1.gradeIncrement(); }
    catch(std::exception& e) { std::cout << e.what() << std::endl; }
    std::cout << "----------------------------" << std::endl;
    b2.signForm(form2);
    b2.executeForm(form2);
    std::cout << "----------------------------" << std::endl;
    b2.signForm(form3);
    b3.signForm(form3);
    b3.executeForm(form3);
    std::cout << "----------------------------" << std::endl;
    delete form;
}