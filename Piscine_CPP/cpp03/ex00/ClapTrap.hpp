#include<iostream>
#include<string>

class ClapTrap{
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;

    public:
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& a);
    ~ClapTrap();
    void attack(std::string const & target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    ClapTrap& operator=(const ClapTrap& a);
    std::string getName() const;
    int getDamageValue() const;
};