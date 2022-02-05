#include "Dog.hpp"
#include "Cat.hpp"

int main(){
    const Dog *j = new Dog();
    const Cat *i = new Cat();
    Animal *mixnimal[10];
    int x=0;
    
    for(; x<5; x++){
        mixnimal[x] = new Dog(*j);
    }
    for(; x<10; x++){
        mixnimal[x] = new Cat(*i);
    }

    std::cout << std::endl << "Printing *brain to prove successful deep copy" << std::endl;
    std::cout << "(Dog) Array[3] : " << &((Dog*)mixnimal[3])->getBrain() << "\t(Dog) *j : " << &j->getBrain() << std::endl;
    std::cout << "(Cat) Array[7] : " << &((Cat*)mixnimal[7])->getBrain() << "\t(Cat) *i : " << &i->getBrain() << std::endl << std::endl;
    delete j; //should not create a leak
    delete i;
    for(x=0; x<10; x++){
        delete mixnimal[x];
    }
}