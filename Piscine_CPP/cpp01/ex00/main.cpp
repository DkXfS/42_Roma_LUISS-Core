#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main(){
    Zombie *z = newZombie("zambaayy");
    z->announce();
    randomChump("RandyChimp");
    delete z;
}