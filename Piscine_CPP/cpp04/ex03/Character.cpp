#include "Character.hpp"

Character::Character(){

}

Character::Character(std::string name): name(name){

}

Character::~Character(){

}

Character::Character(const Character& og){

}

Character& Character::operator=(const Character& og){

}

void Character::use(int id, ICharacter& target){

}

void Character::unequip(int id){

}

void Character::equip(AMateria *m){

}

std::string const& Character::getName() const{
    return this->name;
}