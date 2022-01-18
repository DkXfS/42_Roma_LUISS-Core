#pragma once

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap{

    public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap& from);
    ~ScavTrap();
    void attack(std::string const & target);
    void guardGate();
};