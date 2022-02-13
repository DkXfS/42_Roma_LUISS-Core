#include "Form.hpp"

Form::Form(): _name("N/A"), _signGrade(0), _execGrade(0), _signed(false){}

Form::Form(std::string name, int signGrade, int execGrade): _name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(false){
    if(_signGrade > 150)
        throw GradeTooLowException("sign");
    if(_signGrade < 1)
        throw GradeTooHighException("sign");
    if(_execGrade > 150)
        throw GradeTooLowException("execution");
    if(_execGrade < 1)
        throw GradeTooHighException("execution");
}

Form::Form(const Form& og): _name(og._name), _signGrade(og._signGrade), _execGrade(og._execGrade), _signed(og._signed){}

Form::~Form(){}

Form& Form::operator=(const Form& og){
    _signed = og._signed;
    return *this;
}

bool Form::isSigned()const{
    return _signed;
}

int Form::getExecGrade()const{
    return _execGrade;
}

int Form::getSignGrade()const{
    return _signGrade;
}

std::string Form::getName()const{
    return _name;
}

void Form::beSigned(const Bureaucrat& bro){
    if(bro.getGrade() > _signGrade)
        throw GradeTooLowException("sign");
    _signed = true;
}

std::ostream& operator<<(std::ostream& out, const Form& og){
    out << "Form name: " + og.getName() + ", form's sign grade: " << og.getSignGrade() << ", form's execution grade: " << og.getExecGrade() << ", form signed: ";
    if(og.isSigned())
        out << "yes";
    else out << "no";
    return out;
}