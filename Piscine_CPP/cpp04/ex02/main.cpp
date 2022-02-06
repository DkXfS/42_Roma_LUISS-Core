#include "Dog.hpp"
#include "Cat.hpp"

int main(){
    const Dog *j = new Dog();
    const Cat *i = new Cat();
    //const Animal *k= new Animal();
    //delete k;
    delete j;
    delete i;
}