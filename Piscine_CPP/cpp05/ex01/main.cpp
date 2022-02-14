#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
    Bureaucrat b1("Bob", 150);
    Bureaucrat b2("Marge", 1);
    Form form("Promotion", 100, 50);

    std::cout << "----------------------------" << std::endl;
    try{
        Form form2("Bonus Pay", 0, 150);
    } catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }
    try{
        Form form2("Bonus Pay", 1, 151);
    } catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }
    std::cout << "----------------------------" << std::endl;
    std::cout << form <<std::endl;
    std::cout << "----------------------------" << std::endl;

    try{
        b1.signForm(form);
    } catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }
    try{
        b2.signForm(form);
    } catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }

    std::cout << "----------------------------" << std::endl;
    std::cout << form <<std::endl;
    std::cout << "----------------------------" << std::endl;
}