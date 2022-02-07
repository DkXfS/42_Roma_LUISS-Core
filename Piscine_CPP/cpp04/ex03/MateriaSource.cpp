#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): count(0){
    for(int i=0; i<4; i++){
        materias[i] = NULL;
    }
    //std::cout << "__- MateriaSource default constructor -__" << std::endl;
}

MateriaSource::~MateriaSource(){
    clearMaterias();
    //std::cout << "__- MateriaSource destructor -__" << std::endl;
}

void MateriaSource::learnMateria(AMateria *mat){
    if(count < 4){
        materias[count++] = mat;
        //std::cout << "A source has learnt '" << mat->getType() << "' materia." << std::endl; 
    }
    //else
    //    std::cout << "A source can't learn more materias." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type){
    for(int i=0; i<4; i++){
        if(materias[i]->getType() == type)
            return materias[i]->clone();
    }
    return NULL;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& og){
    clearMaterias();
    count = og.count;
    for(int i=0; i<count; i++){
        //if(og.materias[i])
            materias[i] = og.materias[i]->clone();
    }
    return *this;
}

MateriaSource::MateriaSource(const MateriaSource& og): count(og.count){
    for(int i=0; i<count; i++){
        materias[i] = og.materias[i]->clone();
    }
}

void MateriaSource::clearMaterias(){
    for(int i=0; i<count; i++){
        delete materias[i];
    }
}