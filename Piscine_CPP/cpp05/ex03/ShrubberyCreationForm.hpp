#pragma once
#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm: public Form{
    std::string target;
    ShrubberyCreationForm();

    public:
    ShrubberyCreationForm(std::string target);
    virtual ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& og);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& og);
    void action()const;
};