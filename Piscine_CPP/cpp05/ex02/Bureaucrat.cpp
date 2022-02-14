#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(): name("N/A"), grade(150){
    std::cout << "_- Bureaucrat Default Constructor -_" << std::endl;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "_- Bureaucrat Destructor -_" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name), grade(grade){
    if(this->grade > 150)
        throw GradeTooLowException();
    if(this->grade < 1)
        throw GradeTooHighException();
    std::cout << "Bureaucrat " << name << " joins the fold with grade " << grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& og): name(og.getName()), grade(og.getGrade()){
    std::cout << "Bureaucrat " << name << " gets cloned" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& og){
    grade = og.getGrade();
    std::cout << name << " copies the grade of " << og.name << ". It's grade is now " << grade << std::endl;
    return *this;
}

std::string Bureaucrat::getName() const{
    return name;
}

int Bureaucrat::getGrade() const{
    return grade;
}

void Bureaucrat::gradeDecrement(){
    std::cout << name << " is losing a grade." << std::endl;
    if(grade > 149)
        throw GradeTooLowException();
    grade++;
    std::cout << name << "'s new grade is " << grade << std::endl;
}

void Bureaucrat::gradeIncrement(){
    std::cout << name << " is getting a grade." << std::endl;
    if(grade < 2)
        throw GradeTooHighException();
    grade--;
    std::cout << name << "'s new grade is " << grade << std::endl;
}

void Bureaucrat::signForm(Form& fro){
    try{
        fro.beSigned(*this);
        std::cout << name << " signs " << fro.getName() << std::endl;
    } catch(std::exception& e){
        std::cout << name << " cannot sign " << fro.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bro){
    out << bro.getName() << ", bureaucrat grade " << bro.getGrade() << std::endl;
    return out;
}

void Bureaucrat::executeForm(Form const & form){
    try{
        form.execute(*this);
        std::cout << name << " executes " << form.getName() << std::endl;
    } catch(std::exception& e){
        std::cout << name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}