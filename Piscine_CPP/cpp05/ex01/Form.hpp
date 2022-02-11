#include<string>
#include "Bureaucrat.hpp"

class Form{
    const std::string _name;
    bool _signed;
    const int _signGrade;
    const int _execGrade;

    Form();

    class GradeTooHighException: public std::exception{
        virtual const char* what() const throw(){
            return "_! Exception: The Form's grade is too high !_";
        }
    };
    class GradeTooLowException: public std::exception{
        virtual const char* what() const throw(){
            return "_! Exception: The Form's grade is too low !_";
        }
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

std::ostream operator<<(std::ostream out, const Form& form);