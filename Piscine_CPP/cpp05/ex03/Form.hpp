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
                return "!! Exception: The Form's sign grade is too high !!";
            if(type == "execution")
                return "!! Exception: The Form's execution grade is too high !!";
            else
                return "!! Exception: The Form's grade is too low !!";
        }

        public:
        GradeTooHighException(std::string type): type(type){}
        ~GradeTooHighException() _NOEXCEPT{}
    };
    class GradeTooLowException: public std::exception{
        std::string type;
        virtual const char* what() const throw(){
            if(type == "sign")
                return "!! Exception: The Form's sign grade is too low !!";
            if(type == "execution")
                return "!! Exception: The Form's execution grade is too low !!";
            else
                return "!! Exception: The Form's grade is too low !!";
        }

        public:
        GradeTooLowException(std::string type): type(type){}
        ~GradeTooLowException() _NOEXCEPT{}
    };
    class NotSignedException: public std::exception{
        virtual const char* what() const throw(){
            return "!! Exception: Form not signed !!";
        }
    };
    class CantExecuteException: public std::exception{
        virtual const char* what()const throw(){
            return "!! Exception: Bureaucrat's grade not high enough to execute form !!";
        } 
    };
    class CantSignException: public std::exception{
        virtual const char* what()const throw(){
            return "!! Exception: Bureaucrat's grade not high enough to sign form !!";
        } 
    };

    public:
    virtual ~Form();
    Form(const Form& og);
    Form(std::string name, int signGrade, int execGrade);
    Form& operator=(const Form& fro);
    int getSignGrade()const;
    int getExecGrade()const;
    std::string getName()const;
    bool isSigned()const;
    void beSigned(const Bureaucrat& bro);
    void execute(Bureaucrat const& executor) const;
    virtual void action() const = 0;
};

std::ostream& operator<<(std::ostream& out, const Form& form);