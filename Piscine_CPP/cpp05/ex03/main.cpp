#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(){
    Bureaucrat b1("Bob", 150);
    Bureaucrat b2("Marge", 25);
    Bureaucrat b3("Boss", 1);
    Intern slave;
    Form *form = slave.makeForm("shrubbery creation", "Office");
    Form *form2 = slave.makeForm("robotomy request", "Boss");
    Form *form3 = slave.makeForm("presidential pardon", "Marge");
    Form *form4 = slave.makeForm("Somewhere", "Nowhere");
    std::cout << "----------------------------" << std::endl;
    std::cout << "value of *form4 (Somewhere) = " << form4 << std::endl;
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
    b2.signForm(*form2);
    b2.executeForm(*form2);
    std::cout << "----------------------------" << std::endl;
    b2.signForm(*form3);
    b3.signForm(*form3);
    b3.executeForm(*form3);
    std::cout << "----------------------------" << std::endl;
    delete form;
    delete form2;
    delete form3;
    delete form4;
}