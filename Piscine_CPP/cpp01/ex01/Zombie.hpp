#include <string>
#include <iostream>

class Zombie{
    std::string name;

    public:
    Zombie(std::string name);
    Zombie();
    ~Zombie();
    void announce( void );
    void setName(std::string name);
};