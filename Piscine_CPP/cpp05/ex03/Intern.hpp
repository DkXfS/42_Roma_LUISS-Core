#pragma once
#include <string>
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"


class Intern{
    public:
    Intern();
    ~Intern();
    Intern& operator=(const Intern& og);
    Intern(const Intern& og);
    Form* makeForm(std::string formName, std::string target);
};