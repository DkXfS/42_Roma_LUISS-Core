#include "Bureaucrat.hpp"

int main(){
    Bureaucrat b1("Bob", 150);
    Bureaucrat b2(b1);
    Bureaucrat b3("Marge", 1);
    try{
        std::cout << "Trying to create a God" << std::endl;
        Bureaucrat b4("God", -1);
    }
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }
    try{
        std::cout << "Trying to create a loser" << std::endl;
        Bureaucrat b4("Loser", 151);
    }
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }

    try{
        b1.gradeDecrement();
    }
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }
    try{
        b3.gradeIncrement();
    }
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }
    try{
        std::cout << "incrementing cloned Bob's grade" << std::endl;
        b2.gradeIncrement();
    }
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }

    std::cout << "b1 info :" << std::endl << "\t" << b1;
    std::cout << "b2 info :" << std::endl << "\t" << b2;
    std::cout << "b3 info :" << std::endl << "\t" << b3;
}