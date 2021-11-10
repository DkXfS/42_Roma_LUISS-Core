#include "Zombie.hpp"

std::string toStr(int i, int first=1){
    if(i==0 && first)
        return "0";
    if(i==0 && !first)
        return "";
    else{
        char c = '0'+(i%10);
        return (toStr(i/10, 0) + std::string(&c,1));
    }
}

Zombie* zombieHorde( int N, std::string name ){
    Zombie* z = new Zombie[N];
    for (int i=0; i < N; i++)
        z[i].setName(name+"_"+toStr(i+1));
    return z;
}