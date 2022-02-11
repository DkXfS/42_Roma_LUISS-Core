#include "Form.hpp"

Form::Form(): _name("N/A"), _signGrade(0), _execGrade(0), _signed(false){}

Form::Form(std::string name, int signGrade, int execGrade): _name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(false){

}

Form::Form(const Form& og): _name(og._name), _execGrade(og._execGrade), _signGrade(og.), _signed(){

}

Form::~Form(){

}

