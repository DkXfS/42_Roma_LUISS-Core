#include "Brain.hpp"

Brain::Brain(){
    for(int i=0; i<100; i++){
        ideas[i] = "!dea";
    }
    std::cout << "_- A Brain has been created -_" << std::endl;
}

Brain::Brain(const Brain& og){
    *this = og;
    std::cout << "_- A Brain has been cloned -_" << std::endl;
}

Brain::~Brain(){
    std::cout << "_- A Brain has been destroyed -_" << std::endl;
}

Brain& Brain::operator=(const Brain& b){
    for(int i=0; i<100; i++){
        ideas[i] = b.ideas[i];
    }
    return *this;
    std::cout << "_- Brain: = operator -_" << std::endl;
}