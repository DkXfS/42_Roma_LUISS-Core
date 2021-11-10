#include "Zombie.hpp"
#define ZOMBI_NUM 10

Zombie* zombieHorde( int N, std::string name );

int main(){
    Zombie *z = zombieHorde(ZOMBI_NUM, "Zambaay");
    for (int i=0; i < ZOMBI_NUM; i++)
        z[i].announce();
    delete [] z;
}