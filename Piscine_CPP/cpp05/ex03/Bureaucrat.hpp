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
    void executeForm(Form const & form);

    class GradeTooHighException: public std::exception{
        virtual const char* what() const throw(){
            return "!! Exception: The Bureaucrat's grade is too high !!";
        }
    };
    class GradeTooLowException: public std::exception{
        virtual const char* what() const throw(){
            return "!! Exception: The Bureaucrat's grade is too low !!";
        }
    };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bro);