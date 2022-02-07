#include "Character.hpp"

Character::Character(): name("N/A"), count(0){
    for(int i=0; i<4; i++){
        materia[i] = NULL;
    }
    //std::cout << "__- Character default constructor -__" << std::endl;
}

Character::Character(std::string name): name(name), count(0){
    for(int i=0; i<4; i++){
        materia[i] = NULL;
    }
    //std::cout << "__- Character constructor -__" << std::endl;
}

Character::~Character(){
    clearMaterias();
    //std::cout << "__- Character destructor -__" << std::endl;
}

Character::Character(const Character& og): name(og.name), count(og.count){
    for(int i=0; i<count; i++){
        materia[i] = og.materia[i]->clone();
    }
}

Character& Character::operator=(const Character& og){
    clearMaterias();
    count = og.count;
    name = og.name;
    for(int i=0; i<count; i++){
        //if(og.materias[i])
            materia[i] = og.materia[i]->clone();
    }
    return *this;
}

void Character::use(int id, ICharacter& target){
    materia[id]->use(target);
}

void Character::unequip(int id){
    int i;
    if(id > -1 && id < 4){
        for(i=id; i<3; i++)
            materia[i] = materia [i+1];
        materia[i] = NULL;
        count--;
    }
}

void Character::equip(AMateria *m){
    if(count > -1 && count < 4){
        materia[count++] = m;
        //std::cout << name << " has equipped " << materia[count -1]->getType() << " in slot " << count-1 << std::endl;
    }
    //else
    //    std::cout << name << " couldn't equip " << m->getType() << ". Inventory full" << std::endl;
}

std::string const& Character::getName() const{
    return this->name;
}

void Character::clearMaterias(){
    for(int i=0; i<count; i++){
        delete materia[i];
    }
}