#pragma once

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap{
    public:
    FragTrap();
    FragTrap(std::string name);
    ~FragTrap();
    FragTrap(FragTrap const & og);

    void highFivesGuys();
};