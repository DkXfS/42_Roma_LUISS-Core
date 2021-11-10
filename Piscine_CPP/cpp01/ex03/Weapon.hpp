#include <string>
#pragma once

class Weapon{
    std::string type;

    public:
    Weapon();   ///
    Weapon(std::string);
    std::string const &getType() const;
    void setType(std::string t);
};