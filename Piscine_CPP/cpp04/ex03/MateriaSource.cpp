#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): count(0){
    for(int i=0; i<4; i++){
        materias[i] = NULL;
    }
    std::cout << "__- MateriaSource constructor -__" << std::endl;
}

MateriaSource::~MateriaSource(){
    for(int i=0; i<4; i++){
        if(materias[i])
            delete materias[i];
    }
    std::cout << "__- MateriaSource destructor -__" << std::endl;
}

void MateriaSource::learnMateria(AMateria *mat){
    if(count < 4){
        materias[count++] = mat->clone();
        std::cout << "A source has learnt a materia." << std::endl; 
    }
    else
        std::cout << "A source can't learn more materias." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type){
    for(int i=0; i<4; i++){
        if(materias[i]->getType() == type)
            return materias[i]->clone();
    }
    return NULL;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& og){
    for(int i=0; i<og.count; i++){
        //if(og.materias[i])
            materias[i] = og.materias[i]->clone();
    }
}

MateriaSource::MateriaSource(const MateriaSource& og): count(og.count){
    for(int i=0; i<count; i++){
        materias[i] = og.materias[i]->clone();
    }
}