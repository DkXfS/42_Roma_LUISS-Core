#pragma once
#include<string>
#include "Bureaucrat.hpp"

class Form{
    const std::string _name;
    const int _signGrade;
    const int _execGrade;
    bool _signed;
    Form();

    class GradeTooHighException: public std::exception{
        std::string type;
        virtual const char* what() const throw(){
            if(type == "sign")
                return "_! Exception: The Form's sign grade is too high !_";
            if(type == "execution")
                return "_! Exception: The Form's execution grade is too high !_";
            else
                return "_! Exception: The Form's grade is too low !_";
        }

        public:
        GradeTooHighException(std::string type): type(type){}
    };
    class GradeTooLowException: public std::exception{
        std::string type;
        virtual const char* what() const throw(){
            if(type == "sign")
                return "_! Exception: The Form's sign grade is too low !_";
            if(type == "execution")
                return "_! Exception: The Form's execution grade is too low !_";
            else
                return "_! Exception: The Form's grade is too low !_";
        }

        public:
        GradeTooLowException(std::string type): type(type){}
    };

    public:
    ~Form();
    Form(const Form& og);
    Form(std::string name, int signGrade, int execGrade);
    Form& operator=(const Form& fro);
    int getSignGrade()const;
    int getExecGrade()const;
    std::string getName()const;
    bool isSigned()const;
    void beSigned(const Bureaucrat& bro);
};

std::ostream& operator<<(std::ostream& out, const Form& form);