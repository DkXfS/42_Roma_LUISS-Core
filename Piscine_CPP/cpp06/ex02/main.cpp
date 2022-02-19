#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <time.h>
#include <stdlib.h>

Base* generate(void){
    int i = rand() % 3;

    if(i == 0){
        std::cout << "creating class A" << std::endl;
        return new A;
    }
    if(i == 1){
        std::cout << "creating class C" << std::endl;
        return new C;
    }
    else{
        std::cout << "creating class B" << std::endl;
        return new B;
    }
}

void identify(Base* p){
    std::cout << "Sub-class identified through pointer: ";
    if(dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if(dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else std::cout << "! Dynamic cast on pointer failed !" << std::endl;
}

void identify(Base& p){
    Base tmp;
    int i=1;
    std::cout << "Sub-class identified through reference: ";
    try{
        tmp = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    } catch(std::exception &e){ i++; }
    try{
        tmp = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    } catch(std::exception &e){ i++; }
    try{
        tmp = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    } catch(std::exception &e){ i++; }
    if(i>3)
        std::cout << "! Dynamic cast on reference failed !" << std::endl;
}

int main(){
    srand(time(NULL));
    Base* ptr;

    for(int i=0; i<9; i++){
        std::cout << std::endl;
        ptr = generate();
        identify(ptr);
        identify(*ptr);
        delete ptr;
    }
}