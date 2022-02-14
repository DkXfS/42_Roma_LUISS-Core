#include "Form.hpp"

class RobotomyRequestForm: public Form{
    std::string target;
    RobotomyRequestForm();

    public:
    RobotomyRequestForm(std::string const& target);
    virtual ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& og);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& og);
    void action()const;
};