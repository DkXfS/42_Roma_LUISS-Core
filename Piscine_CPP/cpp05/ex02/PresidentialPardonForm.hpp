#include "Form.hpp"

class PresidentialPardonForm: public Form{
    std::string target;
    PresidentialPardonForm();

    public:
    PresidentialPardonForm(std::string target);
    virtual ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& og);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& og);
    void action()const;
};