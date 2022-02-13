#pragma once
#include <string>
#include <iostream>

class Form;

class Bureaucrat{
    const std::string name;
    int grade;
    Bureaucrat();

    public:
    ~Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& og);
    Bureaucrat& operator=(const Bureaucrat& og);
    std::string getName() const;
    int getGrade() const;
    void gradeIncrement();
    void gradeDecrement();
    void signForm(Form& fro);

    class GradeTooHighException: public std::exception{
        virtual const char* what() const throw(){
            return "_! Exception: The Bureaucrat's grade is too high !_";
        }
    };
    class GradeTooLowException: public std::exception{
        virtual const char* what() const throw(){
            return "_! Exception: The Bureaucrat's grade is too low !_";
        }
    };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bro);